#include "../lib.h"

int ft_is_in_charset(char *str, char *charset)
{
    int i;
    int j;

    i = 0;
    while (i <= ft_strlen(str))
    {
        j = 0;
        while(charset[j])
        {
            if (str[i] == charset[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}