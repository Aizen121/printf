/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaazouz <amaazouz@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:17:31 by amaazouz          #+#    #+#             */
/*   Updated: 2025/11/06 14:37:16 by amaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	ft_convertion(char *format, args, count)
{
	if (*format == 'c')
}

int	ft_printf(char *format, ...)
{
	int	i;
	int	count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_convertion(va_arg(args, char *, count));
		}
		else
		{
			write(1, &format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	format(4, " dodo", " bobo"," fofo", " 66");
	format(3," 22"," dd1"," ddle");
	format(1, " dlele");
	return (0);
}
