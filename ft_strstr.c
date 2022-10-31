#include "libft.h"

char *ft_strstr(const char *str, const char *to_find)
{
  unsigned i;
  unsigned j;

  i = 0;
  if (to_find[0] == '\0')
		return ((char *)str);
  while (str[i])
  {
    j = 0;
    while (str[i + j] == to_find[j])
    {
      if(to_find[j + 1] == 0)
        return ((char *)str + i);
      j++;
    }
    i++;
  }
  return (0);
}
