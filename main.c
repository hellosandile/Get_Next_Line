#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>

int main(int c, char **av)
{
	int	fd;
	int ret;
	char	*line;
	int res;
	ret = c;

	fd = open(av[1], O_RDONLY, 0);
	if (fd == -1)
	{
		printf("error opening file");
			return (0);
	}
	while ((res = get_next_line(fd, &line)) > 0)
		printf("%s\n", line);
	if (res == -1)
		ft_putstr("There was an error\n");
	else
		printf("Your file reading is done");
	close(fd);
	return (0);
}
