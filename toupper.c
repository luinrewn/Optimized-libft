int	ft_toupper(int c)
{
	return (c & ~((c >= 'a' && c <= 'z') << 5));
}
//
// int	main(void)
// {
// 	printf("%c\n", ft_toupper('a'));
// 	printf("%c\n", ft_toupper('a' - 1));
// 	printf("%c\n", ft_toupper(-1));
// 	printf("%c\n", ft_toupper(48));
// }
