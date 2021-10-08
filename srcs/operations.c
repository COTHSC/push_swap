/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:15:07 by jescully          #+#    #+#             */
/*   Updated: 2021/10/08 19:35:09 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/push_swap.h"

int swap_a(t_stacks *s, char *out)
{
    int temp;
    if (s->size_a != 0)
    {		
        temp = s->stacks[s->size_a - 1];
        s->stacks[s->size_a - 1] = s->stacks[s->size_a - 2];
        s->stacks[s->size_a - 2] = temp;
    }
    ft_putstr_fd(out, 1);
    return 1;	
}

int swap_b(t_stacks *s, char *out)
{
    int temp;
    if (s->size_b != 0)
    {		
        temp = s->stacks[s->start_b + s->size_b - 1];
        s->stacks[s->start_b + s->size_b -1] = s->stacks[s->start_b + s->size_b - 2];
        s->stacks[s->start_b + s->size_b - 2] = temp;
    }
    ft_putstr_fd(out, 1);
    return 1;	

}

int swap_both(t_stacks *s, char *out)
{
    swap_a(s, "");
    swap_b(s, "");
    ft_putstr_fd(out, 1);
    return (1);
}

int push_b(t_stacks *s, char *out)
{

    if (s->size_a != 0)
    {	
        s->stacks[s->start_b + s->size_b] = s->stacks[s->size_a - 1];
        s->size_b++;
        s->size_a--;
    }
    ft_putstr_fd(out, 1);
    return 1;	
}

int push_a(t_stacks *s, char *out)
{

    if(s->size_b != 0)
    {
        s->stacks[s->size_a] = s->stacks[s->start_b + s->size_b - 1];
        s->size_a++;
        s->size_b--;
    }

    ft_putstr_fd(out, 1);

    return 1;	
}

int	rotate_a(t_stacks *s, char *out)
{
    int temp;
    int d;

    if (s->size_a != 0)
    {
        d = s->size_a - 1;
        temp = s->stacks[s->size_a - 1];
        while (d > 0)
        {
            s->stacks[d] = s->stacks[d - 1];
            d--;
        }	
        s->stacks[0] = temp;
    }
    ft_putstr_fd(out, 1);
    return (1);
}

int	reverse_rotate_a(t_stacks *s, char *out)
{
    int temp;
    int d;

    if (s->size_a != 0)
    {
        d = 0;
        temp = s->stacks[0];
        while (d < s->size_a - 1) 
        {
            s->stacks[d] = s->stacks[d + 1];
            d++;
        }	
        s->stacks[s->size_a - 1] = temp;
    }
    ft_putstr_fd(out, 1);
    return (1);
}

int	reverse_rotate_b(t_stacks *s, char *out)
{
    int temp;
    int d;

    if (s->size_b != 0)
    {
        d = s->start_b;
        temp = s->stacks[s->start_b];
        while (d < s->start_b + s->size_b - 1) 
        {
            s->stacks[d] = s->stacks[d + 1];
            d++;
        }	
        s->stacks[s->start_b + s->size_b - 1] = temp;
    }
    ft_putstr_fd(out, 1);
    return (1);
}

int	reverse_rotate_both(t_stacks *s, char *out)
{
    reverse_rotate_a(s, "");
    reverse_rotate_b(s, "");
    ft_putstr_fd(out, 1);
    return (1);
}

int	rotate_b(t_stacks *s, char *out)
{
    int temp;
    int d;

    if (s->size_b != 0)
    {
        d = s->size_b - 1;
        temp = s->stacks[s->start_b + s->size_b - 1];
        while (d > 0)
        {
            s->stacks[s->start_b + d] = s->stacks[s->start_b + d - 1];
            d--;
        }	
        s->stacks[s->start_b] = temp;
    }
    ft_putstr_fd(out, 1);
    return (1);
}

int	rotate_both(t_stacks *s, char *out)
{
    rotate_a(s, "");
    rotate_b(s, "");
    ft_putstr_fd(out, 1);
    return (1);
}

int is_sorted(t_stacks *s, int start, int length)
{
    int d;

    d = start;
    while (d < start + length - 1)
    {
        if (s->stacks[d] < s->stacks[d + 1])
            return 0;
        d++;
    }
    return 1;
}

int is_min(int * array, int nbr, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (array[i] < nbr)
            return 0;
        i++;
    }
    return 1;
}

int choose_pivot(int *array, int start, int end)
{
    while (start < end)
    {
        if (!is_min(&array[start] , array[start], end - start))
            return (array[start]);
        else 
            start++;
    }
    return (0);
}

int get_to_top(t_stacks *s, int pos)
{
    int i;

    if (pos > s->size_a - 1)
        pos -= s->size_a;
    if (pos < 0)
        pos += s->size_a + s->size_b;
    i = 0;
    if (pos >= (s->size_a - 1) / 2)
    {
        while (pos != (s->size_a - 1))
        {
            pos++;
            rotate_a(s, "ra\n");
            i++;
        }
    } 
    else
    {
        while (pos != -1)
        {
            pos--;
            reverse_rotate_a(s, "rra\n");
            i--;
        }

    } 
    return i;
}


int quickswap(t_stacks *s, int pos1, int pos2)
{
    int counter;

    if (pos1 < pos2)
    {

    counter = 0;
    
    counter = get_to_top(s, pos2);
    push_b(s,"pb\n");
    counter += get_to_top(s, pos1 + counter);
    push_b(s,"pb\n");
    swap_b(s, "sb\n");
    push_a(s,"pa\n");
    counter += get_to_top(s, counter + pos2 - 1);
    push_a(s,"pa\n");
 //  print_stacks(s);
    while (counter != 0)
    {
        if (counter < 0)
        {
            rotate_a(s, "ra\n");
            counter++;
        }

        if (counter > 0)
        {
            reverse_rotate_a(s, "rra\n");
            counter--;
        }
    }
    }
return (1);
}

/*
int quickswap(t_stacks *s, int pos1, int pos2)
{
    int i;
    int j;
    int counter;


    counter = 0;
    i = pos1;
    j = pos2;
    if (pos2 > pos1)
    {
        counter = get_to_top(s, pos2);
        //    while (j + 1 != s->size_a)
        //  {
        // rotate_a(s, "ra\n");
        //      j++;
        //   i++;
        // }
        push_b(s,"pb\n");
        counter += get_to_top(s, pos1 + counter);
        //  while (i + 1 != s->size_a)
        //  {
        //    rotate_a(s, "ra\n");
        //  i++;
        //  }
        push_b(s,"pb\n");
        print_stacks(s);
        swap_b(s, "sb\n");
        print_stacks(s);
        push_a(s,"pa\n");
        print_stacks(s);
        counter += get_to_top(s, pos1 + counter);
        print_stacks(s);
        //   while (counter > 1)
        //   {
        //      reverse_rotate_a(s, "rra\n");
        //     counter--;
        // }
        // while (i + 1 != pos2)
        // {
        //  if (i == s->size_a)
        //       i = i - (s->size_a);
        //      rotate_a(s,"ra\n");
        //    reverse_rotate_a(s,"rra\n");
        //  i--;
        // }
        push_a(s,"pa\n");
        while (counter != 0)
        {
            if (counter < 0)
            {
                rotate_a(s, "ra\n");
                counter++;
            }

            if (counter > 0)
            {
                reverse_rotate_a(s, "rra\n");
                counter--;
            }
        }
        //  {
        //     reverse_rotate_a(s, "rra\n");
        //    counter--;
        //  }

        //   while (i  !=  pos1)
        //   {
        //    reverse_rotate_a(s,"rra\n");
        //   i--;
        // }
        print_stacks(s);
    }
    return (1);
}*/


void    quicksort(t_stacks *s, int low, int high)
{
    int pivot;
    int i;
    int j;

    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            while (s->stacks[i] >= s->stacks[pivot] && i < high)
                i++;
            while (s->stacks[j] < s->stacks[pivot] && j > low)
                j--;
            if ( i < j)
            {
                quickswap(s, i, j);
            }

        }
        quickswap(s, j, i);
        quicksort(s, low, j - 1);
        quicksort(s, j + 1, high);
    }
}
