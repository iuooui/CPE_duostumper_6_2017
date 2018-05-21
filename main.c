/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

str_t *fill_random_word(str_t *p, char *str, int size)
{
	int nbr_word = my_spestrlen(str);
	int a = rand()% nbr_word;
	int i = 0;
	int c = 0;

	verif_str(str);
	for (int b = 0; b != a; c++) {
		if (str[c] == '\n')
			b++;
	}
	if (str[c] == '\n')
		c++;
	p->sol = malloc(sizeof(char) * (my_strlen(str, c) + 1));
	for (;str[c] != '\n' && str[c] != '\0'; c++) {
		p->sol[i] = str[c];
		i++;
	}
	p->sol[i] = '\0';
	if (my_norm_strlen(p->sol) < 2)
		exit(84);
	return (p);
}

str_t *parth(str_t *p, char **av, int size, struct stat stats)
{
	int f = 0;
	int s = 0;
	char *str = malloc(sizeof(char) * (size + 1));

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
	free(str);
	return (p);
}

void game(str_t *p, char **av)
{
	int size = 0;
	struct stat stats;
	int a = 0;
	int b = 0;

	stat(av[1], &stats);
	size = stats.st_size;
	p = parth(p, av, size, stats);
	p->aff = malloc(sizeof(char) * (my_norm_strlen(p->sol) + 1));
	p->aff[a] = p->sol[a];
	a++;
	for (;a != my_norm_strlen(p->sol); a++)
		p->aff[a] = '*';
	p->aff[a] = '\0';
	p->rep = malloc(sizeof(char) * (my_norm_strlen(p->sol) + 1));
	for (;b != my_norm_strlen(p->sol); b++)
		p->rep[b] = ' ';
	p->rep[b] = '\0';
	game2(p);
}

int main(int ac, char **av)
{
	str_t *p = malloc(sizeof(str_t));

	srand(time(NULL));
	if (ac != 2)
		return (84);
	game(p, av);
	free(p->sol);
	free(p->rep);
	free(p->aff);
	free(p);
	return(0);
}
