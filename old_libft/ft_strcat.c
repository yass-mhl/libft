/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:00:22 by ymehlil           #+#    #+#             */
/*   Updated: 2022/11/01 17:03:32 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strcat(char *dest, const char *src)
{
  int i;
  int len;
  len = 0;
  i = 0;
  while (dest[len])
    len++;
  while (src[i])
  {
    dest[len + i] = src[i];
    i++;
  }
  dest[len + i] = 0;
  return (dest);
}
