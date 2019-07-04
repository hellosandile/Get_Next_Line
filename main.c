#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>

int main(int c, char **av)
{
	int	fd;
	int ret;
	char	*line;
	ret = c;

	fd = open(av[1], O_RDONLY, 0);
	if (fd == -1)
	{
		printf("error opening file");
			return (0);
	}
	while (fd == 1)
	{
		fd = get_next_line(fd, &line);
		printf("%s", line);
	}
	if (fd == -1)
		ft_putstr("There was an error\n");
	else
		printf("Your file reading is done");
	close(fd);
	return (0);
}
