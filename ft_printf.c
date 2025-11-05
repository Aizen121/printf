/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaazouz <amaazouz@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:11:56 by amaazouz          #+#    #+#             */
/*   Updated: 2025/11/05 23:27:07 by amaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*print(const char *str, ...)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		while(str[i] != '%' && str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		if (str[i] == '%' && str[i + 1] != '%')
			i++;
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			i++;
			while (str[i] == '%' && str[i])
			{
				write(1, &str[i], 1);
				i++;
			}
		}
	}
}

int	arg_count(const char *str, ...)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == '%' && str[i + 1] == '%')
			i++;
		if (str[i] == '%' && str[i - 1] != '%')
			count++;
		i++;
	}
	return (count);
}	

int	main(void)
{
	print("je test %%% la %s de %d ne finira %s jamais");
	return (0);
}
