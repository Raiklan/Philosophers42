/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:11:23 by saich             #+#    #+#             */
/*   Updated: 2022/01/09 17:12:06 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free(t_all *all)
{
	if (all && all->p)
		free(all->p);
	if (all)
		free(all);
	return (1);
}

int	error_message(char *str)
{
	printf("%s\n", str);
	return (1);
}

int	main(int argc, char **argv)
{
	t_params	par;

	par.n_times_eat = 0;
	if (argc < 5 || argc > 6)
		return (error_message("Error\nWrong number of arguments"));
	if (parser(argc, argv, &par))
		return (error_message("Error\nWrong arguments"));
	if (philosophers(&par))
		return (error_message("Error\nSomething went wrong during execution"));
}
