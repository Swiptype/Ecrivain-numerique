/**
Fichier hachage.c
Auteur(s): Genestier Théo 22106104
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hachage.h"

/* Crée une table de hachage de taille donnée */
hachage_t *create_hash_table(int size) {
    hachage_t *table = malloc(sizeof(hachage_t));
    table->size = size;
    table->count = 0;
    table->table = calloc((size_t)table->size, sizeof(entry_t*));
    return table;
}

/* Détruit une table de hachage */
void destroy_hash_table(hachage_t *table) {
    int i;
    for (i = 0; i < table->size; i++) {
        entry_t *entry = table->table[i];
        if (entry != NULL) {
            free(entry->key);
            free(entry);
        }
    }
    free(table->table);
    free(table);
}

/* Calcule le hash d'une clé */
unsigned int hash(const char *key, int size) {
    unsigned int hashval = 0;
    int i;
    for (i = 0; key[i] != '\0'; i++) {
        hashval = key[i] + (hashval << 5) - hashval;
    }
    return hashval % size;
}

/* Insère une entrée dans la table de hachage */
void insert(hachage_t *table, const char *key, int id) {
    entry_t *new_entry = malloc(sizeof(entry_t));
    new_entry->key = strdup(key);
    new_entry->id = id;
    new_entry->next = NULL;

    /* Calcule l'indice de la table à partir de la clé */
    unsigned int hashval = hash(key, table->size);

    /* Si l'indice est déjà pris, résoudre la collision */
    if (table->table[hashval] != NULL) {
        entry_t *next = table->table[hashval];
        while (next->next != NULL) {
            next = next->next;
        }
        next->next = new_entry;
    } else {
        table->table[hashval] = new_entry;
    }
    table->count++;
}

/* Recherche une clé dans la table de hachage */
int search(hachage_t *table, const char *key) {
    /* Calcule l'indice de la table à partir de la clé */
    unsigned int hashval = hash(key, table->size);

    /* Si l'indice est déjà pris, rechercher dans la liste chaînée */
    entry_t *entry = table->table[hashval];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return hashval;
        }
        entry = entry->next;
    }
    return -1;
}

/* Récupère la clé associée à un identifiant */
char *retrieve_key(hachage_t *table, int id) {
    int i;
    for (i = 0; i < table->size; i++) {
        entry_t *entry = table->table[i];
        while (entry != NULL) {
            if (entry->id == id) {
                return entry->key;
            }
            entry = entry->next;
        }
    }
    return NULL;
}