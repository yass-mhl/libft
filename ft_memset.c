/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:35:12 by ymehlil           #+#    #+#             */
/*   Updated: 2022/11/01 17:03:32 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// La fonction memset() remplit les n premiers octets de la zone mémoire pointée par s avec l'octet c.
void *ft_memset(void *b, int c, size_t len)
{
  // unsigned integer type of at least 16 bit
  size_t i;
  i = 0;

  while (i < len)
  {
    // cast b en string et c en char
    ((unsigned char *)b)[i] = (unsigned char)c;
    i++;
  }
  return (b);
}
