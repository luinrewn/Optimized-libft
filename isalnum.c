int ft_isalnum(int c)
{
	return (ft_isalpha(c) || (c >= '0' && c <= '9'));
}

int	ft_isalpha(int c)
{
	return ((c | 32) >= 'a' && (c | 32) <= 'z');
}

int	ft_isascii(int c)
{
	return ((unsigned int)c <= 127))
}

int	ft_isdigit(int c)
{
	return ((c & 0xF0) == 0x30);
}

int	ft_isprint(int c)
{
	return ((unsigned char)(c - 32) <= 94)
}
