/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 11:02:00 by charles           #+#    #+#             */
/*   Updated: 2020/05/14 16:01:53 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

#define SCOP_VEC_DEFAULT_SIZE 2048

static void	*st_iter_func_decrement_uint(void *void_uint)
{
	unsigned int	uint;

	uint = *(unsigned int*)&void_uint;
	uint--;
	return (*(void**)&uint);
}

static int	st_parse_face(char **indexes_strs, t_ftvec *indices)
{
	size_t			i;
	size_t			len;
	unsigned int	first;
	unsigned int	tmp;

	len = ft_strslen(indexes_strs);
	first = ft_atoi(indexes_strs[0]);
	i = 1;
	while (i < len - 1)
	{
		if (ft_vecpush(indices, *(void**)&first) == NULL)
			return (-1);
		tmp = ft_atoi(indexes_strs[i]);
		if (ft_vecpush(indices, *(void**)&tmp) == NULL)
			return (-1);
		tmp = ft_atoi(indexes_strs[i + 1]);
		if (ft_vecpush(indices, *(void**)&tmp) == NULL)
			return (-1);
		i++;
	}
	return (0);
}

static int	st_parse_vertex(char **positions_strs, t_ftvec *vertices)
{
	float	tmp;

	tmp = ft_atof(positions_strs[0]);
	ft_vecpush(vertices, *((void**)&tmp));
	tmp = ft_atof(positions_strs[1]);
	ft_vecpush(vertices, *((void**)&tmp));
	tmp = ft_atof(positions_strs[2]);
	ft_vecpush(vertices, *((void**)&tmp));
	if (positions_strs[3] != NULL)
	{
		tmp = ft_atof(positions_strs[3]);
		ft_vecpush(vertices, *((void**)&tmp));
	}
	else
	{
		tmp = 1.0f;
		ft_vecpush(vertices, *((void**)&tmp));
	}
	tmp = 1.0f;
	ft_vecpush(vertices, *((void**)&tmp));
	ft_vecpush(vertices, *((void**)&tmp));
	ft_vecpush(vertices, *((void**)&tmp));
	ft_vecpush(vertices, *((void**)&tmp));
	ft_vecpush(vertices, *((void**)&tmp));
	ft_vecpush(vertices, *((void**)&tmp));
	return (0);
}

/* static int	st_parse_texture_coord(char **coord_strs, t_ftvec *coords) */
/* { */
/* 	float	tmp; */
/*  */
/* 	tmp = ft_atof(coord_strs[0]); */
/* 	ft_vecpush(coords, *((void**)&tmp)); */
/* 	if (coord_strs[1] != NULL) */
/* 	{ */
/* 		tmp = ft_atof(coord_strs[1]); */
/* 		ft_vecpush(coords, *((void**)&tmp)); */
/* 	} */
/* 	else */
/* 	{ */
/* 		tmp = 0.0f; */
/* 		ft_vecpush(coords, *((void**)&tmp)); */
/* 	} */
/* 	if (ft_strslen(coord_strs) == 3) */
/* 	{ */
/* 		tmp = ft_atof(coord_strs[2]); */
/* 		ft_vecpush(coords, *((void**)&tmp)); */
/* 	} */
/* 	else */
/* 	{ */
/* 		tmp = 0.0f; */
/* 		ft_vecpush(coords, *((void**)&tmp)); */
/* 	} */
/* 	return (0); */
/* } */

static int	st_parse_line(char *line, t_ftvec *vertices, t_ftvec *indices)
{
	int		ret;
	char	**split;

	if (!ft_strnequ(line, "v ", 2) && !ft_strnequ(line, "f ", 2))
		return (0);
	if ((split = ft_split(line + 1, ' ')) == NULL)
		return (-1);
	ret = -1;
	if (*line == 'v' && ft_strslen(split) == 3)
		ret = st_parse_vertex(split, vertices);
	if (*line == 'f' && ft_strslen(split) >= 3)
		ret = st_parse_face(split, indices);
	ft_strsdestroy(split);
	return (ret);
}

static int	st_parse_file(int fd, t_ftvec *vertices, t_ftvec *indices)
{
	char	*line;
	int		ret;

	while ((ret = ft_getline(fd, &line)) == FT_LINE)
	{
		ret = st_parse_line(line, vertices, indices);
		free(line);
		if (ret == -1)
			break ;
	}
	if (ret == FT_ERROR)
		return (-1);
	if (*line != '\0')
		ret = -1;
	free(line);
	return (0);
}

int			parse(char *filepath, t_model_data *data)
{
	int		fd;
	t_ftvec	*vertices;
	t_ftvec	*indices;

	if (!helper_check_extension(filepath, ".obj")
		|| (fd = open(filepath, O_RDONLY)) == -1)
		return (-1);
	if ((vertices = ft_vecnew(SCOP_VEC_DEFAULT_SIZE)) == NULL)
		return (-1);
	if ((indices = ft_vecnew(SCOP_VEC_DEFAULT_SIZE)) == NULL)
		return (-1);
	st_parse_file(fd, vertices, indices);
	ft_veciter_ret(indices, st_iter_func_decrement_uint);
	data->vertices = (float*)ft_vectobuf32(vertices);
	data->indices = (unsigned int*)ft_vectobuf32(indices);
	data->vertices_num = vertices->size;
	data->indices_num = indices->size;
	ft_vecdestroy(vertices, NULL);
	ft_vecdestroy(indices, NULL);
	return (0);
}
