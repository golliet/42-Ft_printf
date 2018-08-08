/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <golliet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 13:34:28 by golliet           #+#    #+#             */
/*   Updated: 2018/08/06 14:09:59 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long		ft_iterative_power(long long nb, long long power)
{
	long long temp;

	temp = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (power > 1)
	{
		nb *= temp;
		power--;
	}
	return (nb);
}
