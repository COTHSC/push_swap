/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:00:43 by jescully          #+#    #+#             */
/*   Updated: 2021/10/04 15:38:07 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>



int fill_stack(t_stacks *s, char **argv, int argc)
{
	int d;

	s->size_a = argc -1;
	s->size_b = 0;
	s->start_b = argc -1;
	d = 0;
	while (d < argc -1)
	{
		s->stacks[d] = ft_atoi(argv[d + 1]);
		d++;
	}
	return (1);
}

void print_stacks(t_stacks *s, int argc)
{
	int d;

	d = 0;
	printf("     stack 1          stack 2\n");
	while (d < argc - 1)
	{
		printf("        ");
		if (d < s->size_a)
			printf("%d", s->stacks[d]);
		else
			printf(" ");
		printf("                ");
		if (d < s->size_b && s->size_b != 0)
			printf("%d", s->stacks[d + s->start_b]);
		printf("\n");
		d++;
	}

}


int	main(int argc, char **argv)
{
	t_stacks *s;

	s = (t_stacks *)(malloc((sizeof(t_stacks))));
	s->stacks = (int *)(malloc((sizeof(int) * (argc - 1)) * 2));//protect em
	fill_stack(s, argv, argc);
	print_stacks(s, argc);
	if (is_sorted(s, 0, s->size_a))
		return 0; 
	push_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	push_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	push_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	push_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	push_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	swap_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	swap_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	swap_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	swap_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	swap_both(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	swap_both(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	rotate_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	rotate_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	rotate_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	rotate_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	rotate_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	rotate_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	rotate_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	push_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	push_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	rotate_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	rotate_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	rotate_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	rotate_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	rotate_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	rotate_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	rotate_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	rotate_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	rotate_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	push_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	rotate_both(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	rotate_both(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	rotate_both(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	rotate_both(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	rotate_both(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	reverse_rotate_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	reverse_rotate_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	reverse_rotate_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	reverse_rotate_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	reverse_rotate_a(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	reverse_rotate_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	reverse_rotate_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	reverse_rotate_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	reverse_rotate_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	reverse_rotate_b(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);
	
	reverse_rotate_both(s);
	printf("\n\n\n\n");
	print_stacks(s, argc);

	free (s);
	return 0;
}
