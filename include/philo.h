/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:28:46 by jalves-c          #+#    #+#             */
/*   Updated: 2023/10/18 21:57:36 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

// macros
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define PURPLE "\e[0;35m"
# define YELLOW "\e[0;33m"
# define RESET "\e[0;37m"
# define CLEAR "\033c"

# define WRONG_ARGUMENTS 1
# define ARGUMENTS_NOT_NUMBERS 2
# define ARGUMENTS_NOT_POSITIVE_INTEGER 3

typedef struct s_data
{
	int		philosopher_count;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		meal_count;	
}				t_data;

// structure
t_data	*data(void);

// utils
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	put_error(int errno);

// validations
bool	arguments_are_within_integer_positive_range(int ac, char **av);
bool	arguments_are_numbers(int ac, char **av);
int		ft_atoi(const char *str);
long	int	long_atoi(const char *str);
int		ft_isdigit(int x);

#endif