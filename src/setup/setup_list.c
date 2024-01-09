/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:46:20 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/08 21:05:15 by jalves-c         ###   ########.fr       */
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

int	insert_at_end(t_node	**head)
{
	t_node	*new_node;
	t_node	*tail;

	new_node = create_node();
	if (new_node == NULL)
		return (1);
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
			return (1);
		new_node->next = *head;
		new_node->prev = tail;
		tail->next = new_node;
		(*head)->prev = new_node;
	}
	return (0);
}

bool	create_list(t_host	*host)
{
	unsigned int	node_count;

	node_count = host->node_count;
	while (node_count-- > 0)
	{
		if (insert_at_end(&host->head) != 0)
			return (false);
	}
	return (true);
}