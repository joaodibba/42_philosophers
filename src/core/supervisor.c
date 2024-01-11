/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c <jalves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:45:48 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/11 17:55:08 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_for_philos(t_host *host)
{
	t_node	*current;

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

bool	check_baby(t_host	*host, t_node *node, unsigned int *full_count)
{
	uint64_t		diff;

	if (node->u_data.philo.state == FULL)
		(*full_count)++;
	if (*full_count == host->philosopher_count)
	{
		pthread_mutex_lock(&host->mutex);
		host->dinning = false;
		pthread_mutex_unlock(&host->mutex);
		return (false);
	}
	diff = get_diff(host->start_time, node->u_data.philo.last_meal);
	if (node->u_data.philo.state != FULL && \
		diff >= host->time_to_die)
	{
		message(node->u_data.philo.id, RED, "died");
		pthread_mutex_lock(&host->mutex);
		host->dinning = false;
		pthread_mutex_unlock(&host->mutex);
		node->u_data.philo.state = DEAD;
		return (false);
	}
	return (true);
}

void	baby_sitting(t_host	*host)
{
	unsigned int	full_count;
	t_node			*node;

	node = host->head;
	full_count = 0;
	while (true)
	{
		if (node->type == PHILO)
		{
			pthread_mutex_lock(&node->u_data.philo.mutex);
			if (check_baby(host, node, &full_count) == false)
			{
				pthread_mutex_unlock(&node->u_data.philo.mutex);
				break ;
			}
			pthread_mutex_unlock(&node->u_data.philo.mutex);
		}
		node = node->next;
	}
}
