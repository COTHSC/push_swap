/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:15:07 by jescully          #+#    #+#             */
/*   Updated: 2021/10/12 16:48:31 by jescully         ###   ########.fr       */
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

int is_sorted(t_stacks *s, int start, int length, char dir)
{
    int d;

    d = start;
    if (dir == 'a')
    {
        while (d < start + length - 1)
        {
            if (s->stacks[d] < s->stacks[d + 1])
                return 0;
            d++;
        }

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

        if (pos2 > (s->size_a - 1) / 2)
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
    return (pos1 - ogpos);
}

void    quicksort(t_stacks *s, int low, int high, int offset)
{
    int pivot;
    int i;
    int j;

    if (low < high)
    {
        i = low;
        j = high;


        pivot = low;

        while (i < j)
        {
            while (s->stacks[i] > s->stacks[pivot] && i != high)
            {
                i++;
            }

            while (s->stacks[j] <= s->stacks[pivot] && j != low)
            { 
                j--;
            }
            if (i < j)
            {
                quickerswap(s, i, j);
            }

        }
        quickerswap(s, j, i);
        quicksort(s, low, j - 1, offset);
        quicksort(s, j + 1, high, offset);
    }
}




void    quicksort_b(t_stacks *s, int low, int high, int offset)
{
    int pivot;
    int i;
    int j;
    int icount;
    int jcount;


    if (low < high)
    {
        i = low + offset;
        j = high + offset;
        icount = low;
        jcount = high;

        if (j > high)
            j -= (high + 1 - low);
        pivot = i;
        while (icount < jcount)
        {
            while (s->stacks[i] > s->stacks[pivot] && icount < high)
            {
                i++;
                icount++;
                if (i > high)
                    i -= (high - low);
            }

            while (s->stacks[j] <= s->stacks[pivot] && jcount > low)
            { 
                j--;
                jcount--;
                if (j < low)
                    j += (high - low);

            }
            if (icount < jcount)
            {
                if (i < j)
                    quickerswap(s, i, j);
                else
                    quickerswap(s, j, i);
            }

        }
        if (i < j)
            quickerswap(s, i, j);
        else
            quickerswap(s, j, i);
        quicksort(s, low, j - 1, offset);
        quicksort(s, j + 1, high, offset);
    }
}

static int limit = 0;

int get_average(int *arr, int start, int len)
{
    int i;
    int ret;

    i = start;
    ret = 0;
    while (i < len)
    {
        ret += arr[i++];
    }
    return (ret / i);
}
/*
int	quick_b(t_stacks *s, int low, int high, char amhere)
{
    int pivot;
    int i;
    int ra;

    ra = 0;


    if (is_sorted(s, 0, s->size_a, 'a'))
    {
        return 1;
    }	
    i = 0;
    if (amhere == 'a')
    {

        //pivot = s->stacks[s->size_a - 1 - limit];
        pivot = get_average(s->stacks, low, s->size_a);
        while (i++ <= s->size_a + 1)
        {
            if (s->stacks[s->size_a - 1] >= pivot)
            {
                push_b(s, "pb\n");
                i--;
            }
            else
            {
                rotate_a(s, "ra\n");
                ra++;
            }
        }	
        quick_b(s, low, s->size_b - 1, 'b');
    }
    else
    {
        i = 0;
        rotate_b(s, "rb\n");

        pivot = s->stacks_b[s->size_b - 1];
        //		pivot = get_average(s->stacks_b, 0, s->size_b);

        while (i++ < s->size_b &&  !is_sorted(s, s->start_b, s->size_b, 'a'))
        {
            if (s->stacks_b[s->size_b - 1] < pivot)
                push_a(s, "pa\n");
            else
                rotate_b(s, "rb\n");
        }	
        if (s->size_b > limit + 1 && !is_sorted(s, s->start_b, s->size_b, 'a'))
        {
            quick_b(s, low, high, 'b');
        }
    }
    while (limit < 350)
    {
        limit++;
        quick_b(s, low, s->size_a - 1, 'a');
    }
    return 1;
}*/

int	quick_b(t_stacks *s, int low, int high, char amhere)
{
    int pivot;
    int i;
    int low_b;


  //  if (is_sorted(s, 0, s->size_a, 'a'))
  //  {
   //     return 1;
  //  }	

    high = 1;
    i = 0;
    if (amhere == 'a')
    {
        low_b = s->size_b - 1;
        pivot = s->stacks[s->size_a - 1 - limit];
        while (i++ <= s->size_a - 1)
        {
            if (s->stacks[s->size_a - 1] >= pivot)
            {
                push_b(s, "pb\n");
                i--;
            }
            else
            {
                rotate_a(s, "ra\n");
            }
        }	
    }
        i = s->size_b - 1;
        low = s->size_a - 1;

        rotate_b(s, "rb\n");

        pivot = s->stacks_b[s->size_b - 1];

        while (i-- >= 0)
        {
            if (s->stacks_b[s->size_b - 1] < pivot)
                push_a(s, "pa\n");
            else
                rotate_b(s, "rb\n");

        }
        if (s->size_b > 1)
        {
            limit++;
            quick_b(s, 0, s->size_b - 1, 'b');

        }

    return 1;
}
