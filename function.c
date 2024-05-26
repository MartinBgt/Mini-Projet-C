#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int isGPS(char chaine[]){
	// Fonction qui prend en paramètre une chaine de caractère : si cette chaine est
	// une trame GPS de la forme GPGGA, alors la fonction renvoie un entier égal à 1
	// sinon 0.

	char *ch = strstr(chaine, "$GPGGA");
	int i = 0;
  	char *pVirgule=strchr(chaine,',');

	// Calcul le nombre de virgule dans la chaine.
 	while (pVirgule!=NULL) {
    		i++;
    		pVirgule=strchr(pVirgule+1,',');
  	}

	// Si la chaine "$GPGGA" est présente dans la chaine et qu'elle est au début
	// et que le nombre de virgules est égal à 14, alors on renvoie 1.
	if (ch != NULL && ch-chaine == 0 && i == 14) {
		return 1;
	} else {
		return 0;
	}
}

void extractGPS(char chaine[], char result[][10]){
	// Fonction qui prend en paramètre une chaine de caractère contenant une trame GPS
	// de la forme GPGGA et qui crée un tableau contenant chacune des parties de la trame.

	char *deb = strstr(chaine, "$GPGGA")+7; // Crée un pointeur juste après la première virgule situé après la chaine "GPGGA".
	char *fin = strchr(deb, ','); // Crée un pointeur à l'emplacement de la première virgule de la chaine du pointeur deb. 
	for (int i = 0; i<13; i++) {
		strncpy(result[i] , deb, fin-deb); // Ajoute dans le tableau la chaine situé entre les deux virgules 
		result[i][fin - deb] = '\0'; // On ajoute le caractère nul à la fin de la chaine.
		deb = fin+1; // le pointeur deb pointe maintenant au même emplacement que fin+1
		fin = strchr(deb, ','); // le pointeur fin pointe à l'emplacement de la prochaine virgule.
	}
}

void extractTime(char result[][10], char time[10]) {
	// Fonction qui prend en paramètre le tableau contenant toutes les parties de la trame et
	// renvoie une chaine de caractère représentant l'heure.

	char* end;
	float timeFloat = strtof(result[0], &end); // Convertie la chaine de caractaire en float
	int timeInt = (int)floor(timeFloat); // Convertie le float en int en arrondissant à l'entie le plus bas.
	char timeString[7];

	sprintf(timeString, "%d", timeInt); // Convertie l'ientie timeInt en chaine de caractères.

	// Si la chaine fait 5 caractères alors on décale tous les caractères et on ajoute un 0 au début car dans le cas ou l'on a une heure qui ne dépasse pas 9h59m59s, alors la chaine ne ferait que 5 caractères.
	if (strlen(timeString) == 5) {
		for (int i = strlen(timeString); i>0; i--) {
			timeString[i] = timeString[i-1];
		}
		timeString[0] = '0';
		timeString[7] = '\0'; // On n'oublie pas de modidifié l'emplacment du caractères nul.
	}

	// Création de la chaine de caractères finale.
	int index = 0;
	for (int i = 0; i < 9; i++) {
		if (i == 2) {
			time[i] = 'h';
		} else if (i == 5) {
			time[i] = 'm';
		} else if (i == 8) {
			time[i] = 's';
		} else {
			time[i] = timeString[index];
			index += 1;
		}
	}
}

void printTime(char time[10]) {
	printf("%s\n", time);
}

void getLatAndLon(char trame[][10], char lat[][6], char lon[][6] ){

        // initialisation de la latitude
        char degLat[3];
        char minLat[3];
        char centMinLat[3];
        for(int i = 0; i<2 ; i++){
                degLat[i] = trame[1][i];        // récupère les degré placé en début de la latitude
                degLat[2] = '\0';
                minLat[i] = trame[1][i+2];      // récupère les minutes placé en 3emes position dans la latitude
                minLat[2] = '\0';
                centMinLat[i] = trame[1][i+5];  // récupère les centièmes de minutes à la 5eme position
                centMinLat[2] = '\0';
        }

        // transformation des centiemes de minutes en secondes
        int intCentMinLat = atoi(centMinLat);
        float floatSecLat = (float)intCentMinLat*60/100;

        char secLat[6];
        sprintf(secLat,"%.2f",floatSecLat);
        secLat[5] = '\0';

        // copie des degré, minutes et secondes dans la chaine lat
        strcpy(lat[0],degLat);
        strcpy(lat[1],minLat);
        strcpy(lat[2],secLat);
        // copie de la direction N/S dans la chaine lat
        strcpy(lat[3],trame[2]);

        // intitialisation de la longitude
        char degLon[4];
        char minLon[3];
        char centMinLon[3];

        for(int i = 0; i<2 ; i++){
                degLon[i] = trame[3][i];        // récupère les degré placé en début de la latitude

                minLon[i] = trame[3][i+3];      // récupère les minutes placé en 3emes position dans la lati>
                minLon[2] = '\0';
                centMinLon[i] = trame[3][i+6];  // récupère les centièmes de minutes à la 5eme position
		centMinLon[2] = '\0';
        }
        degLon[2] = trame[3][2];
        degLon[3] = '\0';

        // transformation des centiemes de minutes en secondes
        int intCentMinLon = atoi(centMinLon);
        float floatSecLon = (float)intCentMinLon*60/100;

        char secLon[6];
        sprintf(secLon,"%.2f",floatSecLon);
        secLon[5] = '\0';

        // copie des degrés, minutes et secondes dans la chaine lon
        strcpy(lon[0],degLon);
        strcpy(lon[1],minLon);
        strcpy(lon[2],secLon);
        // copie de la direction E/W dans la chaine lon
        strcpy(lon[3],trame[4]);
}

void printLatAndLon(char lat[][6], char lon[][6]){

        printf("Latitude : %s°%s'%s\" %s\n",lat[0],lat[1],lat[2],lat[3]);
        printf("Longitude : %s°%s'%s\" %s\n",lon[0],lon[1],lon[2],lon[3]);
}

