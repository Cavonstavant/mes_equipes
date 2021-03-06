/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** readfile
*/

/// \file objects/wrapper/src/unpack_wrapper/readfile.c
/// \brief Read a file

#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

char *readfile(int fd)
{
    char *content = NULL;
    struct stat s;

    if (fd < 0 || fstat(fd, &s) < 0)
        return NULL;
    content = malloc(sizeof(char) * (s.st_size + 1));
    if (!content)
        return NULL;
    if (read(fd, content, s.st_size) < 0)
        return NULL;
    content[s.st_size] = '\0';
    return content;
}
