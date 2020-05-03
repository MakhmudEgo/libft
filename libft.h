/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 19:12:53 by mizola            #+#    #+#             */
/*   Updated: 2020/05/02 22:50:12 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIBFT_H
# define LIBFT_LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <string.h>

size_t		ft_strlen(const char *str);
void		*ft_memset(void *destination, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *destination, const void *source, size_t n);
void		*ft_memccpy(void *destination, const void *source, int c, size_t n);
void		*ft_memmove(void *destination, const void *source, size_t n);
void		*ft_memchr(const void *arr, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

#endif
