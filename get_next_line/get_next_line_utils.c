#include "get_next_line.h"

char	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	n;
	size_t	i;

	if (size == 0 || count == 0 || (count > UINT_MAX / size))
		return (NULL);
	n = count * size;
	result = malloc(n);
	if (!result)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		result[i] = '\0';
		n--;
		i++;
	}
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		index_1;
	int		index_2;
	int		index;

	if (s1 == 0 && s2 == 0)
		return (NULL);
	index_1 = 0;
	while (s1[index_1] != '\0')
		index_1++;
	result = malloc(((index_1 + BUFFER_SIZE + 1) + 1) * sizeof(char));
	if (!result)
		return (free(s1), NULL);
	index_1 = 0;
	index_2 = 0;
	index = 0;
	while (s1[index_1] != '\0')
		result[index++] = s1[index_1++];
	while (s2[index_2] != '\0')
	{
		result[index++] = s2[index_2];
		s2[index_2++] = '\0';
	}
	result[index] = '\0';
	return (free(s1), result);
}

int	ft_strchr(const char *str, int c)
{
	unsigned char	new_c;
	int				index;

	new_c = (unsigned char) c;
	index = 0;
	while (str[index])
	{
		if (new_c == str[index])
			return (index++);
		index++;
	}
	return (0);
}
