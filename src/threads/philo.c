/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:23:32 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/05 19:19:11 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lonely_dinner(void)
{
	t_node		*node;
	uint64_t	start_time;

	node = host()->head;
	start_time = get_current_time();
	pthread_mutex_lock(&node->next->u_data.fork.mutex);
	printf("%lu"YELLOW" %d"RESET" has taken a fork\n", get_time(), node->u_data.philo.id);
	while (get_current_time() - start_time < host()->time_to_die)
		ft_sleep(1);
	node->u_data.philo.state = DEAD;
	printf("%lu"RED" %d"RESET" died\n", get_time(),  node->u_data.philo.id);
	pthread_mutex_unlock(&node->next->u_data.fork.mutex);
}
bool	is_full(t_node	*node)
{
	pthread_mutex_lock(&node->u_data.philo.mutex);
	if (host()->max_meals != 0 &&  host()->max_meals == node->u_data.philo.meal_count)
	{
		node->u_data.philo.state = FULL;
		pthread_mutex_unlock(&node->u_data.philo.mutex);
		return (true);
	}
	pthread_mutex_unlock(&node->u_data.philo.mutex);
	return (false);
}

uint64_t	get_diff(uint64_t start, uint64_t last)
{
	if (last > 0)
		return (get_current_time() - last);
	return (get_current_time() - start);
}

bool	is_alive(t_node	*node)
{
	uint64_t diff;

	if (node->type == PHILO)
	{
		pthread_mutex_lock(&node->u_data.philo.mutex);
		diff = get_diff(host()->start_time, node->u_data.philo.last_meal);
		printf(RED"%d philo id | %lu diff\n"RESET, node->u_data.philo.id, diff);
		if (node->u_data.philo.state != EAT && diff >= host()->time_to_die)
		{
			node->u_data.philo.state = DEAD;
			printf("%lu"RED" %d"RESET" died\n", get_time(),  node->u_data.philo.id);
			pthread_mutex_unlock(&node->u_data.philo.mutex);
			return (false);
		}
		pthread_mutex_unlock(&node->u_data.philo.mutex);
	}
	return (true);
}

void	*routine(void	*arg)
{
	t_node	*node;

	node = (t_node *)arg;
	if (host()->philosopher_count == 1)
	{
		lonely_dinner();
		return (NULL);
	}
	if (node->u_data.philo.id % 2 == 0)
		ft_sleep(10);
	while (true)
	{
		if (is_full(node) == true || is_alive(node) == false)
			break ;
		devour(node);
		nap(node);
		contemplate(node);
	}
	return (NULL);
}