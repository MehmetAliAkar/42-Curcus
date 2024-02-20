/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meakar <meakar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:59:25 by meakar            #+#    #+#             */
/*   Updated: 2023/07/25 14:59:25 by meakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 15
#endif 

char *move_forward(char *bigline)
{
    char    *newbig;
    int     i;
    int     j;

    if (!bigline)
        return (NULL);
    i = 0;
    while (bigline[i] && bigline[i] != '\n')
        i++;
    if (bigline[i] == '\n')
        i++;
    newbig = malloc(ft_strlen(bigline) - i + 1);
    if (!newbig)
        return (NULL);
    j = 0;
    while (bigline[i + j])
        newbig[j] = bigline[i + j];
    newbig[j] = '\0';
    free(bigline);
    return (newbig);
}

char    *extract_newline(char *bigline)
{
    char    *newline;
    int     i;
    
    if (!bigline || bigline[0] == '\0')
        return (NULL);
    i = 0;
    while (bigline [i] && bigline[i] != '\n')
        i++;
    if (bigline[i] == '\n')
        i++;
    newline = malloc(sizeof(char) * (i + 1));
    if (!newline)
        return (NULL);
    i = 0;
    while (bigline[i] && bigline[i] != '\n')
    {
        newline[i] = bigline[i];
        i++;
    }
    if (bigline[i] != '\n')
        newline[i++] = '\n';
    newline[i] = '\0';
    return (newline);
}

char * append_to_bigline(char * bigline, char *buffer)
{
    char    *newbig;
    int     i;
    int     j;

    if (bigline == NULL)
    {
        bigline = malloc(sizeof(char));
        bigline[0] = '\0';
    }
    if (!bigline || !buffer)
        return (NULL);
    newbig = malloc(ft_strlen(bigline) * ft_strlen(buffer) + 1);
    if (!newbig)
        return (NULL);
    i = 0;
    while (bigline[i++])
        newbig[i] = bigline[i];
    j = 0;
    while (buffer[j])
        newbig[i++] = buffer[j++];
    newbig[i] = '\0';
    free(bigline);
    return (newbig);
}

char *get_next_line(int fd)
{
    static char * bigline;
    char        * buffer;
    int         temp_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    temp_read = read(fd, buffer, BUFFER_SIZE);
    if (temp_read == -1)
    {
        free(buffer);
        free(bigline);
        return (NULL);
    }
    buffer[temp_read] = '\0';
    bigline = append_to_bigline(bigline, buffer);
    free(buffer);
    if (has_newline(bigline) == 1 || temp_read == 0)
    {
        buffer = extract_newline(bigline);
        bigline = move_forward(bigline);    
        return (buffer);
    }
    else
        return (get_next_line(fd));
}

int main(void)
{
    int fd = open("text.txt",O_RDONLY);

    char * newline;

    while (newline = get_next_line(fd))
    {
        printf("%s",newline);
        free(newline);
    }
    return 0;
}