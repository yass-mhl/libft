#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
  char *res;
  size_t i;
  size_t j;

  if (!s)
    return (NULL);
  res = (char *)ft_memalloc(len + 1);
  if (!res)
    return (NULL);
  i = 0;
  j = 0;
  while (s[i])
  {
    if (i >= start && j < len)
    {
      res[j] = s[i];
      j++;
    }
    i++;
  }
  res[j] = 0;
  return (res);
}
