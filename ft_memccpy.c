/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:34:38 by ymehlil           #+#    #+#             */
/*   Updated: 2022/11/01 17:03:32 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void  *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
  size_t  i;
  i = 0;

  while (i < n)
  {
    ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
    if(((unsigned char *)src)[i] == (unsigned char)c)
      return (dest + i + 1);
    i++;
  }
  return (NULL);
}
