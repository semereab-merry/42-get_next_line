#include "get_next_line_bonus.h"

char	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	n;
	size_t	i;

	if (size == 0 || count == 0 || (count > UINT_MAX / size))
		return (NULL);
	n = count * size;
	result = malloc(n * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < n)
		result[i++] = '\0';
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		len1;
	int		len2;
	int		index;

	if (s1 == 0 && s2 == 0)
		return (NULL);
	len1 = 0;
	while (s1[len1] != '\0')
		len1++;
	result = malloc(((len1 + BUFFER_SIZE + 1) + 1) * sizeof(char));
	if (!result)
		return (free(s1), NULL);
	len1 = 0;
	len2 = 0;
	index = 0;
	while (s1[len1] != '\0')
		result[index++] = s1[len1++];
	while (s2[len2] != '\0')
	{
		result[index++] = s2[len2];
		s2[len2++] = '\0';
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
