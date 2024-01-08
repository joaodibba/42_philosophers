/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:07:32 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/08 20:45:35 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	wash_the_dishes(t_host	*host)
{
	t_node	*current;
	bool	status = true;
	
	current = host->head;
	while (current)
	{
		if (current->type == FORK)
		{
			if (pthread_mutex_destroy(&current->u_data.fork.mutex) != 0)
				status = false;
		}
		else if (current->type == PHILO)
		{
			if (pthread_mutex_destroy(&current->u_data.philo.mutex) != 0)
				status = false;
		}
		current = current->next;
		if (current == host->head)
			break ;
	}
	return (status);
}

bool goodbye(t_host *host)
{
    t_node *next_node;
    t_node *current_node;

    if (!host || !host->head)
        return (false);
    current_node = host->head;
    while (current_node)
    {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    host->head = NULL;
    return (true);
}
