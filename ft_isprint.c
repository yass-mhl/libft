int ft_isprint(int c)
{
  return (c >= 32 && c <= 126);
}

#include "libft.h"

int main(int ac, char **av)
{
  (void)ac;
  printf("%d\n", ft_isprint(av[1][0]));
}
