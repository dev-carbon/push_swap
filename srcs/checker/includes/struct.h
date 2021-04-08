/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 09:48:12 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/05 09:48:16 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_stack
{
	int		*tab;
	int		size;
}					t_stack;

typedef struct		s_action
{
	char			*label;
	int				len;
}					t_action;

typedef struct		s_ops
{
	t_action		*action;
	struct s_ops	*next;
}					t_ops;

typedef struct		s_args
{
	int				ac;
	char			**av;
}					t_args;

typedef struct		s_vars
{
	t_args			*args;
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_ops			*ops;
}					t_vars;

#endif
