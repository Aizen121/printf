/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaazouz <amaazouz@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:17:31 by amaazouz          #+#    #+#             */
/*   Updated: 2025/11/05 21:10:50 by amaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	format(int n, ...)
{
	int	i;
	va_list	args;

	i = 0;
	va_start(args, n);
	while (i < n)
	{
		printf("%s", va_arg(args, char *));
		i++;
	}
	printf("\n");
	va_end(args);
}

int	main(void)
{
	format(4, " dodo", " bobo"," fofo", " 66");
	format(3," 22"," dd1"," ddle");
	format(1, " dlele");
	return (0);
}
