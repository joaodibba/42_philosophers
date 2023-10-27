/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 01:59:33 by jalves-c          #+#    #+#             */
/*   Updated: 2023/10/23 13:55:45 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

typedef struct s_host
{
	int				value;
	pthread_mutex_t	mutex;
}		t_host;

// Function to perform an operation on the shared host
void	*modify_host(void *arg)
{
	t_host	*host;

	host = (t_host *)arg;
	pthread_mutex_lock(&host->mutex);
	host->value += 10;
	printf("Modified host to: %d\n", host->value);
	pthread_mutex_unlock(&host->mutex);
	return (NULL);
}

int	main(void)
{
	pthread_t		threads[2];
	static t_host	host;
	int				i;

	i = 0;
	pthread_mutex_init(&host.mutex, NULL);
	while (i < 2)
		pthread_create(&threads[i++], NULL, modify_host, &host);
	i = 0;
	while (i < 2)
		pthread_join(threads[i++], NULL);
	printf("Final host value: %d\n", host.value);
	pthread_mutex_destroy(&host.mutex);
	return (0);
}
