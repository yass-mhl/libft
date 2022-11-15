/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:34:45 by ymehlil           #+#    #+#             */
/*   Updated: 2022/11/01 17:03:32 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
  size_t i;
  unsigned char *string;

  i = 0;
  string = (unsigned char *)s;

  while (i < n)
  {
    if (string[i] == (unsigned char)c)
      return (string + i);
    i++;
  }
  return (NULL);
}
