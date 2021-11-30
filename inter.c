#include <unistd.h>

int	checkChar(char *string, char c, int index)
{
	int i = 0;

	while (i < index)
	{
		if (string[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	inter(char *s1, char *s2)
{
	int i = 0;
	int	j = 0;
	while (s2[j])
		j++;
	while (s1[i])
	{
		if (checkChar(s1, s1[i], i) == 1 && checkChar(s2, s1[i], j) == 0)
				write(1, &s1[i], 1);
			i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **av)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	inter(av[1], av[2]);
	return (0);
}
