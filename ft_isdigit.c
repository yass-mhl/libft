int ft_isdigit(int c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

#include "libft.h"

int main(int ac, char **av)
{
  (void)ac;
  printf("%d\n", ft_isdigit(av[1][0]));
}
