#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 8

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef	struct		s_params
{
    char **R;
    char **NO;
    char **SO;
    char **WE;
    char **EA;
    char **S;
    char **F;
    char **C;
}					t_params;

void	ft_strdel(char **as);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strcpy(char *dst, const char *src);
void	ft_memdel(void **ap);
char	*ft_substr(char const *s, unsigned int start, size_t len);


//

// libft
char					**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);

int		get_next_line(int fd, char **line);
#endif