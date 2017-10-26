/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:37:35 by amovchan          #+#    #+#             */
/*   Updated: 2017/10/26 15:38:25 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_term	*init_term(t_term *term)
{
	term = (t_term*)malloc(sizeof(t_term));
	term->env = getenv("TERM");
	tcgetattr(0, &term->kankn);
	term->nonkanon = term->kankn;
	term->nonkanon.c_lflag &= (~ICANON & ~ECHO);
	term->nonkanon.c_cc[VTIME] = 0;
	term->nonkanon.c_cc[VMIN] = 1;
	term->fd = ttyslot();
	return (term);
}

t_arg	*init_argument(int ac, char **av)
{
	t_arg 	*arg;
	int		i;

	i = 0;
	arg = (t_arg*)malloc(sizeof(t_arg) * ac);
	while (++i < ac)
	{
		arg[i - 1].line = av[i];
		arg[i - 1].len = ft_strlen(av[i]);
		arg[i - 1].flag = 0;
	}
	arg[i - 1] = NULL;
	return (arg);
}


int		main(int ac, char **av)
{
	t_term	*term;
	t_arg	*arg;

	if (ac == 1)
		return (0);
	term = init_term(NULL);
	if ((tgetent(NULL, term->env)) != 1)
	{
		ft_putstr_fd("Please set the environment variable TERM;\n", STDERR_FILENO);
	ft_putstr_fd(term->env, 0);
		return (0);
	}
	term->height = tgetnum("li");
	term->colum = tgetnum("co");
	arg = init_argument(ac, av);
	ft_do_select(arg, term);
}
