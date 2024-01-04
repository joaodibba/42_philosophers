/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:28:46 by jalves-c          #+#    #+#             */
/*   Updated: 2024/01/03 18:11:49 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "stuctures.h"
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

// macros -> fd
# define STDOUT 1
# define STDERR 2

// utils
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	put_error(int errno);
int		ft_atoi(const char *str);
long	int	long_atoi(const char *str);
int		ft_isdigit(int x);
t_host	*host(void);
void	wash_the_dishes(void);
void	goodbye(void);
void	print_list(t_node *head);

// validations
bool	argument_check(int ac, char **av);
bool	arguments_are_within_integer_positive_range(int ac, char **av);
bool	arguments_are_numbers(int ac, char **av);

// setup
void	dinner_time(void);
void	initialize_list(void);
void	create_list(void);
void	insert_at_end(t_node	**head);
t_node	*create_node(void);
void	create_philo_node(t_node *node, unsigned int id);
void	create_fork_node(t_node *node, unsigned	int owner);
void	baby_sitting(void);
void	*routine(void	*arg);

// time
uint64_t	get_time(void);
uint64_t	get_current_time(void);
void		ft_sleep(uint64_t time_to_sleep);

// routine
void	contemplate(t_node	*node);
void	nap(t_node	*node);
void	devour(t_node	*node);

#endif