/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c <jalves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:46:04 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/11 16:46:05 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_fork_node(t_node *node, unsigned	int owner)
{
	node->type = FORK;
	node->u_data.fork.state = FREE;
	node->u_data.fork.owner = owner;
	if (pthread_mutex_init(&node->u_data.fork.mutex, NULL) != 0)
		return (1);
	return (0);
}

int	create_philo_node(t_node *node, unsigned int id)
{
	node->type = PHILO;
	node->u_data.philo.meal_count = 0;
	node->u_data.philo.last_meal = 0;
	node->u_data.philo.id = id;
	node->u_data.philo.state = THINK;
	if (pthread_mutex_init(&node->u_data.philo.mutex, NULL) != 0)
		return (1);
	if (pthread_create(&node->u_data.philo.thread, \
	NULL, &routine, (void *)node) != 0)
		return (1);
	return (0);
}

int	initialize_fork_list(t_host	*host)
{
	unsigned int	i;
	unsigned int	philo_count;
	t_node			*current;

	i = 1;
	philo_count = 1;
	current = host->head;
	while (i <= host->node_count)
	{
		if (i % 2 == 0)
		{
			if (create_fork_node(current, philo_count++) == 1)
				return (1);
		}
		i++;
		current = current->next;
	}
	return (0);
}

int	initialize_philo_list(t_host	*host)
{
	unsigned int	i;
	unsigned int	philo_count;
	t_node			*current;

	i = 1;
	philo_count = 1;
	current = host->head;
	while (i <= host->node_count)
	{
		if (i % 2 != 0)
		{
			if (create_philo_node(current, philo_count++) == 1)
				return (1);
		}
		i++;
		current = current->next;
	}
	return (0);
}

bool	initialize_list(t_host	*host)
{
	if (pthread_mutex_init(&host->mutex, NULL) != 0)
		return (false);
	if (initialize_fork_list(host) != 0)
		return (false);
	if (initialize_philo_list(host) != 0)
		return (false);
	return (true);
}
