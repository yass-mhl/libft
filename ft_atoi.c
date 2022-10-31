#include "libft.h"

int ft_atoi(const char *str)
{
  int i;
  int res;
  int neg;

  i = 0;
  res = 0;
  neg = 1;

  if (str[i] == '\0')
		return (0);
  while (str[i] == '\n' || str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
  if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - 48;
		i++;
	}
	return (res * neg);
}
