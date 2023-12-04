#include "philo.h"

long	ft_atoi(const char *str)
{
	long	a;
	long	b;

	a = 0;
	b = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		b *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		a = a * 10 + *str - '0';
		str++;
	}
	return (a * b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	real_len;

	if (!s)
		return (NULL);
	real_len = ft_strlen(s);
	if ((size_t)start > real_len)
		return (ft_strdup(""));
	if (len > real_len)
		len = real_len;
	p = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!p)
		return (0);
	while (i < len)
	{
		p[i] = *(s + start + i);
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1)+1;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (0);
	ft_memcpy(str, s1, len);
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*c;

	d = (char *)dst;
	c = (char *)src;
	if (!dst && !src)
		return (0);
	if ((dst == src) || n == 0)
		return (dst);
	while (n--)
	d[n] = c[n];
	return (d);
}
