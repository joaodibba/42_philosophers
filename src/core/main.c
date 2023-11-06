/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:15:46 by jalves-c          #+#    #+#             */
/*   Updated: 2023/11/06 13:40:33 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if (argument_check(ac, av) == false) // make this not return
		return (1);
	dinner_time();
	wash_the_dishes();
	goodbye();
}
// print_list(host()->head);
