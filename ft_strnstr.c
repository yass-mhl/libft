#include "libft.h"

char *ft_strnstr(const char *str, const char *to_find, size_t len)
{
  unsigned int i;
  unsigned int j;

  i = 0;
  if (to_find[0] == '\0')
		return ((char *)str);
  while (str[i] && i < len)
  {
    j = 0;
    while (str[i + j] == to_find[j] && (i + j) < len)
    {
      if (to_find[j + 1] == 0)
        return ((char *)str + i);
      j++;
    }
    i++;
  }
  return (0);
}
