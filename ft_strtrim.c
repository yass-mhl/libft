/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:41:17 by ymehlil           #+#    #+#             */
/*   Updated: 2022/11/04 18:41:18 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s)
{
	char *ret;
	int ltrim;
	int rtrim;
	int len;
	int i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	ltrim = 0;
	while (s[ltrim] == ' ' || s[ltrim] == '\n' || s[ltrim] == '\t')
		ltrim++;
	rtrim = len - 1;
	while (s[rtrim] == ' ' || s[rtrim] == '\n' || s[rtrim] == '\t')
		rtrim--;
	len = rtrim - ltrim + 1;
	if (len <= 0)
		len = 0;
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
		ret[i++] = s[ltrim++];
	ret[i] = '\0';
	return (ret);
}
