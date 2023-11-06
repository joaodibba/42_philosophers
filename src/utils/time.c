/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 23:46:59 by jalves-c          #+#    #+#             */
/*   Updated: 2023/11/06 13:41:17 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

u_int64_t	get_time(void)
{
	return (get_current_time() - host()->start_time);
}

u_int64_t	get_current_time(void)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) < 0)
	{
		// get time of day error deal with it
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_sleep(uint64_t time_to_sleep)
{
	uint64_t	sleep_start;

	sleep_start = get_current_time();
	while ((get_current_time() - sleep_start) < time_to_sleep)
		usleep(500);
}