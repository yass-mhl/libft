/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:40:45 by ymehlil           #+#    #+#             */
/*   Updated: 2022/11/04 18:40:47 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strncpy(char *dest, const char *src, size_t n)
{
  size_t i;
  i = 0;

  while (i < n && src[i])
  {
    dest[i] = src[i];
    i++;
  }
  while(i < n)
  {
    dest[i] = 0;
    i++;
  }
  return (dest);
}
