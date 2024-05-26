/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 1                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Analyse de trame GPS                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : Pesant Fantin                                                *
*                                                                             *
*  Nom-prénom2 : Bagot Martin                                                 *
*                                                                             *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : function.h                                                *
*                                                                             *
******************************************************************************/

int isGPS(char chaine[]);

void extractGPS(char chaine[], char result[][10]);

void extractTime(char result[][10], char time[10]);

void printTime(char time[10]);

void getLatAndLon(char trame[][10], char lat[][6], char lon[][6]);

void printLatAndLon(char lat[][6], char lon[][6]);
