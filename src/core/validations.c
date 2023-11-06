/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:30:35 by jalves-c          #+#    #+#             */
/*   Updated: 2023/11/06 13:40:51 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	arguments_are_within_integer_positive_range(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if ((long_atoi(av[i]) > INT_MAX || long_atoi(av[i]) <= 0))
			return (false);
		i++;
	}
	return (true);
}

bool	arguments_are_numbers(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '+' || av[i][j] == '-')
		{
			j++;
			if (av[i][j] == '\0')
				return (false);
		}
		while (av[i][j] != '\0')
		{
			if (!ft_isdigit(av[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	assign_host(int ac, char **av)
{
	host()->philosopher_count = ft_atoi(av[0]);
	host()->time_to_die = ft_atoi(av[1]);
	host()->time_to_eat = ft_atoi(av[2]);
	host()->time_to_sleep = ft_atoi(av[3]);
	if (ac == 5)
		host()->max_meals = ft_atoi(av[4]);
	host()-> head = NULL;
	host()->node_count = host()->philosopher_count * 2;
	host()->start_time = get_current_time();
}

bool	argument_check(int ac, char **av)
{
	if (ac == 6 || ac == 5)
	{
		av++;
		ac--;
		if (arguments_are_numbers(ac, av) == false)
		{
			put_error(ARGUMENTS_NOT_NUMBERS);
			return (false);
		}
		if (arguments_are_within_integer_positive_range(ac, av) == false)
		{
			put_error(ARGUMENTS_NOT_POSITIVE_INTEGER);
			return (false);
		}
		if (ft_atoi(av[0]) > MAX_PHILO)
		{
			put_error(PHILO_VALUE_TOO_BIG);
			return (false);
		}
		assign_host(ac, av);
		return (true);
	}
	put_error(WRONG_ARGUMENTS);
	return (false);
}