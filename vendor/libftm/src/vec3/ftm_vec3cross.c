/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_vec3cross.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 21:20:41 by charles           #+#    #+#             */
/*   Updated: 2020/05/09 21:25:44 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_vec3.h"

/*
** s1 = a2 * b3 - a3 * b2
** s2 = a3 * b1 - a1 * b3
** s3 = a1 * b2 - a2 * b1
*/

void		ftm_vec3cross(t_ftmvec3 *dst, t_ftmvec3 *a, t_ftmvec3 *b)
{
	dst->v[0] = a->v[1] * b->v[2] - a->v[2] * b->v[1];
	dst->v[1] = a->v[2] * b->v[0] - a->v[0] * b->v[2];
	dst->v[2] = a->v[0] * b->v[1] - a->v[1] * b->v[0];
}