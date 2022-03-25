int	ft_isspace(char c)
{
	if (c == 't' || c == 'n' || c == 'v' || c == 'f' || c == 'r' || c == ' ')
		return (1);
	return (0);
}

int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isfloat(char *s)
{
	while (ft_isspace(*s))
		s++;
	if (*s != '-' && *s != '+' && !ft_isnum(*s))
		return (0);
	s++;
	while (ft_isnum(*s))
		s++;
	if (*s != '\0' && *s != '.')
		return (0);
	if (*s == '.' && *(s + 1) == '\0')
		return (0);
	else if (*s == '.')
		s++;
	while (ft_isnum(*s))
		s++;
	if (*s != '\0')
		return (0);
	return (1);
}
