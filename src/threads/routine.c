/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c <jalves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:46:22 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/11 16:46:23 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(int id, char *color, char *msg)
{
	pthread_mutex_lock(&(host()->mutex));
	if (host()->dinning == true)
		printf("%lu%s %d "RESET"%s\n", get_time(), color, id, msg);
	pthread_mutex_unlock(&(host()->mutex));
}

void	lonely_dinner(void)
{
	t_node		*node;
	uint64_t	start_time;

	node = host()->head;
	start_time = get_current_time();
	pthread_mutex_lock(&node->next->u_data.fork.mutex);
	message(node->u_data.philo.id, YELLOW, "has taken a fork");
	while (get_current_time() - start_time < host()->time_to_die)
		ft_sleep(1);
	pthread_mutex_lock(&node->u_data.philo.mutex);
	node->u_data.philo.state = DEAD;
	message(node->u_data.philo.id, RED, "died");
	pthread_mutex_unlock(&node->u_data.philo.mutex);
	pthread_mutex_unlock(&node->next->u_data.fork.mutex);
}

bool	am_i_alive(void)
{
	pthread_mutex_lock(&(host()->mutex));
	if (host()->dinning == false)
	{
		pthread_mutex_unlock(&(host()->mutex));
		return (false);
	}
	pthread_mutex_unlock(&(host()->mutex));
	return (true);
}

bool	am_i_hungry(t_node *node)
{
	pthread_mutex_lock(&node->u_data.philo.mutex);
	if (host()->meal_limit && \
	host()->max_meals == node->u_data.philo.meal_count)
	{
		pthread_mutex_unlock(&node->u_data.philo.mutex);
		return (false);
	}
	pthread_mutex_unlock(&node->u_data.philo.mutex);
	return (true);
}

void	*routine(void	*arg)
{
	t_node	*node;

	node = (t_node *)arg;
	if (host()->philosopher_count == 1)
	{
		lonely_dinner();
		return (NULL);
	}
	if (node->u_data.philo.id % 2 == 0)
		usleep(100);
	while (true)
	{
		if (!am_i_alive() || !am_i_hungry(node))
			break ;
		devour(node);
		nap(node);
		contemplate(node);
	}
	pthread_mutex_lock(&node->u_data.philo.mutex);
	node->u_data.philo.state = FULL;
	pthread_mutex_unlock(&node->u_data.philo.mutex);
	return (NULL);
}
