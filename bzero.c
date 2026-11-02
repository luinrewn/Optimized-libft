// void    ft_bzero(void *s, size_t n)
//   16   │ {
//   17   │     unsigned char   *ss;
//   18   │     unsigned char   c;
//   19   │ 
//   20   │     c = '\0';
//   21   │     ss = (unsigned char *)s;
//   22   │     while (n--)
//   23   │         *ss++ = c;
//   24   │ }
//

#include <stdint.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	char *src;
	uintptr_t t;
	uintptr_t	*str_64;

	src = s;
	while(n > 0 && (uintptr_t)src & 7)
	{
		*src++ = 0;
		n--;
	}
	str_64 = (uintptr_t *)src;
	while (n > 7)
	{
		*str_64++ = 0;
		n -= 8;
	}
	src = (char *)str_64;
	while (n-- > 0)
		*src++ = 0;
}

// #include <stdio.h>
// #include <string.h>
// #include <stdint.h>
//
// // Declare your function so main can see it
// void    ft_bzero(void *s, size_t n);
//
// // A simple helper to print memory bytes in hex
// void print_mem(unsigned char *s, size_t size)
// {
//     for (size_t i = 0; i < size; i++)
//     {
//         printf("%02X ", s[i]);
//     }
//     printf("\n");
// }
//
// int main(void)
// {
//     // Test 1: Standard Buffer (Perfectly aligned 16 bytes)
//     printf("--- Test 1: Standard 16-byte Buffer ---\n");
//     unsigned char buffer1[16] = "0123456789ABCDEF";
//     printf("Before: "); print_mem(buffer1, 16);
//
//     ft_bzero(buffer1, 16);
//     printf("After : "); print_mem(buffer1, 16);
//
//
//     // Test 2: Misaligned & Odd Size (Clearing 11 bytes starting at index 3)
//     printf("\n--- Test 2: Misaligned & Odd Size ---\n");
//     unsigned char buffer2[16] = "0123456789ABCDEF";
//     printf("Before: "); print_mem(buffer2, 16);
//
//     // Pass a pointer shifted by 3 bytes, and clear only 11 bytes
//     ft_bzero(buffer2 + 3, 11);
//
//     // Expectation: First 3 bytes and last 2 bytes remain untouched ("012" and "EF")
//     printf("After : "); print_mem(buffer2, 16);
//
//
//     // Test 3: Zero Size (Should do absolutely nothing)
//     printf("\n--- Test 3: Zero Size ---\n");
//     unsigned char buffer3[16] = "0123456789ABCDEF";
//     printf("Before: "); print_mem(buffer3, 16);
//
//     ft_bzero(buffer3, 0);
//     printf("After : "); print_mem(buffer3, 16);
//
//     return (0);
// }

