#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
  char *res;
  int len1, len2, i, y;

  len1 = 0;
  len2 = 0;

  if (!s1 || !s2)
		return (NULL);
  while (s1[len1])
    len1++;
  while (s2[len2])
    len2++;
  res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
  if (!res)
    return (NULL);
  i = 0;
  y = 0;
  while (s1[i])
  {
    res[i] = s1[i];
    i++;
  }
  while (s2[y])
  {
    res[i] = s2[y];
    i++;
    y++;
  }
  res[i] = 0;
  return (res);
}

int main(int ac, char **av)
{
  (void)ac;
  printf("%s", ft_strjoin(av[1], av[2]));
  return (0);
}
