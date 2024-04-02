#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include"../src/hachage.h"

void test_create_hash_table(){
  int size = 4;

  printf("Test création table hachage\n");
  hachage_t* hachage = create_hash_table(size);
  assert(hachage);
  // destroy_hash_table(&hachage);
  // assert(&hachage == NULL);
  printf("ok\n");
}

void test_hash(){
  int size = 4;
  const char *key = "a";

  printf("Test hash\n");
  unsigned int indice = hash( key, size);
  assert((indice > 0) && (indice <= (size-1)));
  printf("ok\n");
}


void test_search(){
  int size = 4;
  const char *key = "a";

  printf("Test de recherche\n");
  hachage_t* hachage = create_hash_table(size);
  int recherche = search(hachage, key);
  assert(recherche = key);
  assert(recherche = -1);
  printf("ok\n");
}

void test_retrieve_key(){
  int id = 4;
  int size = 4;
  const char *key = "a";
  
  printf("Test de recherche de pointeur vers la clé\n");
  hachage_t* hachage = create_hash_table(size);
  char * carac = retrieve_key(hachage, id);
  assert(&carac);
  printf("ok\n");
}

int main(int argc, char *argv[]){
  test_create_hash_table();
  test_hash();
  test_search();
  test_retrieve_key();
  assert(1);
  return EXIT_SUCCESS;
}



