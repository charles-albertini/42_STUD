/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:20:22 by calberti          #+#    #+#             */
/*   Updated: 2025/04/10 14:37:07 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

/*
PARSING
1: verifier nombre arg
2: verifier que s1 et s2 ne sont pas NULL
3: verifier que le ficheir existe et qu'on peut l'ouvrir

EXEC
1: ouvrir fichier
2: creer fichier .replace 
3: lire ligne par ligne
4: si on trouve s1 on remplace par s2
5: ecrir au fur et a mesure dans fichier.replace
*/

void	getNewLine(std::string &line, std::string s1, std::string s2) 
{
	size_t	startPos = 0;

	while ((startPos = line.find(s1, startPos)) != std::string::npos)
	{
		line = line.substr(0, startPos) + s2 + line.substr(startPos + s1.length());
		startPos += s2.length();
	}
}


int main(int argc, char **argv)
{
	if (argc != 4)
		return(std::cout << "Error: Need 3 args" << std::endl, 1);
	if ((std::string (argv[2])).length() == 0 || (std::string (argv[3])).length() == 0)
		return(std::cout<< "Error: s1 or s2 is empty" << std::endl, 1);

	std::ifstream file(argv[1]);
	if (!file.is_open())
		return(std::cout<< "Error: file" << std::endl, 1);

	std::string line; //ligne recuperer
	std::ofstream output_file((std::string(argv[1]) + ".replace").c_str()); // on creer le fichier (.c_str() c'est pour lui dire que c'est une string qui vient de c++)
	while(std::getline(file, line))
	{
		getNewLine(line, argv[2], argv[3]);
		output_file << line + "\n";
	}

	

	file.close();
	output_file.close();
    return 0;
	
}