#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
  int len;
  int i;
  char *res;

  len = 0;
  while(s[len])
    len++;
  res = (char *)malloc(sizeof(char) * (len + 1));
  if (!res)
    return (NULL);
  i = 0;
  while(s[i])
  {
    res[i] = f(i, s[i]);
    i++;
  }
  res[i] = 0;
  return (res);
}
