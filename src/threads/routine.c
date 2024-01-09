/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:23:32 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/08 21:25:26 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO: add the host mutex
void	message(int id, char *color, char *msg)
{
	pthread_mutex_lock(&(host()->mutex));
	if (host()->dinning == true)
		printf("%lu%s %d "RESET"%s\n", get_time(), color, id, msg);
	pthread_mutex_lock(&(host()->mutex));
}

void	lonely_dinner(void)
{
	t_node		*node;
	uint64_t	start_time;

	node = host()->head;
	start_time = get_current_time();
	pthread_mutex_lock(&node->next->u_data.fork.mutex);
	message(node->u_data.philo.id, BLUE, "has taken a fork");
	while (get_current_time() - start_time < host()->time_to_die)
		ft_sleep(1);
	node->u_data.philo.state = DEAD;
	message(node->u_data.philo.id, RED, "died");
	pthread_mutex_unlock(&node->next->u_data.fork.mutex);
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
		devour(node);
		nap(node);
		contemplate(node);
	}
	return (NULL);
}