char *ft_strrchr(const char *s, int c)
{
  char *tmp;

  while(*s)
  {
    if (*s == c)
      tmp = ((char *)s);
    s++;
  }
  if (c == 0)
	{
		return ((char *)s);
	}
  if (tmp)
    return (tmp);
	return (0);
}
