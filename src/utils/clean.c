/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:07:32 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/08 21:32:17 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	wash_the_dishes(t_host	*host)
{
	t_node	*current;
	bool	status = true;
	
	if (!host || !host->head)
		return (false);
	current = host->head;
	while (current)
	{
		if (current->type == PHILO)
		{
			// pthread_mutex_lock(&current->u_data.philo.mutex);
			// pthread_mutex_unlock(&current->u_data.philo.mutex);
			if (pthread_mutex_destroy(&current->u_data.philo.mutex) != 0)
				status = false;
		}
		else if (current->type == FORK)
		{
			// pthread_mutex_lock(&current->u_data.fork.mutex);
			// pthread_mutex_unlock(&current->u_data.fork.mutex);
			if (pthread_mutex_destroy(&current->u_data.fork.mutex) != 0)
				status = false;
		}
		current = current->next;
		if (current == host->head)
			break ;
	}
	// pthread_mutex_lock(&host->mutex);
	// pthread_mutex_unlock(&host->mutex);
	if (pthread_mutex_destroy(&host->mutex) != 0)
		status = false;
	return (status);
}

bool goodbye(t_host *host)
{
    t_node *next_node;
    t_node *current_node;

    if (!host->head || !host->head->next)
        return (false);
    current_node = host->head->next;
    while (current_node && current_node != host->head)
    {
        next_node = current_node->next;
		if (current_node)
       		free(current_node);
		current_node = next_node;
    }
	free(host->head);
	host->head = NULL;
	return (true);
}