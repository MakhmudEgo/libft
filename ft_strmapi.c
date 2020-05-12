/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 15:41:08 by mizola            #+#    #+#             */
/*   Updated: 2020/05/12 16:11:53 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *res;
	unsigned int i;

	i = 0;
	res = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (s == NULL || res == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
char test(unsigned int i, char c)
{
	return c;
}

int main(void)
{
	char *str = ft_strmapi("hello", test);
	printf("res :%s", str);
}
