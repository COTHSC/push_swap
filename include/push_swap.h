#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stacks {
	int *stacks;
	int *stacks_b;
	int size_b;
	int size_a;
	int start_b;
}	t_stacks;

int swap_a(t_stacks *s, char *out);
int swap_b(t_stacks *s, char *out);
int swap_both(t_stacks *s, char *out);
int rotate_a(t_stacks *s, char *out);
int rotate_b(t_stacks *s, char *out);
int push_b(t_stacks *s, char *out);
int rotate_both(t_stacks *s, char *out);
int reverse_rotate_a(t_stacks *s, char *out);
int reverse_rotate_b(t_stacks *s, char *out);
int push_a(t_stacks *s, char *out);
int reverse_rotate_both(t_stacks *s, char *out);
int is_sorted(t_stacks *s, int start, int length, char dir);
void quicksort(int *arr, int low, int high);
void quicksort_b(t_stacks *s, int low, int high, int offset);
 void print_stacks(t_stacks *s);
 int quickerswap(t_stacks *s, int pos1, int pos2);
int get_pos(int *arr, int len, int pos);
int quick(t_stacks *s, int low, int high);
int quick_b(t_stacks *s, int low, int high);
int ft_unique_int(t_stacks *s, int newint, int len);
int ft_isint(long long int i);
int fill_stack(t_stacks *s, char **argray, int i);
int fill_struct(t_stacks *s, char **argv, int argc);
char *concat_arg(char **argv, int argc);
int ft_isint(long long int i);
int check_argstr(char *argstr);
int ft_issign(char c);
int ft_isnumber(char *nbrstr);
void    small_sort(t_stacks *s);
void lil_sort(t_stacks *s);
int get_pos(int *arr, int len, int pos);
int get_to_top(t_stacks *s, int pos);
int where_is_min(int *arr, int min, int len);
int get_to_top_a(t_stacks *s, int pos);

#endif
