#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (1);
  if (!s1 || !s2)
        return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}


// int main(void)
// {
// 	char *str1 = "tew";
// 	char *str2 = "tew";
// 	int n = 2;

// 	printf("%d", ft_strnequ(str1, str2, n));
// 	return (0);
// }
