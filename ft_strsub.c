#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
  size_t i;
  i = 0;

  while (i < len)
  {
    ((unsigned char *)b)[i] = (unsigned char)c;
    i++;
  }
  return (b);

}

void  *ft_memalloc(size_t size)
{
  unsigned char *ptr;
  ptr = malloc(size);
  if (!ptr)
    return (NULL);
  ft_memset(ptr, 0, size);
  return (ptr);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
  char *res;
  int i;

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

// int main(void)
// {
// 	char *str1 = "lorem ispusm dolor sit amet";
// 	unsigned int start = 7;
// 	int len = 10;

// 	printf("%s", ft_strsub(str1, start, len));
// 	return (0);
// }
