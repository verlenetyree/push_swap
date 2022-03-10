#include <stdio.h>

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}


int64_t	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	int64_t		n;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
		str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		n = (str[i] - '0') + (n * 10);
		i++;
	}
	return (sign * n);
}

int	main()
{
	printf("%lld\n", ft_atoi("+2147483648"));
	return(0);
}
