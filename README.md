# Analyse de trames GPS

## Description


## Auteurs
- **PESANT** Fantin
- **BAGOT** Martin

## Documentation des Fonctions

### Fonction 1 : `isGPS`
- **Description** : Fonction qui détecte si une chaine est de type GPGGA ou non.

- **Paramètres d'entrée** :
  - `chaine` (char[]) : Chaine de caractères
- **Sorties** :
  - (int) : 1 si la chaine est de type GPGGA, 0 sinon

### Fonction 2 : `extractGPS`
- **Description** : Fonction qui extrait les données d'une chaine de caractères de type GPGGA.

- **Paramètres d'entrée** :
  - `chaine` (char[]) : Chaine de caractères de la forme GPGGA
  - `result` (char[][10]) : Tableau a deux dimensions

### Fonction 3 : `extractTime`
- **Description** : Fonction qui extrait l'heur et la convertie au format XXhYYmZZs

- **Paramètres d'entrée** :
  - `result` (char[][10]) : Tableau a deux dimensions
  - `time` (char[10]) : Chaine de caractères qui va contenir l'heur au format souhaité.

### Fonction 4 : `printTime`
- **Description** : Fonction qui affiche l'heur au format XXhYYmZZs

- **Paramètres d'entrée** :
  - `time` (char[10]) : Chaine de caractères qui contient l'heur au format XXhYYmZZs.

### Fonction 5 : `getLatAndLon`
- **Description** : Fonction qui récupère la longitude et la latitude au format XX°YY'ZZ.ZZ"

- **Paramètres d'entrée** :
  - `trame` (char[][10]) : Tableau a deux dimensions
  - `lat` (char[][6]) : Tableau a deux dimensions pour la latitude
  - `lon` (char[][6]) : Tableau a deux dimensions pour la longitude

### Fonction 6 : `printLatAndLon`
- **Description** : Fonction qui affiche la latitude et la longitude au format XX°YY'ZZ.ZZ"

- **Paramètres d'entrée** :
  - `lat` (char[][6]) : Tableau a deux dimensions pour la latitude
  - `lon` (char[][6]) : Tableau a deux dimensions pour la longitude

## Utilisation

Il suffit de mettre une chaine de caractère au format GPGGA dans le fichier trame.txt et si la chaine est correcte alors le programme afficheront l'heur ainsi que la latitude et la longitude.

