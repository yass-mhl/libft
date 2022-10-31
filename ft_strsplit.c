#include "libft.h"

ssize_t    nombre_de_mot(char *str, char c)
{
    int    i;
    int    j;

    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (str[i] != c)
        {
            j++;
            while (str[i] != c && str[i] != '\0')
                i++;
        }
        else
            i++;
    }
    return (j);
}

char    **ft_split(char **split, char *str, char c, size_t k)
{
    size_t        i;
    size_t        start;
    size_t        j;

    i = 0;
    start = 0;
    j = 0;
    while (str[i] && j < k)
    {
        if (str[i] != c)
        {
            start = i;
            while (str[i] != c && str[i])
                i++;
            split[j] = ft_strsub(str, start, i - start);
            j++;
        }
        else
            i++;
    }
    split[j] = NULL;
    return (split);
}

char    **ft_strsplit(char const *str, char c)
{
    char        **split;
    size_t        k;

    if (!str)
        return (NULL);
    k = nombre_de_mot((char *)str, c);
    split = NULL;
    split = (char **)malloc((k + 1) * sizeof(char *));
    if (!split)
        return (NULL);
    split = ft_split(split, (char *)str, c, k);
    return (split);
}
