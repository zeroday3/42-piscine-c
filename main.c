/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebraun <pebraun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 12:14:15 by pebraun           #+#    #+#             */
/*   Updated: 2017/07/17 21:54:40 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	do_solve(char *filename)
{
	int		box_size;
	char	**map;
	int		**pt_sums;
	int		i;
	int		j;

	map = build_map(filename);	// 1st line (info) is kept in the array.
	pt_sums = count_array(map + 1, /*obstacle char*/, ft_strlen(maps[1]));
	if ((box_size = bsq(pt_sums, ft_strlen(maps[1]), &i, &j)))
		print_solution(map, box_size, i, j);
	else
		write(2, "map error\n", 10);
}

int	main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
	{
		while(i < argc)
		{
			if (is_valid_input(argv[i]))
			{
				printf("So, yep, it is valid.\n");
				// do_solve(argv[i]);
			}
			i++;
		}
	}
	// TODO: handle stdin if no arguments are passed
	return (0);
}
