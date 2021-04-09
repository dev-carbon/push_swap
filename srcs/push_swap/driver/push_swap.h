/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:03:18 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/04 12:03:59 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <time.h>
# include "libft.h"
# include "struct.h"
# include "const.h"
# include "init.h"
# include "stack.h"
# include "sort.h"
# include "util.h"
# include "validate.h"

int		push_swap(t_vars *vars);
t_vars	*execute(t_vars *vars, t_action *action);

#endif
