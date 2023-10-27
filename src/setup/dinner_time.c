/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:36:09 by jalves-c          #+#    #+#             */
/*   Updated: 2023/10/27 15:12:09 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	create_fork_node(t_node *node, unsigned	int owner)
{
	node->type = FORK;
	node->u_data.fork.state = FREE;
	node->u_data.fork.owner = owner;
	if (pthread_mutex_init(&node->u_data.fork.mutex, NULL) != 0)
	{
		// creation of fork failed, deal with it
		// put_error
		// exit the program
	}
}

void	create_philo_node(t_node *node, unsigned int id)
{
	node->type = PHILO;
	node->u_data.philo.meal_count = 0;
	node->u_data.philo.last_meal = 0;
	node->u_data.philo.id = id;
	node->u_data.philo.state = THINK;
	if (pthread_create(&node->u_data.philo.thread, NULL, &routine, (void *)node) != 0)
	{
		// creation of thread failed, deal with it
		// put_error
		// exit the program
	}

}


void	wait_for_guests(void)
{
	t_node *current;

	current = host()->head;
	while (current)
	{
		if (current->type == PHILO)
		{
			pthread_join(current->u_data.philo.thread, NULL);
			// // if (pthread_join(current->u_data.philo.thread, NULL) != 0)
				// deu merda aqui
		}
		current = current->next;
		if (current == host()->head)
			break ;
	}
}

void	monitor_guests(void)
{
	t_node *node;

	node = host()->head;
	while (node)
	{
		if (node->type == PHILO)
		{
			if (node->u_data.philo.last_meal != 0 && (get_current_time() - node->u_data.philo.last_meal >= host()->time_to_die))
			{
				node->u_data.philo.state = DEAD;
				printf("%llu"RED" %d"RESET" died\n", get_time(), node->u_data.philo.id);
				// free shit before
				exit(1);
			}
		}
		node = node->next;
	}
}

void	dinner_time(void)
{
	create_list();
	initialize_list();
	monitor_guests();
	wait_for_guests();
}