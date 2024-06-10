/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_function_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 00:03:06 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/11 00:24:27 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

static int	length_n(long long n)
{
	int	len;

	len = 0;
	if (n < 1)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static long long	absolute_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*str;
	int				sign;
	unsigned int	nbr;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = length_n(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (str);
	str[len] = '\0';
	nbr = absolute_value(n);
	while (len--)
	{
		str[len] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		new[j++] = s2[i++];
	}
	new[j] = '\0';
	return (new);
}
