/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 05:22:48 by mizola            #+#    #+#             */
/*   Updated: 2020/05/06 05:22:57 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_len_res(const char *str, const char c)
{
	unsigned int i;
	unsigned int n;

	i = 0;
	n = 0;
	while (str[i + 1] != '\0')
	{
		if (str[i] == c)
		{
			while (str[i] == c || str[i] == ' ' || str[i] == '\t'
				|| str[i] == '\v' || str[i] == '\f'
				|| str[i] == '\r' || str[i] == '\n')
				i++;
			n++;
		}
		i++;
	}
	return (n);
}

//char	**ft_split(char const *s, char c)
//{
//	char	**result;
//	int 	i;
//
//}





int 	main(void)
{
//	char	**result;
//	int 	i;

	printf("%d\n", get_len_res("h1hhhh22222hhhhh33333hhh    hh    44 44hhh  hh5555hhh6666hhh7hhhh", 'h'));
	return 0;
}