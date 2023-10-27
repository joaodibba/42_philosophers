/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:07:32 by jalves-c          #+#    #+#             */
/*   Updated: 2023/10/26 18:44:52 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	wash_the_dishes(void)
{
	t_node	*current;

	current = host()->head;
	while (current)
	{
		if (current->type == FORK)
			pthread_mutex_destroy(&current->u_data.fork.mutex);
		current = current->next;
		if (current == host()->head)
			break ;
	}
}

void	goodbye(void)
{
	t_node			*next_node;
	t_node			*current_node;

	current_node = host()->head;
	while (host()->head && current_node != host()->head)
	{
		next_node = current_node->next;
        free(current_node);
        current_node = next_node;
	}
	host()->head = NULL;
}
