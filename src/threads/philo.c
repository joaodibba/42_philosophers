/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:23:32 by jalves-c          #+#    #+#             */
/*   Updated: 2023/10/27 15:46:31 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

// TODO: change long long to long

void	nap_time(uint64_t time)
{
	uint64_t	nap_start;

	nap_start = get_current_time();
	while (true)
	{
		if ((get_current_time() - nap_start) >= time)
			return ;
		usleep(1);
	}
}

void	devour(t_node	*node)
{
	pthread_mutex_lock(&node->next->u_data.fork.mutex);
	printf("%llu"YELLOW" %d"RESET" has taken a fork\n", get_time(), node->u_data.philo.id);
	pthread_mutex_lock(&node->prev->u_data.fork.mutex);
	printf("%llu"YELLOW" %d"RESET" has taken a fork\n", get_time(), node->u_data.philo.id);
	node->u_data.philo.last_meal = get_current_time();
	node->u_data.philo.state = EAT;
	node->u_data.philo.meal_count++;
	printf("%llu"GREEN" %d"RESET" is eating\n", get_time(), node->u_data.philo.id);
	nap_time(host()->time_to_eat);
	pthread_mutex_unlock(&node->next->u_data.fork.mutex);
	pthread_mutex_unlock(&node->prev->u_data.fork.mutex);
}

void	nap(t_node	*node)
{
	printf("%llu"BLUE" %d"RESET" is sleeping\n", get_time(), node->u_data.philo.id);
	nap_time(host()->time_to_sleep);
}

void	contemplate(t_node	*node)
{
	printf("%llu"PURPLE" %d"RESET" is thinking\n", get_time(), node->u_data.philo.id);
}

bool	is_dinner_finished(t_node *node)
{
	if (host()->max_meals != 0 && (node->u_data.philo.meal_count == host()->max_meals))
		return (true);
	return (false);
}

void	lonely_dinner(void)
{
	t_node		*node;
	uint64_t	start_time;

	node = host()->head;
	start_time = get_current_time();
	pthread_mutex_lock(&node->next->u_data.fork.mutex);
	printf("%llu"YELLOW" %d"RESET" has taken a fork\n", get_time(), node->u_data.philo.id);
	while (get_current_time() - start_time < host()->time_to_eat)
		nap_time(1);
	node->u_data.philo.state = DEAD;
	printf("%llu"RED" %d"RESET" died\n", get_time(), node->u_data.philo.id);
}
void	*routine(void	*arg)
{
	t_node	*node;

	node = (t_node *)arg;
	if (host()->philosopher_count == 1)
	{
		lonely_dinner();
		return ((void *)node); // NOT SURE WHAT TO RETURN ON THIS BULSHIT
	}
	while (1)
	{
		if (is_dinner_finished(node) == true)
			break ;
		if (node->u_data.philo.id % 2 == 0)
			nap_time(host()->time_to_eat + 1);
		devour(node);
		nap(node);
		contemplate(node);
	} // constantly check if the state shouldnt be dead
	return ((void *)node);
}

// printf("id: %d | thread %d | meal_count: %d | state %d \n", node->u_data.philo.id, node->u_data.philo.thread, node->u_data.philo.meal_count, node->u_data.philo.state);