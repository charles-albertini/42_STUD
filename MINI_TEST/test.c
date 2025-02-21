while (1)
            {
                ft_putstr_fd("> ", 1);
                line = get_next_line(STDIN_FILENO);
                if (!line)
                    break;
                if (ft_strncmp(line, redirs[i]->file, ft_strlen(redirs[i]->file)) == 0 &&
                    line[ft_strlen(redirs[i]->file)] == '\n')
                {
                    free(line);
                    break;
                }
                ft_putstr_fd(line, fd);
                free(line);
            }
            close(fd);