/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:34:07 by isneves-          #+#    #+#             */
/*   Updated: 2024/05/31 21:44:14 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_fmt(char spc, va_list args)
{
	int	count;

	count = 0;
	if (spc == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (spc == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (spc == 'i' || spc == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (spc == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (spc == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (spc == 'x')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 0);
	else if (spc == 'X')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 1);
	else
		count += write (1, &spc, 1);
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		count;

	va_start(args, fmt);
	count = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			count += print_fmt(*(++fmt), args);
		else
			count += write(1, fmt, 1);
		++fmt;
	}
	va_end(args);
	return (count);
}

/*int main()
{
    printf("Character: %c\n", 'A');
    printf("String: %s\n", "Hello, world!");
    printf("Pointer: %p\n", (void *)0x7ffeefbff5c8);
    printf("Decimal: %d\n", 12345);
    printf("Integer: %i\n", -12345);
    printf("Unsigned: %u\n", 12345);
    printf("Hex lowercase: %x\n", 0xabcdef);
    printf("Hex uppercase: %X\n", 0xABCDEF);
    printf("Percent sign: %%\n");
	
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "Hello, world!");
    ft_printf("Pointer: %p\n", (void *)0x7ffeefbff5c8);
    ft_printf("Decimal: %d\n", 12345);
    ft_printf("Integer: %i\n", -12345);
    ft_printf("Unsigned: %u\n", 12345);
    ft_printf("Hex lowercase: %x\n", 0xabcdef);
    ft_printf("Hex uppercase: %X\n", 0xABCDEF);
    ft_printf("Percent sign: %%\n");

    return 0;
}*/
