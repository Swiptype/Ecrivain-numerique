#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include"../src/markov.h"

void test_markov_create_destroy(){
  unsigned int seed = 123;
  int n = 2;

  printf("Test création chaine de markov\n");
  markov_t* markov = creer_markov_chaine(seed, n);
  assert(markov);
  // destroy_markov_chain(&markov);
  // assert(&markov == NULL);
  printf("ok\n");
}

void test_ajout_etat_MC(){
  unsigned int seed = 123;
  int n = 2;

  printf("Test ajout état\n");
  markov_t* markov = creer_markov_chaine(seed, n);
  int erreur = ajout_etat_MC(seed, markov);
  assert(erreur == 1);
  printf("ok\n");
}

void test_augmt_poids(){
  unsigned int seed = 123;
  int n = 2;
  int e1,e2;

  printf("Test augmentation poids\n");
  markov_t* markov = creer_markov_chaine(seed, n);
  int erreur = augmt_poids(markov, e1, e2);
  assert(erreur = 1);
  printf("\nok\n");
}

void test_prob_e1_e2(){
  unsigned int seed = 123;
  int n = 2;
  int e1 = 0,e2 = 1;

  printf("Test probabilités e1 e2\n");
  markov_t* markov = creer_markov_chaine(seed, n);
  double probabilite = prob_e1_e2(markov, e1, e2);
  assert(probabilite = 1);
  printf("ok\n");
}

void test_suite_proba_matrice(){
  unsigned int seed = 123;
  int n = 2;
  double* liste;

  printf("Test suite de probabilité\n");
  double * etat = suite_proba_matrice(liste,n);
  for(int i=0; i<n;i++){
    assert(etat[i] >0);
  }
  printf("ok\n");
}

void test_next_element_alea(){
  unsigned int seed = 123;
  int n = 2;
  int e = 0;

  printf("Test deplacement\n");
  markov_t* markov = creer_markov_chaine(seed, n);
  int element_suivant = next_element(markov, e);
  assert(element_suivant = 10);
  printf("ok\n");
}

int main(int argc, char *argv[]){
  test_markov_create_destroy();
  test_ajout_etat_MC();
  test_augmt_poids();
  test_prob_e1_e2();
  test_suite_proba_matrice();
  test_next_element_alea();
  assert(1);
  return EXIT_SUCCESS;
}

