/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:15:19 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/10 19:05:04 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_swap(pthread_mutex_t **a, pthread_mutex_t **b) 
{
    pthread_mutex_t *tmp = *a;
    *a = *b;
    *b = tmp;
}


void devour(t_node *node) 
{
    pthread_mutex_t *first = &node->prev->u_data.fork.mutex;
    pthread_mutex_t *second = &node->next->u_data.fork.mutex;

    pthread_mutex_lock(&node->u_data.philo.mutex);
    if (!(node->u_data.philo.id % 2))
        ft_swap(&first, &second);
    pthread_mutex_lock(first);
    message(node->u_data.philo.id, YELLOW, "has taken a fork");
    pthread_mutex_lock(second);
    message(node->u_data.philo.id, YELLOW, "has taken a fork");
	node->u_data.philo.last_meal = get_current_time();
	node->u_data.philo.state = EAT;
	node->u_data.philo.meal_count++;
	message(node->u_data.philo.id, GREEN, "is eating");
	ft_sleep(host()->time_to_eat);
	pthread_mutex_unlock(second);
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(&node->u_data.philo.mutex);
}

void	nap(t_node	*node)
{
	pthread_mutex_lock(&node->u_data.philo.mutex);
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