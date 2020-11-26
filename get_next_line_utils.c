/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:44:11 by al-humea          #+#    #+#             */
/*   Updated: 2020/11/26 15:13:59 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		i;

	if (!str)
		return (NULL);
	if (!(dup = malloc(sizeof(char) * (ft_strlen((char *)str) + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int		valid_line(char *str)
{
	int i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*joined;

	if (!str1)
		return (ft_strdup(str2));
	i = 0;
	j = 0;
	if (!(joined = malloc(sizeof(char) * (ft_strlen(str1) + BUFFER_SIZE + 1))))
		return (NULL);
	while (str1[i])
	{
		joined[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		joined[i + j] = str2[j];
		j++;
	}
	joined[i + j] = '\0';
	free(str1);
	str1 = NULL;
	return (joined);
}

int		new_svdbuff_line(char **svd_buff, char **line)
{
	int		i;
	char	*nline;
	char	*nsvd_buff;

	if (!(nline = malloc(sizeof(char) * (valid_line(*svd_buff) + 1))))
		return (-1);
	i = 0;
	while ((*svd_buff)[i])
	{
		if ((*svd_buff)[i] == '\n')
			break ;
		nline[i] = (*svd_buff)[i];
		i++;
	}
	nline[i] = '\0';
	*line = nline;
	nsvd_buff = ft_strdup(&(*svd_buff)[i + 1]);
	free(*svd_buff);
	*svd_buff = nsvd_buff;
	return (1);
}
