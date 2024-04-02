#include "sauvegarde.h"
#include <stdio.h>

void ecrire_dans_fichier(char *texte, char *chemin) {
    FILE *fichier = fopen(chemin, "w");

    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier %s\n", chemin);
        return;
    }
    fprintf(fichier, "%s", texte);
    fclose(fichier);
}

FILE* ouvrir_fichier_en_ajout(const char* chemin) {
    FILE* fichier = fopen(chemin, "a");
    return fichier;
}

void ecrire_chaine_dans_fichier(FILE* fichier, const char* chaine) {
    if (fichier == NULL){
    	printf("Fichier inexistant, verifier l'orthographe");
    }
    fprintf(fichier, "%s", chaine);
}


/*
int main() {

    // test premiere fonction
    char *texte = "quel bail!";
    char *chemin = "fichier.txt";
    ecrire_dans_fichier(texte, chemin);
    
    //test deuxieme fonction
    FILE* fichier = ouvrir_fichier_en_ajout(chemin);
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier\n");
    } else {
        fprintf(fichier, "quel bail!\n");
        fclose(fichier);
    }
    
    //test troisieme fonction
    FILE* fichier2 = fopen("fichier2.txt", "w"); // Ouverture du fichier en mode écriture
    if (fichier2 == NULL) {
        printf("Impossible d'ouvrir le fichier\n");
        return 1;
    }

    ecrire_chaine_dans_fichier(fichier2, texte); // Écriture de la chaîne dans le fichier
    fclose(fichier2); // Fermeture du fichier
}
*/