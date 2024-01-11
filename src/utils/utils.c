/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:31:59 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/08 21:24:17 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_abs(int n)
{
	if (n > 0)
		return (n);
	return(-n);
}

t_host	*host(void)
{
	static t_host	host;

	return (&host);
}

int	ft_isdigit(int x)
{
	if (x >= 48 && x <= 57)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	size_t	res;
	size_t	i;
	size_t	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+' )
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}

long int	long_atoi(const char *str)
{
	size_t	res;
	size_t	i;
	size_t	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+' )
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}

void	print_list(t_node *head)
{
	t_node			*current_node;
	unsigned int	i;

	i = 0;
	current_node = head;
	while (head != NULL && i++ < host()->node_count)
	{
		printf("_____________________________________\n");
		printf("Node: %d\n", i);
		if (current_node->type == FORK)
		{
			printf(RED"Prev Node Address: %p | Type %d | State: %d\n" \
			RESET, current_node->prev, current_node->prev->type, \
			current_node->prev->u_data.philo.state);
			printf("Current Node Address: %p | Type %d | State: %d\n", \
			current_node, current_node->type, \
			current_node->u_data.fork.state);
			printf("Current Node Mutex: %p\n", &current_node->u_data.fork.mutex);
			printf(BLUE"Next Node Address: %p | Type %d | State: %d\n" \
			RESET, current_node->next, current_node->next->type, \
			current_node->next->u_data.philo.state);
		}
		else if (current_node->type == PHILO)
		{
			printf(RED"Prev Node Address: %p | Type %d | State: %d\n" \
			RESET, current_node->prev, current_node->prev->type, \
			current_node->prev->u_data.fork.state);
			printf("Current Node Address: %p | Type %d | State: %d\n", \
			current_node, current_node->type, \
			current_node->u_data.philo.state);
			printf("Current Node Mutex: %p\n", &current_node->u_data.philo.mutex);
			printf(BLUE"Next Node Address: %p | Type %d | State: %d\n" \
			RESET, current_node->next, current_node->next->type, \
			current_node->next->u_data.fork.state);
		}
		printf("_____________________________________\n");
		current_node = current_node->next;
	}
}