#include "libft.h"

// le header marche pas je vais peter un plomb donc je vais copier coller ft_memset

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

int main(void)
{
    int size;

    size = 3;
    ft_memalloc(3);
    return (0);
}
