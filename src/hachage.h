/**
Fichier hachage.h
Auteur(s): Genestier Théo 22106104
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

// Vous travaillerez ici

typedef struct {
    char *key;
    int id;
    struct entry_t *next;
} entry_t;

typedef struct {
    int size;
    entry_t **table;
    unsigned int count;
} hachage_t;

hachage_t *create_hash_table(int size);
void destroy_hash_table(hachage_t *table);
unsigned int hash(const char *key, int size);
void insert(hachage_t *table, const char *key, int id);
int search(hachage_t *table, const char *key);
char *retrieve_key(hachage_t *table, int id);

#endif


/*
Fonction hachage_t *create_hash_table(int size)

@param : Un entier "size" représentant la taille souhaitée pour la table de hachage.

@result : Un pointeur vers une nouvelle table de hachage initialisée.

@require : La taille de la table de hachage "size" doit être positive.

@ensure : La fonction retourne un pointeur vers une nouvelle table de hachage initialisée avec une taille égale à "size" et ne contenant aucune entrée.

-------------------------------------------------------------------------

Fonction destroy_hash_table(hachage_t *table)

@param : Un pointeur vers une table de hachage "table" de type hachage_t à détruire.

@result : Aucun

@require : Le pointeur vers la table de hachage "table" doit être valide et initialisé.

@ensure : La mémoire allouée pour la table de hachage "table" est libérée.

-------------------------------------------------------------------------

Fonction hash(const char *key, int size)

@param : Une chaîne de caractères "key" représentant la clé à hacher.
@param : Un entier "size" représentant la taille de la table de hachage.

@result : Un entier représentant l'indice de hachage de la clé.

@require : La chaîne de caractères "key" doit être valide et non NULL.
@require : La taille de la table de hachage "size" doit être positive.

@ensure : La fonction retourne un indice de hachage compris entre 0 et "size - 1" inclus.

-------------------------------------------------------------------------

Fonction insert(hachage_t *table, const char *key, int id)

@param : Un pointeur vers une table de hachage "table" de type hachage_t.
@param : Une chaîne de caractères "key" représentant la clé à insérer dans la table de hachage.
@param : Un entier "id" représentant l'identifiant associé à la clé.

@result : Aucun

@require : Le pointeur vers la table de hachage "table" doit être valide et initialisé.
@require : La chaîne de caractères "key" doit être valide et non NULL.

@ensure : La table de hachage "table" contient une nouvelle entrée avec la clé "key" et l'identifiant "id".

-------------------------------------------------------------------------

Fonction search(hachage_t *table, const char *key)

@param : Un pointeur vers une table de hachage "table" de type hachage_t.
@param : Une chaîne de caractères "key" représentant la clé à rechercher dans la table de hachage.

@result : Un entier représentant l'indice de la table de hachage correspondant à la clé recherchée s'il existe.
@result : -1 si la clé n'est pas trouvée dans la table de hachage.

@require : Le pointeur vers la table de hachage "table" doit être valide et initialisé.
@require : La chaîne de caractères "key" doit être valide et non NULL.

@ensure : Si la clé est trouvée dans la table de hachage, la fonction retourne l'indice de la table correspondant à la clé.
@ensure : Si la clé n'est pas trouvée dans la table de hachage, la fonction retourne -1.

-------------------------------------------------------------------------

Fonction retrieve_key(hachage_t *table, int id)

@param : table : pointeur vers la table de hachage à partir de laquelle la clé doit être récupérée.
@param : id : identifiant de la clé à récupérer.

@result : Un pointeur vers la clé associée à l'identifiant donné, ou NULL si l'identifiant n'est pas trouvé dans la table.

@require : table doit être un pointeur valide vers une table de hachage initialisée.
@require : id doit être un entier valide.

@ensure : Si l'identifiant est trouvé dans la table, la fonction renvoie un pointeur valide vers la clé associée à cet identifiant.
@ensure : Si l'identifiant n'est pas trouvé dans la table, la fonction renvoie NULL.

*/