#include "libft.h"

void ft_putchar(char c)
{
  write(1, &c, 1);
}

int main(int ac, char **av)
{
  (void)ac;
  ft_putchar('c');
}
