/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 01:58:24 by jalves-c          #+#    #+#             */
/*   Updated: 2023/10/22 02:02:31 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// 1/4 of a second
#define SLEEP_TIME 250000

typedef struct s_account
{
	int				balance;
}				t_account;

int	read_balance(t_account *account)
{
	int	balance;

	balance = account->balance;
	return (balance);
}

void	increment_balance(t_account *account)
{
	int	i;

	i = 0;
	while (i++ < 1000000)
		account->balance++;
}

void	*deposit(void *arg)
{
	t_account	*account;
	int			account_ballance;
	int			deposit_ammount;

	account = (t_account *)arg;
	account_ballance = read_balance(account);
	increment_balance(account);
	return (NULL);
}

int	main(void)
{
	pthread_t			threads[2];
	static t_account	account;
	static int			i;

	printf("Before: %d\n", read_balance(&account));
	while (i < 2)
		pthread_create(&threads[i++], NULL, deposit, (void *)&account);
	i = 0;
	while (i < 2)
		pthread_join(threads[i++], NULL);
	printf("After: %d\n", read_balance(&account));
	return (0);
}
