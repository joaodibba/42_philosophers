/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 23:46:59 by jalves-c          #+#    #+#             */
/*   Updated: 2023/10/25 23:48:52 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

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
