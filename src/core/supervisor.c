/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:49:26 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/08 19:35:35 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_for_philos(t_host *host)
{
	t_node *current;

	current = host->head;
	while (current)
	{
		if (current->type == PHILO)
			pthread_join(current->u_data.philo.thread, NULL);
		current = current->next;
		if (current == host->head)
			break ;
	}
}

uint64_t	get_diff(uint64_t start, uint64_t last)
{
	if (last > 0)
		return (get_current_time() - last);
	return (get_current_time() - start);
}

void	baby_sitting(t_host	*host)
{
	t_node *node;
	uint64_t diff;

	node = host->head;
	while (true)
	{
		if (node->type == PHILO)
		{
			pthread_mutex_lock(&node->u_data.philo.mutex);
			diff = get_diff(host->start_time, node->u_data.philo.last_meal);
			if (node->u_data.philo.state != EAT && diff >= host->time_to_die)
			{
				message(node->u_data.philo.id, RED, "died");
				pthread_mutex_lock(&host->mutex);
				host->dinning = false;
				pthread_mutex_unlock(&host->mutex);
				node->u_data.philo.state = DEAD;
				pthread_mutex_unlock(&node->u_data.philo.mutex);
				return ;
			}
			pthread_mutex_unlock(&node->u_data.philo.mutex);
		}
		node = node->next;
	}
	return ;
}