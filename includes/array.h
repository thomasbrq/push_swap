/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:51:50 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/28 15:02:46 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

int		array_have_duplicate(int *array, int nb);
int		*sort_array(int *array, int nb);
int		*copy_array(int *array, int *temp, int nb);
int		*simplify_array(int *array, int nb);
int		array_is_sorted(int *array, int size);
int		*ft_get_params(int argc, char **argv, int *array, int *nb_args);
int		ft_num_len(int n);

#endif
