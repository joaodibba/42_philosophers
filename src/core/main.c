/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c <jalves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:45:37 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/11 16:45:40 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if (argument_check(ac, av) && create_list(host()) && \
		initialize_list(host()))
	{
		baby_sitting(host());
		wait_for_philos(host());
	}
	if (!wash_the_dishes(host()) || !goodbye(host()))
		return (1);
	return (0);
}
