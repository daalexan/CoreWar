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

int 	ft_valid_file(char *file)
{
	// int i;
	// int len;
//
	//len = ft_strlen(file);
//	i = 0;
	// while (i < len)
	// {
		if (ft_strstr(file, ".cor"))
			printf("cor is here\n");
		//i++;
	// }
		return (1);
}

void	ft_parse_input(t_env *e, int ac, char **av)
{
	int i;
	int p;

	e->plr_numb = 0;
	p = 0;
	i = 1;
	while (i < ac)
	{
		if (ft_valid_file(av[i]))
		{
			printf("%s\n", av[i]);
			e->plrs[p++].file_name = av[i];
			e->plr_numb++;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	t_env	e;
	unsigned int i;
	int j = 0;

	if (ac < 2)
		printf("Not enough files\n");
	else
	{
		ft_parse_input(&e, ac, av);
		ft_read_cor(&e, ac);
		while (j < e.plr_numb)
		{
			i = 0;
			printf("data %u\n", e.plrs[j].head.magic);
			printf("name %s\n", e.plrs[j].head.prog_name);
			printf("comment %s\n", e.plrs[j].head.comment);
			while (i < e.plrs[j].head.prog_size)
			{
				printf("%x ", e.plrs[j].code[i]);
				i++;
			}
			j++;
		}
	}
	printf("\n");
	j = 0;
	while (j < e.plr_numb)
	{
		free(e.plrs[j].code);
		j++;
	}
	return (0);	
}
