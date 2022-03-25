#include "img.h"

double	ft_atof(char *s)
{
	double	nbr;
	double	sign;
	int		count_decimal;

	sign = 1.0;
	while (ft_isspace(*s))
		s++;
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
	return (nbr / pow(10.0, (double)count_decimal));
}
