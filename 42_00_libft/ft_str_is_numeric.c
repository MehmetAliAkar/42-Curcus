#include <stdio.h>

int ft_str_is_numeric(char *str)
{
    int i;

    i = 0;
    if (str[i] == '\0')
    {
        return (1);
    }
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int main(void)
{
    printf("%d  %d  %d",ft_str_is_numeric("324432409"), ft_str_is_numeric("3424453."),ft_str_is_numeric("sdsdws32xc"));
    return (0);
}