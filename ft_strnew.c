#include "libft.h"

char * ft_strnew(size_t size)
{
  size_t i;
  char *str;

  str = (char *)malloc(sizeof(char) * (size + 1));
  if (!str)
    return (NULL);
  i = 0;
  while (i < size)
  {
    str[i] = 0;
    i++;
  }
  str[i] = 0;
  return (str);
}
