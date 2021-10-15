/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:15:07 by jescully          #+#    #+#             */
/*   Updated: 2021/10/15 00:56:27 by jescully         ###   ########.fr       */
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



/*
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
*/
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
        quicksort_b(s, low, j - 1, offset);
        quicksort_b(s, j + 1, high, offset);
    }
}

//static int limit = 0;

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

void    quicksort(int *arr, int low, int high)
{
    int pivot;
    int i;
    int j;
    int temp;

    if (low < high)
    {
        i = low;
        j = high;


        pivot = low;

        while (i < j)
        {
            while (arr[i] > arr[pivot] && i != high)
            {
                i++;
            }

            while (arr[j] <= arr[pivot] && j != low)
            { 
                j--;
            }
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

        }
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        quicksort(arr, low, j - 1);
        quicksort(arr, j + 1, high);
    }
}

int get_pos(int *arr, int len, int pos)
{
    int i;
    int *arrcpy;
	int ret;

    i = 0;

    arrcpy = (int *)malloc(sizeof(int) * len);
    while (i < len)
    {
        arrcpy[i] = arr[i];
        i++;
    }

    quicksort(arrcpy, 0, len - 1);
	ret = arrcpy[pos];
	free(arrcpy);
    return ret;
}

int get_to_top_a(t_stacks *s, int pos)
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

int get_to_top(t_stacks *s, int pos)
{
    int i;

    if (pos > s->size_b - 1)
        pos -= s->size_b;
    if (pos < 0)
        pos += s->size_b;
    i = 0;
    if (pos >= (s->size_b - 1) / 2)
    {
        while (pos != (s->size_b - 1))
        {
            pos++;
            rotate_b(s, "rb\n");
            i++;
        }
    } 
    else
    {
        while (pos != -1)
        {
            pos--;
            reverse_rotate_b(s, "rrb\n");
            i--;
        }

    } 
    return i;
}

int where_is_min(int *arr, int min, int len)
{
    int i;

    i = 0;
    while (arr[i] != min && i < len)
    {
        i++;
    }
    return i;

}

static int divisor = 11;

int	push_to_b(t_stacks *s, int low, int high)
{

    int i;
    int pivot;
	int chunck_size;

    i = 0;

	chunck_size = (high / divisor++) - 1;

	if (s->size_a <= chunck_size)
		while (s->size_a != 0)
            push_b(s, "pb\n");

    pivot = get_pos(s->stacks, s->size_a, chunck_size);

	while (i++ <= s->size_a + s->size_b - 1 && s->size_a != 0 && get_pos(s->stacks, s->size_a, 0) >= pivot)
    {
		if (get_pos(s->stacks, s->size_a, 1) < pivot)
			get_to_top_a(s, where_is_min(s->stacks, get_pos(s->stacks, s->size_a, 0), s->size_a));
        if (s->stacks[s->size_a - 1] >= pivot)
            push_b(s, "pb\n");
        else
			rotate_a(s, "ra\n");
    }
	while (s->size_a != 0)
		push_to_b(s, low + chunck_size, high);
	
	
	
	
	low++;
	low--;
	high++;
	high--;
    return 1;
}

int and_back_to_a(t_stacks *s, int low,  int high)
{
	int swap;
	low++;
	high++;
	high--;

	swap = 0;
    while (s->size_b != 0)
    {
        if (s->stacks_b[s->size_b - 1] == get_pos(s->stacks_b, s->size_b, 0))
		{
			push_a(s, "pa\n");
			if (swap == 1)
				swap_a(s, "sa\n");
			swap = 0;
		}
		else if (s->stacks_b[s->size_b - 1] == get_pos(s->stacks_b, s->size_b, 1) && swap == 0)
		{
			push_a(s, "pa\n");
			swap = 1;
		}

        else
        {
            get_to_top(s, where_is_min(s->stacks_b, get_pos(s->stacks_b, s->size_b, 0), s->size_b));
        }

    }
	return 1;
}

int	quick(t_stacks *s, int low, int high)
{
	low++;
	push_to_b(s, 0, s->size_a);
	and_back_to_a(s, 0, high);
	return 1;
}

/*
int	quick(t_stacks *s, int low, int high)
{
    int i;
    int pivot;

    i = low;

    pivot = get_pos(s->stacks, high, (s->size_a - 1) / 2);
    while (s->size_a > (high/2) && i++ <= high - 1)
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
    while (s->size_b != 0)
    {
        if (s->stacks_b[s->size_b - 1] == get_pos(s->stacks_b, s->size_b, 0))
			push_a(s, "pa\n");
        else
        {
            get_to_top(s, where_is_min(s->stacks_b, get_pos(s->stacks_b, s->size_b, 0), s->size_b));
        }
    }
	i = 0;
	while (i <= (high / 2))
	{
		rotate_a(s, "ra\n");
		i++;
	}
	quick_b(s, high / 2, high);
    return 1;
}
*/

int	quick_b(t_stacks *s, int low, int high)
{
    int i;
    int pivot;

    i = low;

    pivot = get_pos(s->stacks, high, (s->size_a - 1) / 2);
    while (s->size_a > (high/2) && i++ <= (high/2) && s->stacks[i] != pivot)
    {
        if (s->stacks[s->size_a - 1] <= pivot)
        {
            push_b(s, "pb\n");
            i--;
        }
        else
        {
            rotate_a(s, "ra\n");
        }
    }
    while (s->size_b != 0)
    {
        if (s->stacks_b[s->size_b - 1] == get_pos(s->stacks_b, s->size_b, 0))
			push_a(s, "pa\n");
        else
        {
            get_to_top(s, where_is_min(s->stacks_b, get_pos(s->stacks_b, s->size_b, 0), s->size_b));
        }
    }
    return 1;
}




