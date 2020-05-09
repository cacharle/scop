/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_vec4add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 20:45:59 by charles           #+#    #+#             */
/*   Updated: 2020/05/09 21:15:07 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_vec4.h"

t_ftmvec4	*ftm_vec4add(t_ftmvec4 *dst, t_ftmvec4 *other)
{
	dst->v[0] += other->v[0];
	dst->v[1] += other->v[1];
	dst->v[2] += other->v[2];
	dst->v[3] += other->v[3];
	return (dst);
}
