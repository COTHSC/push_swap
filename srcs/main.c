/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:00:43 by jescully          #+#    #+#             */
/*   Updated: 2021/10/06 14:47:25 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

static int  ft_iswhitespace(int c)
{
    if (c == '\v' || c == '\r' || c == '\f' || \
            c == ' ' || c == '\n' || c == '\t')
        return (1);
    else
        return (0);
}



int ft_isnumber(char *nbrstr)
{
    int i;

    i = 0;
    while (nbrstr[i])
    {
        if (!ft_isdigit(nbrstr[i]) && !ft_iswhitespace(nbrstr[i]))
            return (0);
    }
    return (1);
}

char *concat_arg(char **argv, int argc)
{
    int i;
    char *argstr;
    char *temp;

    argstr = " ";
    i = 1;
    while (i < argc)
    {
        temp = ft_strjoin(argstr, " ");
        argstr = ft_strjoin(temp, argv[i++]);
        free(temp);
    }
    return (argstr);
}

int ft_issign(char c)
{
    if (c == '-')
        return (1);

    if (c == '+')
        return (1);
    return 0;
}


int check_argstr(char *argstr)
{
    int i;

    i = 0;
    while (argstr[i])
    {
        if (!ft_isdigit(argstr[i]) && !ft_iswhitespace(argstr[i]) && !ft_issign(argstr[i]))
            return (0);
        i++;
    }
    return (1);
}

int ft_isint(long long int i)
{
    if (i < INT_MAX && i > INT_MIN)
        return (1);
    return (0);
}

int ft_unique_int(t_stacks *s, int new, int len)
{
    int i;

    i = 0;
    while (i <= len)
    {
        if (s->stacks[i] == new)
            return (0);
        i++;
    }
    return (1);
}

int fill_stack(t_stacks *s, char **argray, int i)
{
    int d;

    d = 0;
    while (i > 0)
    {
        if (ft_isint(ft_atoi(argray[d])) && ft_unique_int(s, ft_atoi(argray[d]), d + 1))
            s->stacks[i - 1] = ft_atoi(argray[d]);
        else 
            return 0;
        free(argray[d]);
        i--;
        d++;
    }
    return (1);
}

int fill_struct(t_stacks *s, char **argv, int argc)
{
    char *argstr;
    char **argray;

    argstr = concat_arg(argv, argc);
    if (!check_argstr(argstr))
        return 0;
    argray = ft_split(argstr, ' ');
    free (argstr);
    s->size_a = 0;

    while (argray[s->size_a])
        s->size_a++;
    s->stacks = (int *)malloc(sizeof(int) * s->size_a * 2);
    s->size_b = 0;
    s->start_b = s->size_a;
    s->stacks_b = &s->stacks[s->start_b];
    if (!fill_stack(s, argray, s->size_a))
        return (0);
    free(argray);
    return (1);
}

void print_stacks(t_stacks *s)
{
    int d;

    d = 0;
    printf("     stack 1          stack 2\n");
    while (d < s->start_b)
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

void lil_sort(t_stacks *s)
{
    if (s->size_a == 2)
        (swap_a(s, "sa\n"));
    else
    {
        if (s->stacks[0] > s->stacks[1] && s->stacks[0] > s->stacks[2] && s->stacks[1] < s->stacks[2])
            swap_a(s, "sa\n");
        else if (s->stacks[0] < s->stacks[1] && s->stacks[1] < s->stacks[2])
        {   
            swap_a(s, "sa\n");
            reverse_rotate_a(s, "rra\n");
        }
        else if (s->stacks[0] > s->stacks[1] && s->stacks[0] < s->stacks[2])
            rotate_a(s, "ra\n");
        else if (s->stacks[0] < s->stacks[1] && s->stacks[1] > s->stacks[2] && s->stacks[0] > s->stacks[2])
        {   
            swap_a(s, "sa\n");
            rotate_a(s, "ra\n");
        }
        else if (s->stacks[0] < s->stacks[1] && s->stacks[1] > s->stacks[2])
            reverse_rotate_a(s, "rra\n");
    }
}

void    small_sort(t_stacks *s)
{
    int turns;

    turns = 0;
    push_b(s, "pb\n");
    if (s->size_a == 4)
        push_b(s, "pb\n");
    lil_sort(s);
    if (!is_sorted(s, s->start_b, s->size_b))
        swap_b(s, "sb\n");
    while (s->size_b != 0 || !is_sorted(s, 0, s->size_a))
    {
        if (s->size_b > 0 && (s->stacks_b[s->size_b - 1] < s->stacks[s->size_a - 1] || turns == s->size_a))
            push_a(s, "pa\n");
        else
        {
            rotate_a(s, "ra\n");
            turns++;
        }
    }
}

int sort(t_stacks *s)
{
    if (is_sorted(s, 0, s->size_a) || s->size_a == 1)
        return 1;
    else if (s->size_a <= 3)
        lil_sort(s);
    else if (s->size_a <= 5)
        small_sort(s);
    else
        quicksort(s, s->size_a, s->stacks[s->size_a -1]);
    return 0;
}

int	main(int argc, char **argv)
{
    t_stacks *s;
    if (argc != 1)
    {
        s = (t_stacks *)(malloc((sizeof(t_stacks))));
        if (!fill_struct(s, argv, argc))
        {
            printf("invalid argument \n");
            return 0;
        }
        print_stacks(s);
        concat_arg(argv, argc);
        sort(s);
        print_stacks(s);
        /*        push_b(s);
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
        */
            free (s);
    }
    return 0;
}
