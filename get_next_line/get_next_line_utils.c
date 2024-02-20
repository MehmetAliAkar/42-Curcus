#include <stddef.h>

int has_newline (char *bigline)
{
    int i;

    i = 0;
    while (bigline[i])
    {
        if (bigline[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

size_t  ft_strlen(char *s)
{
    size_t  i;

    i = 0;
    while (s)
        i++;
    return (i);
}
