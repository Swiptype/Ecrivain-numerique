#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include"../src/repertoire.h"

void test_tout_en_minuscule() {
  printf("Test caractère en minuscule\n");
  FILE* fichier_vide = fopen("fichier_vide.txt", "w");
  fclose(fichier_vide);
  tout_en_minuscule("fichier_vide.txt");

  FILE* fichier_caractere = fopen("fichier_caractere.txt", "w");
  fprintf(fichier_caractere, "Hello world!\n");
  fclose(fichier_caractere);
  tout_en_minuscule("fichier_caractere.txt");

  FILE* fichier_phrase = fopen("fichier_phrase.txt", "w");
  fprintf(fichier_phrase, "Je suis Une personne Qui dit des phrases, puis d'autres phrases et encore Une autre.\n");
  fclose(fichier_phrase);

  tout_en_minuscule("fichier_phrase.txt");
  printf("ok\n");
}

int main(int argc, char *argv[]){
  test_tout_en_minuscule();
  assert(1);
  return EXIT_SUCCESS;
}
