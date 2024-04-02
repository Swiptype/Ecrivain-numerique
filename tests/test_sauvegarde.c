#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include"../src/sauvegarde.h"

void test_ecrire_dans_fichier(){
  char *txt = "Test écrire dans le fichier !";
  char *chemin = "test.txt";
  char contenu[100];

  printf("Test écrire dans le fichier\n");
  ecrire_dans_fichier(txt, chemin);
  FILE *fichier = fopen(chemin, "r");
  fgets(contenu, 100, fichier);
  fclose(fichier);
  assert(strcmp(contenu, txt) == 0);
  printf("ok\n");
}

void test_ouvrir_fichier_en_ajout(){
  char *chemin = "test.txt";

  printf("Test ouvrir un fichier\n");
  FILE* fichier = ouvrir_fichier_en_ajout(chemin);
  assert(fichier != NULL);
  fprintf(fichier, "%s\n", txt);
  fclose(fichier);

  char *cheminI = "dossier/fichier_test.txt";
  FILE* cheminI = ouvrir_fichier_en_ajout(cheminI);
  assert(cheminI == NULL);
  printf("ok\n");
}

void test_ecrire_chaine_dans_fichier(){
  char contenu[100];

  printf("Test insertion fichier texte\n");
  FILE* fichier1 = fopen("fichier_test.txt", "w");
  ecrire_chaine_dans_fichier(fichier1, "Ecrire dans le premier fichier !");
  fclose(fichier1);

  FILE* fichier2 = fopen("fichier_test.txt", "r");
  fgets(contenu, 100, fichier2);
  fclose(fichier2);
  assert(strcmp(contenu, "Ecrire dans le deuxième fichier !") == 0);
  printf("ok\n");
}

int main(int argc, char *argv[]){
  test_ecrire_dans_fichier();
  test_ouvrir_fichier_en_ajout();
  test_ecrire_chaine_dans_fichier();
  assert(1);
  return EXIT_SUCCESS;
}
