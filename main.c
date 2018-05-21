/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

str_t *fill_random_word(str_t *p, char *str, int size)
{
	int nbr_word = my_spestrlen(str);
	
	verif_str(str);
}

str_t *parth(str_t *p, char **av, int size)
{
	int f = 0;
	int s = 0;
	char *str = malloc(sizeof(char) * (size));

	if (S_ISDIR(stats.st_mode))
		exit(84);
	f = open(av[1], O_RDONLY);
	if (f == -1)
		exit(84);
	s = read(f, str, size);
	str[s] = '\0';
	if (s == -1)
		exit(84);
	close(f);
	p = fill_random_word(p, str, size);
	return (p);
}

void game(str_t *p, char **av)
{
	int size = 0;
	struct stat stats;

	stat(av[1], &stats);
	size = stats.st_size;
	p = parth(p, av, size);
}

int main(int ac, char **av)
{
	str_t *p = malloc(sizeof(str_t));

	if (ac != 2)
		return (84);
	game(p, av);
	return(0);
}
