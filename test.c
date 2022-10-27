#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>

void	memset_test(void)
{
	char *test = "This is test string";
	char *buf1 = strdup(test);
	char *buf2 = strdup(test);
	int i = -1;
	while (++i < 300)
	{
		memset(buf1, i, strlen(test));
		ft_memset(buf2, i, strlen(test));
		if (strcmp(buf1, buf2) != 0)
			printf("     Fail! ft_memset('%s', %c, %zu): '%s' <=> '%s'\n",
			test, i, strlen(test), buf2, buf1);
	}
}

void	bzero_test(void)
{
	struct example
	{
		char	*s;
		int		len;
	};
	struct example test[] =	{
								"abcdefgh", 9,
								"", 1,
								"\0", 1,
								"\0\0\0", 3,
								"abc\0\0abc\0", 6
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	char *buf1;
	char *buf2;
	while (++i < count)
	{
		buf1 = strdup(test[i].s);
		buf2 = strdup(test[i].s);
		bzero(buf1, test[i].len);
		ft_bzero(buf2, test[i].len);
		if (strcmp(buf1, buf2) != 0)
			printf("     Fail! ft_bzero('%s'): '%s' <=> '%s'\n",
			test[i].s, buf2, buf1);
	}
}

void	memcpy_test(void)
{
	char *test[] =	{
						"This is string0rrr",
						"This is string0",
						"This is string2",
						"This is string22",
						"This",
						"This is string5",
						"This is ",
						"is string7",
						"This is string8test",
						"This is string8test"
					};
	int count = sizeof(test) / sizeof(test[0]);
	char *buf1 = malloc(sizeof(char) * 25);
	char *buf2 = malloc(sizeof(char) * 25);
	int i = -1;
	while (++i < count)
	{
		buf1 = memcpy(buf1, test[i], strlen(test[i]));
		buf2 = ft_memcpy(buf2, test[i], strlen(test[i]));
		if (strcmp(buf1, buf2) != 0)
			printf("     Fail! ft_memcpy('', '%s', %zu): '%s' <=> '%s'\n",
			test[i], strlen(test[i]), buf1, buf2);
	}
}

void	memccpy_test(void)
{
	struct example
	{
		char	*s;
		char	c;
		int		len;
	};
	struct example test[] =	{
								"This is string1", 's', 15,
								"This is string1", 'r', 15,
								"This is string1", 'l', 15,
								"This is string1", '1', 15,
								"This is string1", '\0', 15
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	char buf1[100] = "";
	char buf2[100] = "";
	while (++i < count)
	{
		memccpy(buf1, test[i].s, test[i].c, test[i].len);
		ft_memccpy(buf2, test[i].s, test[i].c, test[i].len);
		if (strcmp(buf1, buf2) != 0)
			printf("     Fail! ft_memccpy('', '%s', %c, %i): '%s' <=> '%s'\n",
			test[i].s, test[i].c, test[i].len, buf2, buf1);
	}
}

void	memmove_test(void)
{
	char	str1[100] = "This is test string!";
	char	str2[100] = "This is test string!";
	char	buf1[100];
	char	buf2[100];

	memmove(&str1[20], &str1[6], 15);
	ft_memmove(&str2[20], &str2[6], 15);
	if (strcmp(str1, str2) != 0)
		printf("     Fail! ft_memmove: '%s' <=> '%s'\n", str1, str2);

	memmove(&str1[2], &str1[6], 10);
	ft_memmove(&str2[2], &str2[6], 10);
	if (strcmp(str1, str2) != 0)
		printf("     Fail! ft_memmove: '%s' <=> '%s'\n", str1, str2);

	memmove(&str1[0], &str1[28], 50);
	ft_memmove(&str2[0], &str2[28], 50);
	if (strcmp(str1, str2) != 0)
		printf("     Fail! ft_memmove: '%s' <=> '%s'\n", str1, str2);

	memmove(buf1, str1, 15);
	ft_memmove(buf2, str2, 15);
	if (strcmp(str1, str2) != 0)
		printf("     Fail! ft_memmove: '%s' <=> '%s'\n", buf1, buf2);
}

void	memchr_test(void)
{
	int i = -1;
	char *s1;
	char *s2;
	char *s = "This is string1";
	while (++i < 300)
	{
		s1 = memchr(s, i, 15);
		s2 = ft_memchr(s, i, 15);
		if (ft_strequ(s1, s2) == "null")
			printf("     Fail! ft_memchr('%s', %c, 15): '%s' <=> '%s'\n",
			s, i, s2, s1);
	}
}

void	memcmp_test(void)
{
	struct example
	{
		char	*s1;
		char	*s2;
		int		len;
	};
	struct example test[] =	{
								"This is string0", "This is string0", 15,
								"This is string0", "This is string2", 15,
								"This is string2", "This is string22", 15,
								"This is string22", "This", 15,
								"This", "This is string5", 15,
								"This is string5", "This is ", 15,
								"This is ", "is string7", 15,
								"is string7", "This is string8test", 15,
								"This is string8test", "This is string8test", 15,
								"This", "This ", 3,
								"This", "This ", 4,
								"This", "This ", 5,
								"This", "This ", 6
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while (++i < count)
	{
		int res1 = memcmp(test[i].s1, test[i].s2, test[i].len);
		int res2 = memcmp(test[i].s1, test[i].s2, test[i].len);
		if (res1 != res2)
			printf("     Fail! ft_memcmp('%s', '%s', %i): %i <=> %i\n",
			test[i].s1, test[i].s2, test[i].len, res2, res1);
	}
}

void	strlen_test(void)
{
	char *test[] =	{
						"This is test string!",
						"This",
						"",
						" \t\022",
						0
					};
	int i = -1;
	while (test[++i])
	{
		if (strlen(test[i]) != ft_strlen(test[i]))
			printf("     Fail! ft_strlen('%s'): %zu <=> %zu\n",
			test[i], ft_strlen(test[i]), strlen(test[i]));
	}
}

void	strdup_test(void)
{
	printf("%s", strcmp(strdup("Test"), ft_strdup("Test")) == 0 ?
			"" :
			"Fail");
	printf("%s", strcmp(strdup("484df41hdy1h111fs1fsd15sf15sdf115d15fdgs15gfd4sg1615df156g1515g4erg4561esg156gr15156g15eg15eg15e51e51g1515ge156e156eg156e15156ge516e1551eg51eg15g1551eg15e516eg15e15eg1515e55eg51e15e51g5151eg15eg1515egr515151erg51er51e51e551ee5eg51egr51er51er5er5eg51e5r1e51rg5egr5eg51erg5e1r51e6rg51egr516ee5g15e1g5e1g5e1g51ger51egr51erg55reg5er55er55"), ft_strdup("484df41hdy1h111fs1fsd15sf15sdf115d15fdgs15gfd4sg1615df156g1515g4erg4561esg156gr15156g15eg15eg15e51e51g1515ge156e156eg156e15156ge516e1551eg51eg15g1551eg15e516eg15e15eg1515e55eg51e15e51g5151eg15eg1515egr515151erg51er51e51e551ee5eg51egr51er51er5er5eg51e5r1e51rg5egr5eg51erg5e1r51e6rg51egr516ee5g15e1g5e1g5e1g51ger51egr51erg55reg5er55er55")) == 0 ?
			"" :
			"Fail");
}

void	strcpy_test(void)
{
	char *test[] =	{
						"This is test string!",
						"This",
						"Just one more test",
						"",
						" \t\022",
						0
					};
	char buf1[25];
	char buf2[25];
	int i = -1;
	while(test[++i])
	{
		strcpy(buf1, test[i]);
		ft_strcpy(buf2, test[i]);
		if (strcmp(buf1, buf2) != 0)
			printf("     Fail! ft_strcpy('', '%s'): '%s' <=> '%s'\n",
			test[i], buf2, buf1);
	}
}

void	strncpy_test(void)
{
	struct example
	{
		char	*s;
		int		len;
	};
	struct example test[] =	{
								"This is test string!", 25,
								"This", 2,
								"Just one more test", 0,
								"", 0,
								"", 5
							};
	char *buf1;
	char *buf2;
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while(++i < count)
	{
		buf1 = malloc(sizeof(char) * 25);
		buf2 = malloc(sizeof(char) * 25);
		strncpy(buf1, test[i].s, test[i].len);
		ft_strncpy(buf2, test[i].s, test[i].len);
		if (strcmp(buf1, buf2) != 0)
			printf("     Fail! ft_strncpy('%s', %i): '%s' <=> '%s'\n",
			test[i].s, test[i].len, buf2, buf1);
	}
}

void	strcat_test(void)
{
	struct example
	{
		char	*s1;
		char	*s2;
	};
	struct example test[] =	{
								"This is ", "test string",
								"This is", "",
								"", "This is",
								"", "",
								" \t\022", "\t\022"
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while(++i < count)
	{
		char *buf1 = malloc(sizeof(char) * 100);
		char *buf2 = malloc(sizeof(char) * 100);
		strcpy(buf1, test[i].s1);
		strcpy(buf2, test[i].s1);
		strcat(buf1, test[i].s2);
		ft_strcat(buf2, test[i].s2);
		if (strcmp(buf1, buf2) != 0)
			printf("     Fail! ft_strcat('%s', '%s'): '%s' <=> '%s'\n",
			test[i].s1, test[i].s2, buf2, buf1);
	}
}

void	strncat_test(void)
{
	struct example
	{
		char	*s1;
		char	*s2;
		int		len;
	};
	struct example test[] =	{
								"This is ", "test string", 5,
								"This is", "", 3,
								"This is", "abcdefghijklmnopqrstuvwxyz", 10,
								"", "This is", 3,
								"", "", 0,
								" \t\022", "\t\022", 1,

							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while(++i < count)
	{
		char *buf1 = malloc(sizeof(char) * 100);
		char *buf2 = malloc(sizeof(char) * 100);
		strcpy(buf1, test[i].s1);
		strcpy(buf2, test[i].s1);
		strncat(buf1, test[i].s2, test[i].len);
		ft_strncat(buf2, test[i].s2, test[i].len);
		if (strcmp(buf1, buf2) != 0)
			printf("     Fail! ft_strncat('%s', '%s', %i): '%s' <=> '%s'\n",
			test[i].s1, test[i].s2, test[i].len, buf2, buf1);
	}
}

void	strlcat_test(void)
{
	struct example
	{
		char *dst;
		char *src;
		int n;
	};
	struct example test[] =	{
								"abc", "abc", 3,
								"", "abc", 0,
								"abc", "", 3,
								"", "", 1,
								"This is ", "string1", 5,
								"This is ", "string1", 20,
								"test", "This is string1", 0
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while (++i < count)
	{
		char *s1 = strdup(test[i].dst);
		char *s2 = strdup(test[i].dst);
		int r1 = strlcat(s1, test[i].src, test[i].n);
		int r2 = ft_strlcat(s2, test[i].src, test[i].n);
		if (strcmp(s1, s2) != 0 || r1 != r2)
			printf("     Fail! ft_strlcat('%s', '%s'): '%s' = %i <=> '%s' = %i\n",
			test[i].dst, test[i].src, s1, r1, s2, r2);
	}
}

void	strchr_test(void)
{
	char s[] = "This is test string!";
	int i = -1;
	while (++i < 300)
	{
		char *r1 = strchr(s, i);
		char *r2 = ft_strchr(s, i);
		if (ft_strequ(r1, r2) == "null" || r1 == r2)
			printf("");
	 	else
			printf("     Fail! ft_strchr('%s', %i): '%s' <=> '%s'\n",
			s, i, r2, r1);
	}
}

void	strrchr_test(void)
{
	char s[] = "This is test string!";
	int i = -1;
	char *r1;
	char *r2;
	while (++i <= 300)
	{
		r1 = strrchr(s, i);
		r2 = ft_strrchr(s, i);
		if (ft_strequ(r1, r2) == "null")
			printf("     Fail! ft_strrchr('%s', %i): '%s' <=> '%s'\n",
			s, i, r2, r1);
	}
}

void	strstr_test(void)
{
	struct example
	{
		char *s1;
		char *s2;
	};
	struct example test[] =	{
								"This is string0rrr", "This is string0",
								"This is string0", "This is string2",
								"This is string2", "This is string22",
								"This is string22", "This",
								"This", "This is string5",
								"This is string5", "This is ",
								"This is ", "is string7",
								"is string7", "This is string8test",
								"This is string8test", "This is string8test",
								"", "",
								"abc", ""
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while (++i < count)
	{
		char *r1 = strstr(test[i].s1, test[i].s2);
		char *r2 = ft_strstr(test[i].s1, test[i].s2);
		if (r1 != r2)
			printf("     Fail! ft_strstr('%s', '%s'): '%s' <=> '%s'\n",
			test[i].s1, test[i].s2, r2, r1);
	}
}


void	strnstr_test(void)
{
	struct example
	{
		char	*s1;
		char	*s2;
		int		n;
	};
	struct example test[] =	{
								"This is test string", "is", 19,
								"This is test string", "", 20,
								"This is test string", "This is test strin1", 19,
								"This is test string", "This is test string", 19,
								"This is test string", "This is test string", 18,
								"This is test string", "test", 11,
								"This is test string", "test", 12,
								"", "", 1,
								"", "", 0,
								"abc", "", 0,
								"abc", "", 3
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while (++i < count)
	{
		char *r1 = strnstr(test[i].s1, test[i].s2, test[i].n);
		char *r2 = ft_strnstr(test[i].s1, test[i].s2, test[i].n);
		if (ft_strequ(r1, r2) == 0 || r1 == r2)
            printf("");
		else
        {
            printf("     Fail! ft_strnstr('%s', '%s', %i): '%s' <=> '%s'\n",
			test[i].s1, test[i].s2, test[i].n, r2, r1);
        }
	}
}

void	strcmp_test(void)
{
	struct example
	{
		char *s1;
		char *s2;
	};
	struct example test[] =	{
								"abc", "abc",
								"", "abc",
								"abc", "abcd",
								"abcd", "abc",
								"This", "This is string5",
								"This is string5", "string5",
								"", ""
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while (++i < count)
	{
		int r1 = strcmp(test[i].s1, test[i].s2);
		int r2 = ft_strcmp(test[i].s1, test[i].s2);
		if (r1 != r2)
			printf("     Fail! ft_strcmp('%s', '%s'): %i <==> %i\n",
			test[i].s1, test[i].s2, r2, r1);
	}
}

void	strncmp_test(void)
{
	struct example
	{
		char	*s1;
		char	*s2;
		int		len;
	};
	struct example test[] =	{
								"abc", "abc", 3,
								"", "abc", 1,
								"abc", "abcd", 4,
								"abcd", "abc", 3,
								"This", "This is string5", 5,
								"This is string5", "string5", 25,
								"This is test string", "is", 19,
								"This is test string", "", 20,
								"This is test string", "This is test strin1", 19,
								"This is test string", "This is test string", 19,
								"This is test string", "This is test string", 18,
								"This is test string", "test", 11,
								"This is test string", "test", 12,
								"", "", 3
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while (++i < count)
	{
		int r1 = strncmp(test[i].s1, test[i].s2, test[i].len);
		int r2 = ft_strncmp(test[i].s1, test[i].s2, test[i].len);
		if (r1 != r2)
			printf("     Fail! ft_strncmp('%s', '%s', %i): %i <==> %i\n",
			test[i].s1, test[i].s2, test[i].len, r2, r1);
	}
}

void	atoi_test(void)
{
	char *test[] =	{
						"2147483647",
						"-2147483648",
						"-210",
						"-2147bbb483648",
						"+2",
						"0",
						"-0",
						"+0",
						"++20",
						"--2",
						"\r\f\v\t\n 567 567 ",
						0
					};

	char *test2[] =	{
						"922337203685477580",
						"-922337203685477580",
						"9223372036854775807",
						"9223372036854775808",
						"-9223372036854775807",
						"-9223372036854775808",
						"19223372036854775807",
						"-19223372036854775808",
						0
					};

	int i = -1;
	while (test[++i])
	{
		if (atoi(test[i]) != ft_atoi(test[i]))
			printf("     Fail! ft_atoi('%s'): %d <=> %d\n", test[i], ft_atoi(test[i]), atoi(test[i]));
	}
	i = -1;
	while (test2[++i])
	{
		if (atoi(test[i]) != ft_atoi(test[i]))
			printf("     Warning! ft_atoi('%s'): %d <=> %d\n", test[i], ft_atoi(test[i]), atoi(test[i]));
	}
}

void	isalpha_test(void)
{
	int i = -300;
	while (++i < 300)
		if (isalpha(i) != ft_isalpha(i))
			printf("     Fail! ft_isalpha(%i): %i <=> %i\n",
			i, ft_isalpha(i), isalpha(i));
}

void	isdigit_test(void)
{
	int i = -300;
	while (++i < 300)
		if (isdigit(i) != ft_isdigit(i))
			printf("     Fail! ft_isdigit(%i): %i <=> %i\n",
			i, ft_isdigit(i), isdigit(i));
}

void	isalnum_test(void)
{
	int i = -300;
	while (++i < 300)
		if (isalnum(i) != ft_isalnum(i))
			printf("     Fail! ft_isalnum(%i): %i <=> %i\n",
			i, ft_isalnum(i), isalnum(i));
}

void	isascii_test(void)
{
	int i = -300;
	while (++i < 300)
		if (isascii(i) != ft_isascii(i))
			printf("     Fail! ft_isascii(%i): %i <=> %i\n",
			i, ft_isascii(i), isascii(i));
}

void	isprint_test(void)
{
	int i = -300;
	while (++i < 300)
		if (isprint(i) != ft_isprint(i))
			printf("     Fail! ft_isprint(%i): %i <=> %i\n",
			i, ft_isprint(i), isprint(i));
}

void	toupper_test(void)
{
	int i = -300;
	while (++i < 300)
		if (toupper(i) != ft_toupper(i))
			printf("     Fail! ft_toupper(%c): %c <=> %c\n",
			i, toupper(i), ft_toupper(i));
}

void	tolower_test(void)
{
	int i = -300;
	while (++i < 300)
		if (tolower(i) != ft_tolower(i))
			printf("     Fail! ft_tolower(%c): %c <=> %c\n",
			i, tolower(i), ft_tolower(i));
}

int		main(void)
{
	printf("TEST\n");
	printf("Part 1 :\n");
	printf("MEMSET TESTING... :\n"); memset_test();
	printf("OK\n");
	printf("BZERO TESTING... :\n"); bzero_test();
	printf("OK\n");
	printf("MEMCPY TESTING... :\n"); memcpy_test();
	printf("OK\n");
	printf("MEMCCPY TESTING... :\n"); memccpy_test();
	printf("OK\n");
	printf("MEMMOVE TESTING... :\n"); memmove_test();
	printf("OK\n");
	printf("MEMCHR TESTING... :\n"); memchr_test();
	printf("OK\n");
	printf("MEMCMP TESTING... :\n"); memcmp_test();
	printf("OK\n");
	printf("STRLEN TESTING... :\n"); strlen_test();
	printf("OK\n");
	printf("STRDUP TESTING... :\n"); strdup_test();
	printf("OK\n");
	printf("STRCPY TESTING... :\n"); strcpy_test();
	printf("OK\n");
	printf("STRNCPY TESTING... :\n"); strncpy_test();
	printf("OK\n");
	printf("STRCAT TESTING... :\n"); strcat_test();
	printf("OK\n");
	printf("STRNCAT TESTING... :\n"); strncat_test();
	printf("OK\n");
	printf("STRLCAT TESTING... :\n"); strlcat_test();
	printf("OK\n");
	printf("STRCHR TESTING... :\n"); strchr_test();
	printf("OK\n");
	printf("STRRCHR TESTING... :\n"); strrchr_test();
	printf("OK\n");
	printf("STRSTR TESTING... :\n"); strstr_test();
	printf("OK\n");
	printf("STRNSTR TESTING... :\n"); strnstr_test();
	printf("OK\n");
	printf("STRCMP TESTING... :\n"); strcmp_test();
	printf("OK\n");
	printf("STRNCMP TESTING... :\n"); strncmp_test();
	printf("OK\n");
	printf("ATOI TESTING... :\n"); atoi_test();
	printf("OK\n");
	printf("ISALPHA TESTING... :\n"); isalpha_test();
	printf("OK\n");
	printf("ISDIGIT TESTING... :\n"); isdigit_test();
	printf("OK\n");
	printf("ISALNUM TESTING... :\n"); isalnum_test();
	printf("OK\n");
	printf("ISASCII TESTING... :\n"); isascii_test();
	printf("OK\n");
	printf("ISPRINT TESTING... :\n"); isprint_test();
	printf("OK\n");
	printf("TOUPPER TESTING... :\n"); toupper_test();
	printf("OK\n");
	printf("TOLOWER TESTING... :\n"); tolower_test();
	printf("OK\n");
}
