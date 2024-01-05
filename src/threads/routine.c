/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:15:19 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/04 21:02:40 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	devour(t_node	*node)
{
	pthread_mutex_lock(&node->next->u_data.fork.mutex);
	printf("%llu"YELLOW" %d"RESET" has taken a fork\n", get_time(), node->u_data.philo.id);
	pthread_mutex_lock(&node->prev->u_data.fork.mutex);
	printf("%llu"YELLOW" %d"RESET" has taken a fork\n", get_time(), node->u_data.philo.id);
	pthread_mutex_lock(&node->u_data.philo.mutex);
	printf("%llu"GREEN" %d"RESET" is eating\n", get_time(), node->u_data.philo.id);
	node->u_data.philo.last_meal = get_current_time();
	// printf(GREEN"%d"RESET"  last meal time : %llu\n", node->u_data.philo.id, node->u_data.philo.last_meal);
	node->u_data.philo.state = EAT;
	node->u_data.philo.meal_count++;
	pthread_mutex_unlock(&node->u_data.philo.mutex);
	ft_sleep(host()->time_to_eat);
	pthread_mutex_unlock(&node->next->u_data.fork.mutex);
	pthread_mutex_unlock(&node->prev->u_data.fork.mutex);
}

void	nap(t_node	*node)
{
	pthread_mutex_lock(&node->u_data.philo.mutex);
	printf("%llu"BLUE" %d"RESET" is sleeping\n", get_time(), node->u_data.philo.id);
	node->u_data.philo.state = SLEEP;
	pthread_mutex_unlock(&node->u_data.philo.mutex);
	ft_sleep(host()->time_to_sleep);
}

void	contemplate(t_node	*node)
{
	pthread_mutex_lock(&node->u_data.philo.mutex);
	printf("%llu"PURPLE" %d"RESET" is thinking\n", get_time(), node->u_data.philo.id);
	node->u_data.philo.state = THINK;
	pthread_mutex_unlock(&node->u_data.philo.mutex);
}