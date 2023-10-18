/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:30:35 by jalves-c          #+#    #+#             */
/*   Updated: 2023/10/18 21:48:52 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

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
