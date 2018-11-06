/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdcor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:25:42 by daalexan          #+#    #+#             */
/*   Updated: 2018/11/06 15:25:43 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


unsigned int ft_get_prog_size(unsigned char *buf, int i)
{
	return ((buf[i] << 24) | (buf[i + 1] << 16) | (buf[i + 2] << 8) | (buf[i + 3]));
}

void	ft_write_code(t_plr *p, unsigned char *buf, int i)
{
	unsigned char code[p->head.prog_size];
	unsigned int j;

	j = 0;
	while (j < p->head.prog_size)
	{
		code[j++] =  buf[i++];
	}
	p->code = code;
}

void		ft_fill(t_plr *p, unsigned char *buf)
{
	int i;
	int j;

	printf("here\n");
	i = 4;
	if (buf[0] == 0 && buf[1] == 234 && buf[2] == 131 && buf[3] == 243)
		p->head.magic = 15369203;
	j = 0;
	while (i < 132)
		p->head.prog_name[j++] = buf[i++];
	if (buf[i] == 0 && buf[i + 1] == 0 && buf[i+2] == 0 && buf[i+3] == 0)
		printf("top\n");
	i += 4;
	p->head.prog_size = ft_get_prog_size(buf, i);
	i += 4;
	j = 0;
	while (i < 2188)
		p->head.comment[j++] = buf[i++];
	if (buf[i] == 0 && buf[i + 1] == 0 && buf[i+2] == 0 && buf[i+3] == 0)
		printf("top\n");
	i += 4;
	ft_write_code(p, buf, i);
	// while (head->prog_size-- > 0)
	// 	i++;
	printf("last %x\n", buf[2214]);
	printf("magic %x\n", p->head.magic);
	printf("come %s\n", p->head.comment);
}

void	ft_read(t_plr *p)
{
	int				fd;
	int				res;
	unsigned char	buf[READ_SIZE];
	int				len;

	fd = -1;
	len = 0;
	if ((fd = open(p->file_name, O_RDONLY)) == -1)
		printf("Error read file\n");
	while ((res = read(fd, buf, READ_SIZE)) > 0)
		buf[res] = '\0';	
	if (close(fd) == -1)
		printf("close error\n");
	ft_fill(p, buf);
	// int len;
	// int	fd;
	// int *buf;
	// (void)head;

	// buf = NULL;
	// len = ft_file_len(av);
	// printf("len = %d\n", len);
	// if ((fd = open(av, O_RDONLY)) == -1)
	// 	printf("error\n");
	// if (read(fd, buf, len) == -1)
	// 	printf("read not read\n");
	// if (close(fd) == -1)
	// 	printf("close eror\n");
	// printf("<>\n");
}

void	ft_read_cor(t_env *e, int ac)
{
	int i;

	i = 0;
	printf("ac %d\n", ac);
	while (i < e->plr_numb)
	{
		ft_read(&e->plrs[i]);
		i++;
	}

	printf("Its end\n");
}