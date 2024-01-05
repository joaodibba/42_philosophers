/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baby_sitting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:22:38 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/05 17:17:02 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_if_baby_is_full(t_node *node)
{
	pthread_mutex_lock(&node->u_data.philo.mutex);
	if (node->u_data.philo.meal_count == host()->max_meals)
		node->u_data.philo.state = FULL;
	pthread_mutex_unlock(&node->u_data.philo.mutex);
}

bool	is_all_full(void)
{
	t_node	*node;
	bool	all_full;

	all_full = true;
	node = host()->head;
	while (node)
	{
		pthread_mutex_lock(&node->u_data.philo.mutex);
		if (node->type == PHILO && node->u_data.philo.state != FULL)
		{
			all_full = false;
			pthread_mutex_unlock(&node->u_data.philo.mutex);
			break ;
		}
		pthread_mutex_unlock(&node->u_data.philo.mutex);
		node = node->next;
		if (node == host()->head)
			break ;
	}
	return (all_full);
}

void	baby_sitting(void)
{
	t_node *node;

	node = host()->head;
	if (host()->philosopher_count == 1)
		return ;
	while (is_all_full() == false)
	{
		// check_if_baby_is_alive(node);
		check_if_baby_is_full(node);
		// printf(RED"%d"RESET" - state: %d\n",node->u_data.philo.id , node->u_data.philo.state);
		pthread_mutex_unlock(&node->u_data.philo.mutex);
		node = node->next;
	}
}