/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:40:54 by ymehlil           #+#    #+#             */
/*   Updated: 2022/11/04 18:40:56 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char * ft_strnew(size_t size)
{
  size_t i;
  char *str;

  str = (char *)malloc(sizeof(char) * (size + 1));
  if (!str)
    return (NULL);
  i = 0;
  while (i < size)
  {
    str[i] = 0;
    i++;
  }
  str[i] = 0;
  return (str);
}
