#include "libft.h"

void  ft_putstr(char const *s)
{
  while(*s)
    write(1, s++, 1);
}

// int main(int ac, char **av)
// {
//   (void)ac;
//   ft_putstr(av[1]);
// }
