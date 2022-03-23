static int	ft_isspace(char c)
{
	if (c == 't' || c == 'n' || c == 'v' || c == 'f' || c == 'r' || c == ' ')
		return (1);
	return (0);
}

static int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static double	ft_pow(double base, int exp)
{
	if (exp > 0)
		return (base * ft_pow(base, exp - 1));
	else
		return (1.0);
}

double	ft_atof(char *s)
{
	double	nbr;
	double	sign;
	int		count_decimal;

	sign = 1.0;
	while (ft_isspace(*s))
		s++;
	if (!ft_isnum(*s) && *s != '-' && *s != '+')
		return (0.0);
	if (*s == '-')
	{
		sign = -1.0;
		s++;
	}
	nbr = 0.0;
	while (ft_isnum(*s))
		nbr = nbr * 10.0 + ((double)(*s++ - '0') * sign);
	if (*s == '.')
		s++;
	count_decimal = 0;
	while (*s != '\0')
	{
		nbr = nbr * 10.0 + ((double)(*s++ - '0') * sign);
		count_decimal++;
	}
	return (nbr / ft_pow(10.0, count_decimal));
}
