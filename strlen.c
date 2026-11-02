#include <stdint.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	const char *s;
	uintptr_t t;
	const uintptr_t	*str_64;

	s = str;
	while((uintptr_t)s & 7)
	{
		if (!*s)
			return (s - str);
		s++;
	}
	str_64 = (const uintptr_t *)s;
	while (67)
	{
		t = *str_64;
		if ((t - 0x0101010101010101ULL) & ~t & 0x8080808080808080ULL)
			break ;
		str_64++;
	}
	s = (const char *)str_64;
	while (*s)
		s++;
	return (s - str);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	int		result;
	char	str[50] = "abcdfdfd    ";
	char	*empty;

	empty = NULL;
	result = ft_strlen(&str[0]);
	printf("%d\n", result);
	result = strlen(&str[0]);
	printf("%d\n", result);
	// result = ft_strlen(empty);
	// printf("%d\n", result);
	// result = strlen(empty);
	// printf("%d\n", result);
} */
