/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baby_sitting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:22:38 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/05 19:36:12 by jalves-c         ###   ########.fr       */
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

bool is_all_full(void) {
    t_node *node;
    unsigned int full_philo = 0;

    node = host()->head;
    while (node) {
        if (node->type == PHILO) {
            pthread_mutex_lock(&node->u_data.philo.mutex);
            if (node->u_data.philo.state == FULL) {
                full_philo++;
            }
            pthread_mutex_unlock(&node->u_data.philo.mutex);
        }
        node = node->next;
    }
    return (full_philo == host()->philosopher_count);
}


void baby_sitting(void) {
    if (host()->philosopher_count == 1) {
        return;
    }

    while (!is_all_full()) {
        // Do nothing, just wait
    }
}
