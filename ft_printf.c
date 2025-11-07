/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaazouz <amaazouz@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:17:31 by amaazouz          #+#    #+#             */
/*   Updated: 2025/11/07 15:36:14 by amaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	c_format(char c);
int	s_format(const char *str);
int	put_number_base(unsigned long int n, char t);

int	ft_convertion(char c, va_list *args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += c_format(va_arg(*args, int));
	else if (c == 's')
		count += s_format(va_arg(*args, const char *));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		count += 2;
		count += put_number_base(va_arg(*args,unsigned long int), 'p');
	}
	return (count);
}

int	ft_printf(char *format, ...)
{
	int	count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_convertion(*format, &args);
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	char	*d = "doded";

	ft_printf(" jqjdhdj%p\n", &d);
	printf("%p",&d);
	return (0);
}
