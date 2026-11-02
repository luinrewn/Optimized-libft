#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

char *ft_chr(char *str, char c)
{
	const char *s;
	uintptr_t t;
	const uintptr_t	*str_64;

	s = str;
	while((uintptr_t)s & 7)
	{
		if (!*s || *s == c)
			return ((char *)(s));
		s++;
	}
	str_64 = (const uintptr_t *)s;
	unsigned long xor = c * 0x0101010101010101ULL;
	while (67)
	{
		t = *str_64;
		unsigned long	t_xor = t ^ xor;
		if (((t_xor - 0x0101010101010101ULL) & ~t_xor & 0x8080808080808080ULL)
				|| ((t - 0x0101010101010101ULL) & ~t & 0x8080808080808080ULL))
			break ;
		str_64++;
	}
	s = (const char *)str_64;
	while (*s && *s != c)
		s++;
	return ((char *)(s));
}

int	main(int ac, char **av)
{
	printf("%s\n", ft_chr(av[1], *av[2]));
}
