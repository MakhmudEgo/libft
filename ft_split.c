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

int 	get_amount_str(const char *s, const char c)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			i = 1;
			while (*s != c && *s != '\0')
				s++;
			s--;
			n++;
		}
		s++;
	}
	if (i)
		n = (n == 0) ? 1 : n;
	return (n);
}
int		get_len_str(const char *s, const char c, int i)
{
	int n;

	n = 0;
	while ((s[i] == c || s[i] == ' ') && s[i] != '\0')
		i++;
	while ((s[i] != c) && s[i] != '\0')
	{
		i++;
		n++;
	}
	return (n + 1);
}

void 	push_str(char *str, const char *s, int *i, char c)
{
	int n;

	n = 0;
	while ((s[*i] == c || s[*i] == ' ') && s[*i] != '\0')
		*i += 1;
	while (s[*i] != c && s[*i] != '\0')
	{
		str[n] = s[*i];
		n++;
		*i += 1;
	}
	*i -= 1;
	str[n] = '\0';
}

char		**ft_split(char const *s, char c)
{
	char	**res;
	int		n;
	int		i;
	int 	x;

	n = get_amount_str(s, c) + 1;
	if (n == 0)
		return (NULL);
	res = malloc(sizeof(char*) * n);
	if (res == NULL)
		return (NULL);
	n = 0;
	i = 0;
	x = 0;
	while (s[x] != '\0')
	{
		n = get_len_str(s, c, x);
		res[i] = malloc(sizeof(char) * n);
		if (res[i] == NULL)
		{
			free(res[i]);
			return (NULL);
		}
		if (n == 1)
		{
			res[i] = NULL;
			return (res);
		}
		push_str(res[i], s, &x, c);
		x++;
		i++;
	}
	res[i] = NULL;
	return (res);
}
//
//int 	main(void)
//{
//	char **str = ft_split(" ", ' ');
//	printf("1 :%s\n", str[0]);
//}
