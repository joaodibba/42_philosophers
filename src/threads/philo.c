/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:23:32 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/03 19:09:11 by jalves-c         ###   ########.fr       */
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
}
bool	is_full(t_node	*node)
{
	pthread_mutex_lock(&node->u_data.philo.mutex);
	// printf("%d -> status: %d -> meals: %d\n", node->u_data.philo.id, node->u_data.philo.state, node->u_data.philo.meal_count);
	if (node->u_data.philo.state == FULL)
	{
		pthread_mutex_unlock(&node->u_data.philo.mutex);
		return (true);
	}
	pthread_mutex_unlock(&node->u_data.philo.mutex);
	return (false);
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
		ft_sleep(30); // fix this shit
	while (true)
	{
		if (is_full(node) == true)
			break ;
		devour(node);
		if (is_full(node) == true)
			break ;
		nap(node);
		if (is_full(node) == true)
			break ;
		contemplate(node);
	} // constantly check if the state shouldnt be dead
	return (NULL);
}

// printf("id: %d | thread %d | meal_count: %d | state %d \n", node->u_data.philo.id, node->u_data.philo.thread, node->u_data.philo.meal_count, node->u_data.philo.state);