#include "get_next_line_bonus.h"

char	*ft_read_nline(char *buffer)
{
	int		i;
	int		j;
	int		len;
	char	*next_line;

	i = 0;
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
	{
		i++;
		len++;
	}
	while (buffer[len])
		len++;
	if (!buffer[i])
		return (free(buffer), buffer = NULL, NULL);
	next_line = ft_calloc(((len - i) + 1), sizeof(char));
	if (!next_line)
		return (free(buffer), buffer = NULL, NULL);
	i++;
	j = 0;
	while (buffer[i])
		next_line[j++] = buffer[i++];
	return (free(buffer), next_line);
}

char	*ft_read_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] && buffer[i] == '\n')
		line = ft_calloc((i + 2), sizeof(char));
	else
		line = ft_calloc((i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_read_file(int fd, char *buffer)
{
	char	*str;
	int		buffer_read;

	if (buffer == NULL)
		buffer = ft_calloc(1, sizeof(char));
	if (!buffer)
		return (NULL);
	str = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!str)
		return (free(buffer), buffer = NULL, NULL);
	buffer_read = 1;
	while (buffer_read > 0)
	{
		buffer_read = read(fd, str, BUFFER_SIZE);
		if (buffer_read == -1)
			return (free(str), free(buffer), buffer = NULL, NULL);
		buffer = ft_strjoin(buffer, str);
		if (!buffer)
			return (free(str), str = NULL, NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(str), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (!buffer[fd])
	{
		buffer[fd] = NULL;
		return (NULL);
	}
	line = ft_read_line(buffer[fd]);
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = ft_read_nline(buffer[fd]);
	if (buffer[fd] == NULL)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h> 
// int main()
// {
//     int fd = open("text.txt", O_RDONLY);
//     int fd2 = open("text2.txt", O_RDONLY);
//     int fd3 = open("text3.txt", O_RDONLY);
// 	char *line;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	printf("\n");
// 	while ((line = get_next_line(fd2)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	printf("\n");
// 	while ((line = get_next_line(fd3)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }