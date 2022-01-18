/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:11:23 by saich             #+#    #+#             */
/*   Updated: 2022/01/09 17:12:06 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(long int timestamp, int id, char *str, int dead)
{
	int	i;

	i = 0;
	if (dead == 1)
		return ;
	printf("%ld %u %s\n", timestamp, id + 1, str);
}
