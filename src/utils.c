/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** utils for all
*/

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
