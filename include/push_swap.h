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
void quicksort(t_stacks *s, int low, int high, int offset);
void quicksort_b(t_stacks *s, int low, int high, int offset);
 void print_stacks(t_stacks *s);
 int quickerswap(t_stacks *s, int pos1, int pos2);
 int quick_b(t_stacks *s, int low, int high, char amhere);


#endif
