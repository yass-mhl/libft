#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
  char *res;
  size_t i;

  if (!s)
    return (NULL);
  res = ft_memalloc(len + 1);
  if (!res)
    return (NULL);
  i = 0;
  while (i < len)
  {
    res[i] = s[start];
    i++;
    start++;
  }
  res[i] = 0;

  return (res);
}
