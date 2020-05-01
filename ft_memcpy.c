/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 20:48:39 by mizola            #+#    #+#             */
/*   Updated: 2020/05/01 22:58:29 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	if (n == 0 || destination == source)
		return (destination);
	while (n)
	{
		*((char*)destination + n - 1) = *((char*)source + n - 1);
		n--;
	}
	return (destination);
}
