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

typedef struct 	s_stack
{
	int		*tab;
	int		len;
}				t_stack;

typedef struct		s_action
{
	char			*label;
	int				len;
	struct s_action	*next;
}					t_action;


typedef struct	s_args
{
	int			ac;
	char		**av;
}				t_args;

#endif