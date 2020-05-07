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

static void		skip_elem(const char *str, const char c, int *i)
{
	while (str[*i] == c)
		*i += 1;
}

static int		get_len_str(const char *str, const char c, int i)
{
	int n;

	n = 0;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		n++;
	}
	return (n);
}

static int		get_len_res(const char *str, const char c)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i + 1] != '\0')
	{
		if (str[i] == c)
		{
			skip_elem(str, c, &i);
			n++;
		}

		i++;
	}
	if (n == 0)
		n++;
	return (n);
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	int	i;
	int				n;
	int 			j;
	int 			index;

	j = 0;
	i = 0;
	index = 0;
	n = get_len_res(s, c);
	result = malloc(sizeof(char**) * (n + 1));
	if (result == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		skip_elem(s, c, &i);
		n = get_len_str(s, c, i);
		result[j] = malloc(sizeof(char) * (n + 1));
		if (result[j] == NULL)
		{
			free(result[i]);
			return (NULL);
		}
		while (index < n)
			result[j][index++] = s[i++];
		result[j][index] = '\0';
		index = 0;
		i++;
		j++;
	}
	result[j] = NULL;
	return (result);
}

