/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c <jalves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:45:24 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/11 16:45:26 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "structures.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdio.h>

// macros
# define MAX_PHILO 200
# define MIN_TIME 60

// macros -> printf colors
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define PURPLE "\e[0;35m"
# define YELLOW "\e[0;33m"
# define RESET "\e[0;37m"
# define CLEAR "\033c"

// macros -> error codes
# define WRONG_ARGUMENTS 1
# define ARGUMENTS_NOT_NUMBERS 2
# define ARGUMENTS_NOT_POSITIVE_INTEGER 3
# define PHILO_VALUE_TOO_BIG 4
# define TIME_VALUE_TOO_LOW 5

// macros -> fd
# define STDOUT 1
# define STDERR 2

t_host		*host(void);
bool		argument_check(int ac, char **av);
bool		initialize_list(t_host	*host);
void		wait_for_philos(t_host *host);
void		*routine(void	*arg);
void		devour(t_node	*node);
void		nap(t_node	*node);
void		contemplate(t_node	*node);
bool		create_list(t_host	*host);
bool		wash_the_dishes(t_host	*host);
bool		goodbye(t_host	*host);
void		baby_sitting(t_host	*host);
void		message(int id, char *color, char *msg);
uint64_t	get_time(void);
uint64_t	get_current_time(void);
void		ft_sleep(uint64_t time_to_sleep);
int			ft_isdigit(int x);
int			ft_abs(int n);
int			ft_atoi(const char *str);
long int	long_atoi(const char *str);
bool		put_error(int errno);
void		print_list(t_node *head);

#endif	