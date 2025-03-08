/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:07:03 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/08 11:32:18 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_box
{
	int				value;
	int				index;
	int				push_cost;
	int				rank;
	bool			cheapest;
	bool			above_median;
	struct s_box	*target;
	struct s_box	*next;
	struct s_box	*prev;
}	t_box;

typedef struct s_vars
{
	char	**av_pocket;
	char	**new_av;
	int		i;
	int		j;
	int		new_len;
	long	value;
	char	**tmp;
}	t_vars;

typedef struct s_pcost
{
	int	a_size;
	int	b_size;
	int	b_cost;
	int	a_cost;
}	t_pcost;

void	two_boxes(t_box **pile);
void	three_boxes(t_box **pile);
void	five_boxes(t_box **pile_a, t_box **pile_b);
void	big_pile(t_box **pile_a, t_box **pile_b);
void	ranking_system(t_box **pile_a, t_box **pile_b);

void	update_metadata(t_box **pile_a, t_box **pile_b);
void	update_pushcost(t_box **pile_a, t_box **pile_b);
void	update_cheapest(t_box **pile_b);
void	update_rank(t_box **pile);
void	settle_at_top(t_box **pile, t_box *cheapest, char pile_name);

int		pile_size(t_box *pile);
int		swap_pile(t_box **pile);
void	append_box(t_box **pile, t_box *new_box);
t_box	*find_lastbox(t_box *lst);
t_box	*find_smallest(t_box *pile);

void	sa(t_box **pile_a);
void	sb(t_box **pile_b);
void	ss(t_box **pile_a, t_box **pile_b);

void	ra(t_box **pile_a);
void	rb(t_box **pile_b);
void	rr(t_box **pile_a, t_box **pile_b);

void	rra(t_box **pile_a);
void	rrb(t_box **pile_b);
void	rrr(t_box **pile_a, t_box **pile_b);

void	pa(t_box **pile_a, t_box **pile_b);
void	pb(t_box **pile_a, t_box **pile_b);

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	free_argv(char **av, bool argc_2);

char	**build_pile_a(t_box **pile_a, char **av, bool argc_2);

bool	syntax_parser(char *str);
bool	duplicate_parser(t_box **pile_a, int num);
void	free_failure(t_box **pile_a, char **av, bool argc_2);
void	free_pile(t_box **pile_a);
bool	sorted_pile(t_box *pile_a);
bool	pocket_parser(char *str);
bool	pocket_checker(char **av);
char	**append_pocket(char **av, char *av_p, int i);

void	ft_putstr_fd(char *s, int fd);
void	print_error(void);
bool	ft_isdigit(char c);
bool	ft_issign(char c);

#endif // PUSH_SWAP_H