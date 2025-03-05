#include <stdlib.h> //malloc
#include <unistd.h> //read
#include <stdio.h> //printf
#include <fcntl.h> //open

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    static int buffer_pos = 0;
    static int bytes_read = 0;
    int line_pos;
    char *line;

    if(fd < 0 || BUFFER_SIZE < 1)
        return(NULL);
    line = malloc(10000);
    if(!line)
        return(NULL);
    line_pos = 0;
    while(1)
    {
        if(buffer_pos >= bytes_read)
        {
            bytes_read = read(fd, buffer, BUFFER_SIZE);
            buffer_pos = 0;
            if(bytes_read <= 0)
                break;
        }
        while(buffer_pos < bytes_read)
        {
            line[line_pos++] = buffer[buffer_pos++];
            if(line[line_pos - 1] == '\n')
            {
                line[line_pos] = '\0';
                return(line);
            }
        }
    }
	
    if(line_pos > 0)
    {
        line[line_pos] = '\0';
        return(line);
    }
    free(line);
    return(NULL);
}

int main (void)
{
	int fd = open("input.txt", O_RDONLY);
    char *line;

    while((line = get_next_line(fd))!= NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return(0);
}

