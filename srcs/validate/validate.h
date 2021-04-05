/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:48:35 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/04 12:48:40 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include "push_swap.h"

int		is_valid_args(int argc, char **argv);
int		is_valid_action(char *label, int nbytes);

#endif