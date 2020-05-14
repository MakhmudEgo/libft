/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 05:22:48 by mizola            #+#    #+#             */
/*   Updated: 2020/05/14 20:16:47 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_amount_str(const char *s, const char c)
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

static int		get_len_str(const char *s, const char c, int i)
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

static void		push_str(char *str, const char *s, int *i, char c)
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

static char		**ft_split_add(char **res, const char *s, char c, int *i)
{
	int x;
	int n;

	x = 0;
	while (s[x] != '\0')
	{
		n = get_len_str(s, c, x);
		res[*i] = malloc(sizeof(char) * n);
		if (res[*i] == NULL)
		{
			free(res[*i]);
			return (NULL);
		}
		if (n == 1)
		{
			res[*i] = NULL;
			return (res);
		}
		push_str(res[*i], s, &x, c);
		x++;
		*i += 1;
	}
	res[*i] = NULL;
	return (res);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	int		n;
	int		i;

	i = 0;
	if (!s || !c)
		return (NULL);
	n = get_amount_str(s, c) + 1;
	if (n == 0)
		return (NULL);
	res = malloc(sizeof(char*) * n);
	if (res == NULL)
		return (NULL);
	return (ft_split_add(res, s, c, &i));
}
