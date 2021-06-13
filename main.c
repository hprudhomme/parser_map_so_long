#include "get_next_line.h"

int     ft_map_len(char **map)
{   
    int i = 0;

    while (map[i])
        i++;
    return i;
}

int     is_map_char(char c)
{
    if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P')
        return 1;
    return 0;
}

int     check_first_last(char *s)
{
    int i = 0;

    while (s[i])
    {
        if (s[i] != '1')
            return 0;
        i++;
    }
    return 1;
}

int     check_close_map(char **map)
{
    int i = 0;
    int j = 0;
    int map_len = ft_map_len(map) - 1;
    int line_len = ft_strlen(map[0]);

    while (map[i])
    {   
        j = 0;
        if (i == 0 || i == map_len)
        {
            if (check_first_last(map[i]) == 0)
                return 0;
        }
        while (map[i][j])
        {
            if (j == 0 || j == line_len - 1)
            {
                if (map[i][j] != '1')
                    return 0;
            }
            j++;
        }   
        i++;
    }
    return 1;
}

int main(int ac, char **av)
{   
    (void)ac;
	char  *line;
	int   fd1;
    char **map;
    int c;
    int i = 0;
    int j;

    fd1 = open(av[1], O_RDONLY);

    if (!(map = (char **)malloc(sizeof(char*) * (15))))
		return (0);
    while (( c = get_next_line(fd1, &line)) >= 0)
	{   
        if (ft_strlen(line) > 4)
        {   
            if (!(map[i] = malloc(sizeof(char) * (40))))
				return (0);
            map[i] = line;
            i++;
        }
        if (c == 0)
            break ;
    }
    map[i] = NULL;


    i = 0;
    j = 0;
    while (map[i])
    {   
        j = 0;
        while (map[i][j])
        {
           printf("%c", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }

    i = 0;
    j = 0;
    while (map[i])
    {   
        j = 0;
        while (map[i][j])
        {
            if (!(is_map_char(map[i][j])))
                printf("error\n");
            j++;
        }   
        i++;
    }

    int len_line = ft_strlen(map[0]);
    i = 0;
    while (map[i])
    {
        if (ft_strlen(map[i]) != len_line)
            printf("error\n");
        i++;
    }
    if (check_close_map(map) == 0)
        printf("error\n");
}