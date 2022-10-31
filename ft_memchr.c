#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
  size_t i;
  unsigned char *string;

  i = 0;
  string = (unsigned char *)s;

  while (i < n)
  {
    if (string[i] == (unsigned char)c)
      return (string + i);
    i++;
  }
  return (NULL);
}
