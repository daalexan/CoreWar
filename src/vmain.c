/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:18:12 by daalexan          #+#    #+#             */
/*   Updated: 2018/11/04 18:19:20 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

// static t_op g_op_tab[17];



int main(int ac, char **av)
{
	t_env	e;
	(void)av;
	e.plr_numb = 1;
	e.plrs[0].file_name = "zork.cor";
	e.plrs[1].file_name = "tutle.cor";
	if (ac < 2)
		printf("Not enough files\n");
	else
	{
		ft_read_cor(&e, ac);

		printf("data %u\n", e.plrs[0].head.magic);
		printf("name %s\n", e.plrs[0].head.prog_name);
		printf("comment %s\n", e.plrs[0].head.comment);

		unsigned int i = 0;
		while (i < e.plrs[0].head.prog_size)
		{
			printf("%x ", e.plrs[0].code[i]);
			i++;
		}
		printf("data %u\n", e.plrs[1].head.magic);
		printf("name %s\n", e.plrs[1].head.prog_name);
		printf("comment %s\n", e.plrs[1].head.comment);

		i = 0;
		while (i < e.plrs[1].head.prog_size)
		{
			printf("%x ", e.plrs[1].code[i]);
			i++;
		}
	}
	return (0);	
}
