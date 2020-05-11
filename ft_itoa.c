/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 14:44:26 by mizola            #+#    #+#             */
/*   Updated: 2020/05/11 15:20:46 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int			i;
	int			j;
	long long int	tmp;

	i = 0;
	tmp = n;
	if (n < 0)
	{
		i++;
		tmp *= (-1);
	}
	if (tmp < 10 && n > (-10))
		return (i + 2);
	while (tmp >= 10)
	{
		j = tmp % 10;
		tmp /=10;
		i++;
	}
	return (i + 2);
}

static void	push_char(char *s, long long int n)
{
	long long int res;
	char tmp;
	int index;

	res = n;
	index = 0;
	if (n < 0)
	{
		s[index] = '-';
		index++;
		res *= (-1);
		push_char(s, res);
	}
	else
	{
		if (res > 10)
			push_char(s, res / 10);
		tmp = res % 10 + '0';
		s[index] = tmp;
		++index;
	}
//	s[index] = '\0';
}

char		*ft_itoa(int n)
{
	char 	*res;

	res = malloc(sizeof(char) * num_len(n));
	if (res == NULL)
		return (NULL);
	push_char(res, n);
	return (res);
}

int 		main(void)
{
//	ft_itoa(1234);
	printf("%s\n", ft_itoa(123));
//	printf("%s\n", s);
}