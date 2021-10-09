/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:15:07 by jescully          #+#    #+#             */
/*   Updated: 2021/10/09 18:30:32 by jescully         ###   ########.fr       */
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
        pos += s->size_a;
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

    if (pos2 > pos1)
    {

        counter = 0;

        counter = get_to_top(s, pos2);
        push_b(s,"pb\n");
        counter += get_to_top(s, pos1 + counter);
        push_b(s,"pb\n");
        print_stacks(s);
        swap_b(s, "sb\n");
        push_a(s,"pa\n");
        //	    print_stacks(s);
        counter += get_to_top(s, pos2 + counter - 1);
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
        print_stacks(s);
    }
    return (1);
}

int quickerswap(t_stacks *s, int  pos1, int pos2)
{
    int turns;
    int ogpos;

    turns = 0;
    ogpos = pos2;

    if (pos2 > pos1)
    {
        if (pos2 > (s->size_a - 1) / 2)
        {
            while (pos2 != s->size_a - 1)
            {
                rotate_a(s, "ra\n");
                pos2++;
                pos1++;
                if (pos1 == s->size_a)
                    pos1 = 0; 
                if (pos2 == s->size_a)
                    pos2 = 0;
            }
        }
        else
        {
            while (pos2 != s->size_a - 1)
            {
                reverse_rotate_a(s, "rra\n");
                pos2--;
                pos1--;
                if (pos1 == -1)
                    pos1 = s->size_a - 1; 
                if (pos2 == -1)
                    pos2 = s->size_a - 1; 
            }
        }
        push_b(s, "pb\n");
        pos2--;

        if (pos1 > (s->size_a - 1) / 2)
        {
            while (pos1 != s->size_a - 1)
            {
                rotate_a(s, "ra\n");
                pos2++;
                pos1++;
                if (pos1 == s->size_a)
                    pos1 = 0; 
                if (pos2 == s->size_a)
                    pos2 = 0; 
            }
        }
        else
        {
            while (pos1 != s->size_a - 1)
            {
                reverse_rotate_a(s, "rra\n");
                pos2--;
                pos1--;
                if (pos1 == -1)
                    pos1 = s->size_a - 1; 
                if (pos2 == -1)
                    pos2 = s->size_a - 1; 
            }
        }
        push_b(s, "pb\n");
        swap_b(s, "sb\n");   
        push_a(s, "pa\n");

        if (pos1 > (s->size_a - 1) / 2)
        {

            while (pos2 != s->size_a -1)
            {
                rotate_a(s, "ra\n");
                pos2++;
                pos1++;
                if (pos1 == s->size_a)
                    pos1 = 0; 
                if (pos2 == s->size_a)
                    pos2 = 0; 
            }
        }
        else
        {
            while (pos2 != s->size_a -1)
            {
                reverse_rotate_a(s, "rra\n");
                pos2--;
                pos1--;
                if (pos1 == -1)
                    pos1 = s->size_a - 1; 
                if (pos2 == -1)
                    pos2 = s->size_a -1; 
            }
        }


        push_a(s, "pa\n");

        if (pos2 > ogpos - 1)
        {
            while (pos2 != ogpos - 1)
            {
                reverse_rotate_a(s, "rra\n");
                pos2--;
                pos1--;
                if (pos2 == -1)
                    pos2 = s->size_a - 1; 
                if (pos1 == -1)
                    pos1 = s->size_a - 1; 
            }
        }
        else
        {
            while (pos2 != ogpos - 1)
            {
                rotate_a(s, "ra\n");
                pos2++;
                pos1++;
                if (pos2 == s->size_a)
                    pos2 = 0; 
                if (pos1 == s->size_a)
                    pos1 = 0; 
            }
        }
    }



    //    print_stacks(s);
    return 1;

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
//  i +=counter;
// j +=counter;

while (j + 1 != s->size_a)
{
//		rotate_a(s, "ra\n");
j++;
i++;
}
push_b(s,"pb\n");
while (i + 1 != s->size_a)
{
rotate_a(s, "ra\n");
i++;
}
push_b(s,"pb\n");
swap_b(s, "sb\n");
push_a(s,"pa\n");
while (i + 1 != pos2)
{
reverse_rotate_a(s,"rra\n");
i--;
}
push_a(s,"pa\n");
while (i  !=  pos1)
{
reverse_rotate_a(s,"rra\n");
i--;
}
}
return (1);
}
*/
void    quicksort(t_stacks *s, int low, int high, int offset)
{
    int pivot;
    int i;
    int j;

    low += offset;
    high += offset;

    if (low > s->size_a - 1)
        low -= s->size_a - 1;
    if (high > s->size_a - 1)
        high -= s->size_a - 1;

    if (low < high)
    {
        pivot = low;

        i = low;
        j = high;
        while (i < j)
        {
            while (s->stacks[i] > s->stacks[pivot] && i < high)
                i++;
            while (s->stacks[j] <= s->stacks[pivot] && j > low)
                j--;
            if ( i < j)
            {
                quickerswap(s, i, j);
            }

        }
        quickerswap(s, j, i);
        quicksort(s, low, j - 1, offset);
        quicksort(s, j + 1, high, offset);
    }
}
