/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:34:05 by ymehlil           #+#    #+#             */
/*   Updated: 2022/11/01 17:03:32 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int calcul_len(long n)
{
  int len;

  len = 0;
  if (n < 0)
  {
    n *= -1;
    len++;
  }
  if (n == 0)
    return (len + 1);
  while (n > 0)
  {
    n /= 10;
    len++;
  }
  return (len);
}

char *ft_itoa(int n)
{
  int len;
  long nbr;
  char *res;

  nbr = n;
  len = calcul_len(nbr);
  res = (char *)malloc(sizeof(char) * len + 1);
  if (!res)
    return (NULL);
  res[len] = 0;
  len--;
  if (nbr == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = nbr * -1;
	}
  while (nbr > 0)
	{
		res[len--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (res);
}
