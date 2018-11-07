/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:15:42 by daalexan          #+#    #+#             */
/*   Updated: 2018/11/04 18:17:15 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>//delete after all

# define READ_SIZE 4096

typedef struct 		s_carr
{
	unsigned int	cur_pos;
	short			carry;
	short			plr_num;
	unsigned int	reg[REG_NUMBER];
	short			alive;
	short			command;
	int				cycles;
}					t_carr;

typedef struct 		s_plr
{
	char			*file_name;
	t_header		head;
	unsigned char	*code;
}					t_plr;

typedef struct 		s_env
{
	unsigned char	fild[MEM_SIZE];
	t_plr			plrs[4];
	short			plr_numb;
	
}					t_env;

void				ft_read_cor(t_env *e, int ac);

#endif
