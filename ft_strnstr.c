/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 05:53:54 by mizola            #+#    #+#             */
/*   Updated: 2020/05/04 05:53:55 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t index;
	size_t index1;
	size_t res;

	index = 0;
	index1 = 0;
	res = ft_strlen(needle);
	if (len == 0 && res == 0)
		return ((char*)haystack);
	while (haystack[index] != '\0' && index < len)
	{
		while (haystack[index] == needle[index1] &&
				index < len && haystack[index1])
		{
			index1++;
			index++;
		}
		if (index1 == res)
			return ((char*)haystack + (index - index1));
		index1 = 0;
		index++;
	}
	return (NULL);
}
