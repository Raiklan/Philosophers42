/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:11:23 by saich             #+#    #+#             */
/*   Updated: 2022/01/09 17:12:06 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	print_status(get_tstamp(philo->time.start), philo->id, "is sleeping", \
		*philo->dead);
	pthread_mutex_unlock(philo->print);
	ft_usleep(philo->par->time_sleep);
	pthread_mutex_lock(philo->print);
	print_status(get_tstamp(philo->time.start), philo->id, "is thinking", \
		*philo->dead);
	pthread_mutex_unlock(philo->print);
}

void	ft_eat2(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	pthread_mutex_lock(philo->print);
	print_status(get_tstamp(philo->time.start), philo->id, "has taken a fork", \
		*philo->dead);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(philo->print);
	print_status(get_tstamp(philo->time.start), philo->id, "is eating", \
		*philo->dead);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(philo->eat_times);
	philo->last_eat = get_time();
	philo->eat_index++;
	pthread_mutex_unlock(philo->eat_times);
	ft_usleep(philo->par->time_eat);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(&philo->left);
}

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left);
	pthread_mutex_lock(philo->print);
	print_status(get_tstamp(philo->time.start), philo->id, "has taken a fork", \
		*philo->dead);
	pthread_mutex_unlock(philo->print);
	if (&philo->left == philo->right)
	{
		*philo->dead = 1;
		pthread_mutex_unlock(&philo->left);
		return (0);
	}
	ft_eat2(philo);
	return (0);
}

int	routine(t_philo *philo)
{
	if (philo->id % 2)
	{
		if (ft_eat_right(philo))
			return (1);
	}
	else if (ft_eat(philo))
		return (1);
	pthread_mutex_lock(philo->eat_times);
	if (philo->stop == 1)
	{
		pthread_mutex_unlock(philo->eat_times);
		return (1);
	}
	pthread_mutex_unlock(philo->eat_times);
	ft_sleep(philo);
	return (0);
}

void	*start_routine(void *par)
{
	t_philo			*philo;
	sig_atomic_t	ded;
	int				times;

	philo = (t_philo *)par;
	ded = 0;
	times = 0;
	if (philo->id % 2)
		ft_usleep(philo->par->time_eat / 2);
	while (ded == 0)
	{
		if (philo->par->n_times_eat == -1 || \
			times < philo->par->n_times_eat)
		{
			if (routine(philo))
				return (NULL);
			times++;
		}
		pthread_mutex_lock(philo->death);
		ded = *philo->dead;
		pthread_mutex_unlock(philo->death);
	}
	return (NULL);
}
