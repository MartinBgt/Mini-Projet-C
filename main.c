#include <stdio.h>
#include <stdlib.h>
#include "function.h"

#define MAX_CHAR 69 // nombre maximal de caractère pris en compte

int main() {
	FILE *file;
    	char filename[] = "trame.txt";
    	char trame[MAX_CHAR];

    	// Ouverture du fichier en mode lecture
    	file = fopen(filename, "r");
    	if (file == NULL) {
        	perror("Erreur lors de l'ouverture du fichier");
        	return EXIT_FAILURE;
   	}

   	// Lecture du contenu du fichier et affichage sur la console
   	int i = 0;
	char c;
	while (i < MAX_CHAR && (c = fgetc(file)) != EOF) {
   	     	trame[i] = c;
		i++;
   	}

   	// Fermeture du fichier
   	if (fclose(file) != 0) {
   		perror("Erreur lors de la fermeture du fichier");
   	    	return EXIT_FAILURE;
   	}

	if (isGPS(trame) == 1){

		char result[10][10];

		extractGPS(trame, result);

		char time[10];
		char lat[4][6];
		char lon[4][6];
		extractTime(result, time);
		getLatAndLon(result, lat, lon);
		printf("Heure : ");
		printTime(time);
		printLatAndLon(lat,lon);
	} else {
		printf("La chaine n'est pas une trame GPS GPGGA...\n");
	}
}
