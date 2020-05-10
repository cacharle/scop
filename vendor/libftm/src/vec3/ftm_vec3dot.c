/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_vec3dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 21:06:09 by charles           #+#    #+#             */
/*   Updated: 2020/05/09 21:14:44 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_vec3.h"

float		ftm_vec3dot(t_ftmvec3 *a, t_ftmvec3 *b)
{
	return (a->v[0] * b->v[0] +
			a->v[1] * b->v[1] +
			a->v[2] * b->v[2]);
}