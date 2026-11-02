int	ft_tolower(int c)
{
	return (c | ((c >= 'A' && c <= 'Z') << 5));
}

// int	main(void)
// {
// 	printf("%c\n", ft_tolower('A'));
// 	printf("%c\n", ft_tolower('A' - 1));
// 	printf("%c\n", ft_tolower(-1));
// 	printf("%c\n", ft_tolower(48));
// }
