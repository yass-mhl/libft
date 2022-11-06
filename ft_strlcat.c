/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:40:18 by ymehlil           #+#    #+#             */
/*   Updated: 2022/11/04 18:40:20 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
  size_t i;
  size_t j;
  size_t total;

  i = 0;
  j = 0;
  total = 0;
  while (dest[i])
		i++;
  while(src[total])
    total++;
  if (i >= size)
    total += size;
  else
    total += i;

  while (src[j] && i + 1 < size)
  {
    dest[i] = src[j];
    i++;
    j++;
  }
  dest[i] = 0;
  return (total);
}
