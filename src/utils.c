/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** utils for all
*/

#include <stdlib.h>

void verif_str(char *str)
{
	for (int a = 0; str[a] != '\0'; a++) {
		if ((str[a] < 'a' || str[a] > 'z') && str[a] != '\n')
				exit(84);
	}
}

int my_spestrlen(char *str)
{
	int ligne = 0;

	for (int a = 0; str[a] != '\0'; a++) {
		if (str[a] == '\n')
			ligne++;
	}
	return (ligne);
}

int my_strlen(char *str, int c)
{
	int a = 0;

	for (;str[c] != '\n' && str[c] != '\0'; c++)
		a++;
	return (a);
}

int my_norm_strlen(char *str)
{
	int a = 0;

	for(;str[a] != '\0'; a++);
	return (a);
}
