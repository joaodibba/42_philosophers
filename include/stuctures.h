/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuctures.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 21:13:36 by jalves-c          #+#    #+#             */
/*   Updated: 2023/10/26 19:30:54 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "philo.h"
# include <pthread.h>

typedef enum e_fork_state
{
	FREE ,
	TAKEN
}	t_fork_state;

typedef enum e_philo_state
{
	DEAD = -1,
	THINK ,
	EAT ,
	SLEEP ,
}	t_philo_state;

typedef enum e_type
{
	PHILO,
	FORK
}			t_type;

// PHILO STRUCTURE
typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	unsigned int	meal_count;
	u_int64_t		last_meal;
	t_philo_state	state;
}					t_philo;

// FORK STRUCTURE

// TODO
typedef struct s_fork
{
	int				owner;
	pthread_mutex_t	mutex;
	t_fork_state	state;
}					t_fork;

// NODE STRUCTURE
typedef struct s_node
{
	t_type			type;
	union
	{
		t_philo		philo;
		t_fork		fork;
	}				u_data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

// HOST STRUCTURE
typedef struct s_host
{
	unsigned int	philosopher_count;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	max_meals;
	unsigned int	node_count;
	u_int64_t		start_time;
	t_node			*head;
}					t_host;

#endif