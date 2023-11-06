/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:46:20 by jalves-c          #+#    #+#             */
/*   Updated: 2023/11/06 17:20:23 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_node	*create_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}


void	insert_at_end(t_node	**head)
{
	t_node	*new_node;
	t_node	*tail;

	new_node = create_node();
	if (new_node == NULL)
	{
		// Handle memory allocation failure
	}
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		tail = (*head)->prev;
		if (tail == NULL)
		{
			// handle not tail found
		}
		new_node->next = *head;
		new_node->prev = tail;
		tail->next = new_node;
		(*head)->prev = new_node;
	}
}

void	create_list(void)
{
	unsigned int	node_count;

	node_count = host()->node_count;
	while (node_count-- > 0)
		insert_at_end(&(host()->head));
}

void	initialize_list(void)
{
	unsigned int	i;
	unsigned int	philo_count;
	t_node			*current;

	i = 1;
	philo_count = 1;
	current = host()->head;
	while (i <= host()->node_count)
	{
		if (i % 2 == 0)
			create_fork_node(current, philo_count);
		else
			create_philo_node(current, philo_count++);
		i++;
		current = current->next;
	}
}
