#include <unistd.h>

int	checkChar(char *string, char c, int index)
{
	int	i = 0;
	while (i < index)
	{
		if (string[i] == c)
			return(0);
		i++;
	}
	return (1);
}

void unioN(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	while (s1[i])
	{
		if (checkChar(s1, s1[i], i) == 1)
			write(1, &s1[i], 1);
		i++;
	}
	while (s2[j])
	{
		if (checkChar(s1, s2[j], i) == 1 && checkChar(s2, s2[j], j) == 1)
			write(1, &s2[j], 1);
		j++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **av)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return(0);
	}
	unioN(av[1], av[2]);
	return (0);
}
