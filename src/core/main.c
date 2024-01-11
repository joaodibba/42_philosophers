/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:15:46 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/09 16:20:29 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if (argument_check(ac, av) && create_list(host()) && initialize_list(host()))
	{
		baby_sitting(host());
		wait_for_philos(host());
	}
	if (!wash_the_dishes(host()) || !goodbye(host()))
		return (1);
	return (0);
}