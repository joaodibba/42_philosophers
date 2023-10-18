/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:19:04 by jalves-c          #+#    #+#             */
/*   Updated: 2023/10/18 21:53:43 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	put_error(int errno)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(RESET, 2);
	if (errno == WRONG_ARGUMENTS)
	{
		ft_putstr_fd("./philo <number_of_philosophers> <time_to_die> ", 2);
		ft_putstr_fd("<time_to_eat> <time_to_sleep> ", 2);
		ft_putendl_fd("[number_of_times_each_philosopher_must_eat]", 2);
	}
	else if (errno == ARGUMENTS_NOT_NUMBERS)
		ft_putendl_fd("ARGUMENTS MUST BE NUMBERS", 2);
	else if (errno == ARGUMENTS_NOT_POSITIVE_INTEGER)
		ft_putendl_fd("ARGUMENTS MUST BE POSITIVE INTEGERS", 2);
}
