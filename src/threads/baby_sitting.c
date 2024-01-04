/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baby_sitting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:22:38 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/04 16:15:05 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_diff(uint64_t start, uint64_t last)
{
	if (last > 0)
		return (get_current_time() - last);
	return (get_current_time() - start);
}

bool	check_if_baby_is_alive(t_node *node)
{
	uint64_t diff = get_diff(host()->start_time, node->u_data.philo.last_meal);
	if (node->u_data.philo.state != EAT && diff >= host()->time_to_die)
	{
		node->u_data.philo.state = DEAD;
		printf("%lu"RED" %d"RESET" died\n", get_time(),  node->u_data.philo.id);
		// 
		// printf(RED"%d"RESET" - last_meal: %lu\n",philo->id, get_current_time() - philo->last_meal);
		// TODO: free shit before
		exit(1); // TODO: REMOVE THIS
	}
	return (true);
}

void	check_if_baby_is_full(t_node *node)
{
	if (host()->max_meals > 0 && node->u_data.philo.meal_count == host()->max_meals)
	{
		node->u_data.philo.state = FULL;
		if (host()->max_meals)
		{	
			host()->max_meals--;
			if (host()->max_meals == 0)
			{
				printf("something mf %d\n", host()->max_meals);
				return ;
			}
		}		
		// printf("something mf %d\n", node->u_data.philo.state);
	}
}

void	baby_sitting(void)
{
	t_node *node;

	node = host()->head;
	while (node)
	{
		if (node->type == PHILO && node->u_data.philo.state != FULL)
		{
			pthread_mutex_lock(&node->u_data.philo.mutex);
			check_if_baby_is_alive(node);
			check_if_baby_is_full(node);
			// printf(RED"%d"RESET" - state: %d\n",node->u_data.philo.id , node->u_data.philo.state);
			pthread_mutex_unlock(&node->u_data.philo.mutex);
		}
		node = node->next;
	}
	printf(RED"narroyzplayja\n"RESET);	
}