/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 11:53:53 by charles           #+#    #+#             */
/*   Updated: 2020/05/13 16:43:59 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

float	*color_new(size_t n)
{
	size_t			i;
	float			step;
	float			*colors;
	union u_color	c;

	if ((colors = malloc(sizeof(float) * (n * 4))) == NULL)
		return (NULL);
	step = 0.8 / (float)n;
	i = 0;
	c.r = 0.1;
	c.g = 0.1;
	c.b = 0.1;
	c.a = 1.0;
	while (i < n)
	{
		c.r += step;
		c.g += step;
		c.b += step;
		ft_memcpy(&colors[i * 4], c.data, 4 * sizeof(float));
		i++;
	}
	return (colors);
}

bool	color_merge_vertices(t_object *object, float *coords)
{
	size_t	i;
	float	*colors;
	float	*new_vertices;

	if ((colors = color_new(object->vertices_len)) == NULL)
		return (false);
	if ((new_vertices = malloc(sizeof(float) * object->vertices_len * (4 + 4 + 2))) == NULL)
	{
		free(colors);
		return (false);
	}
	i = 0;
	while (i < object->vertices_len)
	{
		ft_memcpy(&new_vertices[i * (4 + 4 + 2)], &object->vertices[i * 4], 4 * sizeof(float));
		ft_memcpy(&new_vertices[i * (4 + 4 + 2) + 4], &colors[i * 4], 4 * sizeof(float));
		ft_memcpy(&new_vertices[i * (4 + 4 + 2) + 8], &coords[i * 2], 2 * sizeof(float));
		i++;
	}
	free(object->vertices);
	object->vertices = new_vertices;
	return (true);
}