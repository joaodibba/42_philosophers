/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 23:46:59 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/08 20:49:34 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


uint64_t	get_current_time(void)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) < 0)
	{
		return (0);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

uint64_t	get_time(void)
{
	return (get_current_time() - host()->start_time);
}

void	ft_sleep(uint64_t time_to_sleep)
{
	uint64_t	sleep_start;

	sleep_start = get_current_time();
	while ((get_current_time() - sleep_start) < time_to_sleep)
		usleep(500);
}