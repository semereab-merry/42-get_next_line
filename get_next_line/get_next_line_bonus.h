#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(const char *str, int c);

#endif
