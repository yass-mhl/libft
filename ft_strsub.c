/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:41:13 by ymehlil           #+#    #+#             */
/*   Updated: 2022/11/04 18:41:15 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
  char *res;
  size_t i;
  size_t j;

  if (!s)
    return (NULL);
  res = (char *)ft_memalloc(len + 1);
  if (!res)
    return (NULL);
  i = 0;
  j = 0;
  while (s[i])
  {
    if (i >= start && j < len)
    {
      res[j] = s[i];
      j++;
    }
    i++;
  }
  res[j] = 0;
  return (res);
}
