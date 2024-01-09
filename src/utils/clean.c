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
	int i = 1;
	bool	status = true;
	
	current = host->head;
	while (current)
	{
		printf(RED"this is the %d time\n"RESET, i++);
		if (current->type == PHILO)
		{
			if (pthread_mutex_destroy(&current->u_data.philo.mutex) != 0)
				status = false;
		}
		else if (current->type == FORK)
		{
			if (pthread_mutex_destroy(&current->u_data.fork.mutex) != 0)
				status = false;
		}
		current = current->next;
		if (current == host->head)
			break ;
	}
	if (pthread_mutex_destroy(&host->mutex) != 0)
				status = false;
	return (status);
}
/*
==52130== ---Thread-Announcement------------------------------------------
==52130== 
==52130== Thread #1 is the program's root thread
==52130== 
==52130== ----------------------------------------------------------------
==52130== 
==52130== Thread #1's call to pthread_mutex_destroy failed
==52130==    with error code 16 (EBUSY: Device or resource busy)
==52130==    at 0x4850B43: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-amd64-linux.so)
==52130==    by 0x4021F7: wash_the_dishes (clean.c:32)
==52130==    by 0x401269: main (main.c:23)
==52130== 
*/
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