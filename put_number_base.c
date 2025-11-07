/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_number_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaazouz <amaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:32:06 by amaazouz          #+#    #+#             */
/*   Updated: 2025/11/07 15:35:21 by amaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	put_number_base(unsigned long int n, char t)
{
	char	*hexa = "0123456789abcdef";
	char	c;
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += put_number_base(n / 16, t);
	}
	if (t == 'p')
	{
		c = hexa[n % 16];
		write (1, &c, 1);
	}
	return (count + 1);
}
