int ft_toupper(int c)
{
  if (c >= 'A' && c <= 'Z')
    return (c + 32);
  return (c);
}

#include <stdio.h>

int main(int ac, char **av)
{
  (void)ac;
  printf("%c\n", ft_toupper(av[1][0]));
}
