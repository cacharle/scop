/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftm_vec3.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 11:02:29 by charles           #+#    #+#             */
/*   Updated: 2020/05/14 18:06:33 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTM_VEC3_H
# define LIBFTM_VEC3_H

# include <math.h>

typedef union
{
	float	v[3];
	struct
	{
		float	x;
		float	y;
		float	z;
	};
}			t_ftmvec3;

t_ftmvec3	*ftm_vec3init(t_ftmvec3 *vec3, float x, float y, float z);
float		ftm_vec3norm(t_ftmvec3 *vec3);
t_ftmvec3	*ftm_vec3normalize(t_ftmvec3 *vec3);

#endif
