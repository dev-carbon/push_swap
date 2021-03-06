/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_operation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 19:23:42 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/12 22:50:31 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	is_valid_operation(char *label, t_vars *vars)
{
	int	len;

	len = ft_strlen(label);
	if (len < LABEL_MIN_LEN || len > LABEL_MAX_LEN)
		exit_prog(EXIT_FAILURE, "Invalid operation.\n", vars);
	if (ft_strncmp(label, SWAP_A, len) != 0
		&& ft_strncmp(label, SWAP_B, len) != 0
		&& ft_strncmp(label, SWAP_AB, len) != 0
		&& ft_strncmp(label, PUSH_A, len) != 0
		&& ft_strncmp(label, PUSH_B, len) != 0
		&& ft_strncmp(label, ROTATE_A, len) != 0
		&& ft_strncmp(label, ROTATE_B, len) != 0
		&& ft_strncmp(label, ROTATE_AB, len) != 0
		&& ft_strncmp(label, REV_ROTATE_A, len) != 0
		&& ft_strncmp(label, REV_ROTATE_B, len) != 0
		&& ft_strncmp(label, REV_ROTATE_AB, len) != 0)
		exit_prog(EXIT_FAILURE, "Invalid operation.\n", vars);
	return (1);
}
