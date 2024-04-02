#include"repertoire.h"
#include <stdio.h>
#include <ctype.h>

void tout_en_minuscule(char *b) {
    FILE* fichier = fopen("mon_fichier.txt", "r");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier \n");
        return;
    }

    char c;
    int est_ponctuation = 0;
    int fin_de_phrase = 0;
    // Boucle qui vas lire tout le texte du fichier
    while ((c = fgetc(fichier)) != EOF) {
    	if (c == '.' || c == '!' || c == '?'){
            printf("Fin de phrase \n");
            fin_de_phrase = 1;
            est_ponctuation = 1;
            continue;
    	}
    	// Si le caractere selectionné est une ponctuation
        if (c == ',' || c == ';' || c == ':' || c == '-') {
            continue;
        }
        if (!isalnum(c)) {
            continue;
        }
        if (isdigit(c)){
            continue;
        }
        char mot[100];
        int i = 0;
        while (isalnum(c)) {
            mot[i++] = tolower(c);
            c = fgetc(fichier);
        }
        mot[i] = '\0';
        printf("%s %s\n", mot, fin_de_phrase ? "(fin de phrase)" : "");
        fin_de_phrase = 0;
    }
    fclose(fichier);
}


/*
int main() {
char *chemin = "mon_fichier.txt";
    tout_en_minuscule(chemin);
    return 0;
}
*/
