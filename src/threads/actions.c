/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:15:19 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/09 20:23:03 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	devour(t_node	*node)
{
	pthread_mutex_lock(&node->prev->u_data.fork.mutex);
	message(node->u_data.philo.id, YELLOW, "has taken a fork");
	pthread_mutex_lock(&node->next->u_data.fork.mutex);
	message(node->u_data.philo.id, YELLOW, "has taken a fork");
	pthread_mutex_lock(&node->u_data.philo.mutex);
	node->u_data.philo.last_meal = get_current_time();
	node->u_data.philo.state = EAT;
	node->u_data.philo.meal_count++;
	message(node->u_data.philo.id, GREEN, "is eating");
	ft_sleep(host()->time_to_eat);
	pthread_mutex_unlock(&node->u_data.philo.mutex);
	pthread_mutex_unlock(&node->next->u_data.fork.mutex);
	pthread_mutex_unlock(&node->prev->u_data.fork.mutex);
}

void	nap(t_node	*node)
{
	pthread_mutex_lock(&(node->u_data.philo.mutex));
	node->u_data.philo.state = SLEEP;
	message(node->u_data.philo.id, BLUE, "is sleeping");
	ft_sleep(host()->time_to_sleep);
	pthread_mutex_unlock(&node->u_data.philo.mutex);
}

void	contemplate(t_node	*node)
{
	pthread_mutex_lock(&node->u_data.philo.mutex);
	node->u_data.philo.state = THINK;
	message(node->u_data.philo.id, PURPLE, "is thinking");
	pthread_mutex_unlock(&node->u_data.philo.mutex);
}