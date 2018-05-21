/*
** EPITECH PROJECT, 2018
** game
** File description:
** game
*/

#include "../include/my.h"
#include <stdio.h>
#include <string.h>

int who_win(str_t *p, char *line)
{
	if (strcmp(line, p->sol)) {
		printf("You win!\n");
		exit (0);
	}
}

int check_word(str_t *p, char *line)
{
	size_t len = strlen(line);
	
	if (strlen(line) < len) {
		printf("Word too short. Retry\n>");
		return (1);
	}
	if (strlen(line) > len) {
		printf("Word too long. Retry\n>");
		return (1);
	}
	return (0);
}

int game2(str_t *p)
{
	int a = 0;
	char *line = NULL;
	size_t len = 0;
	
	printf("*: invalid letter\n");
	printf("?: incorrectly placed letter\n");
	printf("Will you find the secret word?\n");
	printf("%s\n\n", p->aff);

	while (a != my_norm_strlen(p->sol)) {
		a++;
		printf("Round %d\n>", a);
		getline(&line, &len, stdin);
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) -1] = '\0';
		while (check_word(p, line) == 1)
			getline(&line, &len, stdin);
		who_win(p, line);
	}
}
