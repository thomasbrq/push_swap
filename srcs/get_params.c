/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:10:46 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/28 16:42:34 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/array.h"

static void	free_temp(char **temp)
{
	int	i;

	i = 0;
	while (temp[i] != NULL)
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

static int	*ft_str_to_int(int *array, char **argv, int **nb_args)
{
	char			**temp;
	int				i;

	i = 0;
	temp = ft_split(argv[1], ' ');
	while ((temp[i]) != NULL)
		i++;
	array = (int *) malloc((i) * sizeof(int));
	if (!array)
		return (NULL);
	**nb_args = (i);
	i = -1;
	while (temp[++i] != NULL)
	{
		if ((size_t) ft_num_len(ft_atoi(temp[i])) != ft_strlen(temp[i])
			|| (!ft_isdigit(*temp[i]) && ft_atoi(temp[i]) > 0))
		{
			free(array);
			free_temp(temp);
			return (NULL);
		}
		array[i] = ft_atoi(temp[i]);
	}
	free_temp(temp);
	return (array);
}

static int	*ft_params_to_array(int *array, char **argv, int **nb, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < (argc - 1))
		i++;
	**nb = i;
	array = (int *) malloc(i * sizeof(int));
	if (!array)
		return (NULL);
	i = 1;
	j = 0;
	while (i < (argc))
	{
		if ((size_t) ft_num_len(ft_atoi(argv[i])) != ft_strlen(argv[i])
			|| ((!ft_isdigit(*argv[i])) && (ft_atoi(argv[i]) >= 0)))
		{
			free(array);
			return (NULL);
		}
		array[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	return (array);
}

int	*ft_get_params(int argc, char **argv, int *array, int *nb_args)
{
	int	*a;

	a = NULL;
	if (argc == 2)
		a = ft_str_to_int(array, argv, &nb_args);
	else
		a = ft_params_to_array(array, argv, &nb_args, argc);
	return (a);
}
