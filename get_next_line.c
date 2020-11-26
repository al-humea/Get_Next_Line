/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:44:07 by al-humea          #+#    #+#             */
/*   Updated: 2020/11/26 15:16:04 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			rtn;
	char		buffer[BUFFER_SIZE + 1];
	static char	*svd_buff = NULL;

	if (fd < 0 || !line || read(fd, buffer, 0) < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (valid_line(svd_buff) >= 0)
		return (new_svdbuff_line(&svd_buff, line));
	while ((rtn = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[rtn] = '\0';
		svd_buff = gnl_strjoin(svd_buff, buffer);
		if (valid_line(svd_buff) >= 0)
			return (new_svdbuff_line(&svd_buff, line));
	}
	if (svd_buff)
	{
		*line = ft_strdup(svd_buff);
		free(svd_buff);
		svd_buff = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}
