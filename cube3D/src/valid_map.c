/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:03:43 by calberti          #+#    #+#             */
/*   Updated: 2025/03/17 21:56:41 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int validate_map(t_config *config)
{
    // Normaliser la carte (rendre toutes les lignes de même longueur)
    if (!normalize_map(config))
		return (0);
    // Vérifier qu'il y a exactement un joueur
    if (!find_player_position(config))
        return (0);
    
    // Vérifier que la carte est fermée
    if (!check_map_borders(config))
        return (0);
    
    return (1);
}

int normalize_map(t_config *config)
{
    int i, j;
    char **normalized;
    
    // Calculer la largeur maximale après suppression des indentations
    int max_width = 0;
    for (i = 0; i < config->map.height; i++)
    {
        char *trimmed = trim_left(config->map.grid[i]);
        int len = ft_strlen(trimmed);
        if (len > max_width)
            max_width = len;
    }
    config->map.width = max_width;

    // Allouer la nouvelle grille
    normalized = malloc(sizeof(char *) * config->map.height);
    if (!normalized)
        return (0);

    for (i = 0; i < config->map.height; i++)
    {
        char *trimmed = trim_left(config->map.grid[i]);  // Supprime les espaces de gauche
        int len = ft_strlen(trimmed);
        normalized[i] = malloc(max_width + 1);
        if (!normalized[i])
        {
            for (j = 0; j < i; j++)
                free(normalized[j]);
            free(normalized);
            return (0);
        }

        // Copier la ligne sans indentation
        j = 0;
        while (j < len)
        {
            normalized[i][j] = trimmed[j];
            j++;
        }

        // Compléter avec des espaces à droite
        while (j < max_width)
            normalized[i][j++] = ' ';

        normalized[i][j] = '\0';
    }

    // Libérer l'ancienne grille
    for (i = 0; i < config->map.height; i++)
        free(config->map.grid[i]);
    free(config->map.grid);

    // Remplacer par la nouvelle grille
    config->map.grid = normalized;

    // Vérification DEBUG
    printf("\n--- NORMALIZED MAP (FIXED) ---\n");
    for (i = 0; i < config->map.height; i++)
        printf("%s\n", config->map.grid[i]);

    return (1);
}

int find_player_position(t_config *config)
{
    int i, j;
    int player_count = 0;
    
    for (i = 0; i < config->map.height; i++)
    {
        for (j = 0; j < config->map.width; j++)
        {
            char c = config->map.grid[i][j];
            if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
            {
                // Si on a déjà trouvé un joueur, c'est une erreur
                if (player_count > 0)
                {
                    printf("Error\nMultiple player positions found\n");
                    return (0);
                }
                
                // Enregistrer la position et l'orientation du joueur
                config->map.player_x = j;
                config->map.player_y = i;
                config->map.player_dir = c;
                player_count++;
            }
        }
    }
    
    // Vérifier qu'on a trouvé un joueur
    if (player_count == 0)
    {
        printf("Error\nNo player position found\n");
        return (0);
    }
    
    return (1);
}

int check_map_borders(t_config *config)
{
    char **copy = malloc(sizeof(char *) * config->map.height);
    if (copy == NULL)
        return (0);
    
    for (int i = 0; i < config->map.height; i++)
    {
        copy[i] = ft_strdup(config->map.grid[i]);
        if (copy[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(copy[j]);
            free(copy);
            return (0);
        }
    }

    // Marquer les espaces extérieurs pour ne pas les considérer comme erreur
    mark_outer_spaces(copy, config->map.height, config->map.width);

    if (!flood_fill(copy, config->map.player_x, config->map.player_y, 
			config->map.height, config->map.width))
    {
        for (int i = 0; i < config->map.height; i++)
            free(copy[i]);
        free(copy);
        printf("Error\nMap is not properly closed\n");
        return (0);
    }
    
    for (int i = 0; i < config->map.height; i++)
        free(copy[i]);
    free(copy);
    
    return (1);
}

int flood_fill(char **map, int x, int y, int height, int width)
{
    if (x < 0 || y < 0 || x >= width || y >= height)
        return (0); // Sortie de carte = erreur

    if (map[y][x] == 'O') // Espace extérieur, on l'ignore
        return (1);

    if (map[y][x] == ' ') // Si c'est un espace non marqué = erreur
        return (0);

    if (map[y][x] == 'V' || map[y][x] == '1') // Déjà visité ou mur
        return (1);

    map[y][x] = 'V'; // Marquer comme visité

    if (!flood_fill(map, x + 1, y, height, width))
        return (0);
    if (!flood_fill(map, x - 1, y, height, width))
        return (0);
    if (!flood_fill(map, x, y + 1, height, width))
        return (0);
    if (!flood_fill(map, x, y - 1, height, width))
        return (0);

    return (1);
}