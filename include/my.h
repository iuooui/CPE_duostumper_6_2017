/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

typedef struct s_str
{
	char *sol;
	char *aff;
	char *rep;
}str_t;

void verif_str(char *);
int my_spestrlen(char *);
int my_strlen(char *, int);
int my_norm_strlen(char *);
int check_word(str_t * , char *);
int game2(str_t *);
