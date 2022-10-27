#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

// int main()
// {
// 	char str[] = "http://www.tutorialspoint.com";
// 	char ch = '.';
// 	char *ret;

// 	ret = ft_strchr(str, ch);
// 	printf("String after |%c| is - |%s|\n", ch, ret);
// 	return (0);
// }
