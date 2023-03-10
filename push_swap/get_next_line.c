/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:11:36 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/11 01:27:34 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_attach(char *src, char *dest)
{
	char	*str;

	str = ft_strjoinn(src, dest);
	free(src);
	return (str);
}

char	*ft_path(char *tab)
{
	int		i;
	char	*path;

	i = 0;
	if (!tab[i])
		return (NULL);
	while (tab[i] && tab[i] != '\n')
		i++;
	path = ft_callocc(i + 2, sizeof(char));
	i = 0;
	while (tab[i] && tab[i] != '\n')
	{
		path[i] = tab[i];
		i++;
	}
	if (!tab[i])
		tab[i] = 0;
	else
		path[i] = '\n';
	return (path);
}

char	*ft_nextrow(char *tab)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (tab[i] && tab[i] != '\n')
		i++;
	if (!tab[i])
	{
		free(tab);
		return (NULL);
	}
	str = ft_callocc((ft_strlenn(tab) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (tab[i])
		str[j++] = tab[i++];
	free(tab);
	return (str);
}

char	*scan_file(int fd, char *str)
{
	char	*tab;
	int		num_bit;

	if (!str)
		str = ft_callocc(1, 1);
	tab = ft_callocc(BUFFER_SIZE + 1, sizeof(char));
	num_bit = 1;
	while (num_bit > 0)
	{
		num_bit = read(fd, tab, BUFFER_SIZE);
		if (num_bit == -1)
		{
			free(tab);
			return (NULL);
		}
		tab[num_bit] = 0;
		str = ft_attach(str, tab);
		if (ft_strchrr(tab, '\n'))
			break ;
	}
	free(tab);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*path;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd < 0)
		return (NULL);
	str = scan_file(fd, str);
	if (!str)
		return (NULL);
	path = ft_path(str);
	str = ft_nextrow(str);
	return (path);
}

// int	main() //returns blank
// {
// 	static int	fd;
// 	// fd = open("text1.txt", O_CREAT | O_WRONLY, 0600);
// 	// if (fd == -1)
// 	// {
// 	// 	printf("Failed to create & open file.\n");
// 	// 	return (1);
// 	// }
// 	// write(fd, "This is a test string.\nThis is another test string.", 52);
// 	// // write(fd, "\n", 30);
// 	// write(fd, "This is the third test string.\n", 32);
// 	// write(fd, "This is the last test string.\n", 31);
// 	// close(fd);
// 	fd = open("text.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Failed to open & read file.\n");
// 		return (1);
// 	}
// 	printf("main: %s\n", get_next_line(fd));
// 	printf("main: %s\n", get_next_line(fd));
// 	printf("main: %s\n", get_next_line(fd));
// 	printf("main: %s\n", get_next_line(fd));
// }