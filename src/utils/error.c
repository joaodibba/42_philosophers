/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:19:04 by jalves-c          #+#    #+#             */
/*   Updated: 2023/11/06 13:41:14 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	put_error(int errno)
{
	ft_putstr_fd(RED, STDOUT);
	ft_putstr_fd("ERROR: ", STDOUT);
	ft_putstr_fd(RESET, STDOUT);
	if (errno == WRONG_ARGUMENTS)
	{
		ft_putstr_fd("./philo <number_of_philosophers> <time_to_die> ", STDOUT);
		ft_putstr_fd("<time_to_eat> <time_to_sleep> ", STDOUT);
		ft_putendl_fd("[number_of_times_each_philosopher_must_eat]", STDOUT);
	}
	else if (errno == ARGUMENTS_NOT_NUMBERS)
		ft_putendl_fd("ARGUMENTS MUST BE NUMBERS", STDOUT);
	else if (errno == ARGUMENTS_NOT_POSITIVE_INTEGER)
		ft_putendl_fd("ARGUMENTS MUST BE POSITIVE INTEGERS", STDOUT);
	else if (errno == PHILO_VALUE_TOO_BIG)
		ft_putendl_fd("<number_of_philosophers> SHOULDN'T BE MORE THAN 200", \
		STDOUT);
}
