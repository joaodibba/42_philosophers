/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:15:46 by jalves-c          #+#    #+#             */
/*   Updated: 2023/10/19 20:28:02 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	assign_data(int ac, char **av)
{
	data()->philosopher_count = ft_atoi(av[0]);
	data()->time_to_die = ft_atoi(av[1]);
	data()->time_to_eat = ft_atoi(av[2]);
	data()->time_to_sleep = ft_atoi(av[3]);
	if (ac == 5)
		data()->meal_count = ft_atoi(av[4]);
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
		assign_data(ac, av);
		return (true);
	}
	put_error(WRONG_ARGUMENTS);
	return (false);
}

int	main(int ac, char **av)
{
	if (argument_check(ac, av) == false)
		return (1);
	return (0);
}
