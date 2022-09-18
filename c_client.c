/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_client.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:43:12 by leyeghia          #+#    #+#             */
/*   Updated: 2022/07/04 14:19:27 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

static int	ft_atoi(const char *s)
{
	int	val;
	int	i;
	int	sign;

	val = 0;
	sign = 1;
	i = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign = -1;
	while (s[i] > 47 && s[i] < 58)
	{	
		val = 10 * val + (s[i] - 48);
		i++;
	}
	return (sign * val);
}

void	ft_send_text(int pid, char *str)
{
	int	i;
	int	n;

	i = -1;
	while (str[++i])
	{
		n = 7;
		while (n >= 0)
		{
			if (((str[i] >> n) & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			--n;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		ft_send_text(ft_atoi(av[1]), av[2]);
	return (0);
}
