/**
Fichier markov.h
Auteur(s): TEURTERIE Alexis teurter211
*/
#ifndef __MARKOV_H__
#define __MARKOV_H__

// Vous travaillerez ici

typedef struct markov_s
{
    /* data */
    double * matrice_transition;
    int nb_etats;
    int poids;
} markov_t;

/**
 * La fonction creer_markov_element(unsigned int, int) permet de creer un element markov representant un etat
 * @param seed est un entier qui permet de controler l'aleatoire
 * @param n est un entier qui represente le nombre d'etat à avoir
 * @return un element de markov
*/
markov_t creer_markov_element(unsigned int seed, int n);

/**
 * La fonction creer_markov_chaine(unsigned int, int) permet de creer une chaine de markov
 * @param seed est un entier qui permet de controler l'aleatoire
 * @param n est un entier qui represente le nombre d'etat à avoir
 * @return une chaine de markov
*/
markov_t * creer_markov_chaine(unsigned int seed, int n);

/**
 * La fonction ajout_etat_MC(markov_t *, int, int) permet d'ajouter un etat si la chaine le peut
 * @param mc est une liste d'element de markov
 * @requires mc != NULL
 * @return 0 si erreur sinon 1
*/
int ajout_etat_MC(unsigned int seed, markov_t * mc);

/**
 * La fonction augmt_poids(markov_t *, int, int) permet d'augmenter la probabilite de passer de l'etat 1 à l'etat 2
 * @param mc est une liste d'element de markov
 * @param e1 est l'element de base
 * @param e2 est l'element auquel on augmente la probabilite
 * @requires e1 < MAX_ETAT
 * @requires e2 < MAX_ETAT
 * @requires mc != NULL
 * @return 0 si erreur sinon 1
*/
int augmt_poids(markov_t * mc, int e1, int e2);

/**
 * La fonction prob_e1_e2(markov_t *, int, int) permet de recuperer la probabilite de passer de l'etat 1 à l'etat 2
 * @param mc est une liste d'element de markov
 * @param e1 est l'element de base
 * @param e2 est l'element auquel on veut passer
 * @requires e1 < MAX_ETAT
 * @requires e2 < MAX_ETAT
 * @requires mc != NULL
 * @return la probabilité de passer de e1 à e2
*/
double prob_e1_e2(markov_t * mc, int e1, int e2);

/**
 * La fonction suite_proba_matrice(double *, int) permet de creer un tableau ou les probabilites du tableau liste se cumule successivement
 * @param liste est une tableau de double (des probabilites)
 * @param n est un entier representant le nombre d'elements
 * @requires n < MAX_ETAT
 * @requires somme(liste) == 1
 * @return une liste d'object de type double
*/
double * suite_proba_matrice(double * liste, int n);

/**
 * La fonction next_element(markov_t *, int) permet de recuperer un entier (etat) aleatoirement parmi ceux possible
 * @param mc est une liste d'element de markov
 * @param e est l'element de base
 * @requires e1 < MAX_ETAT
 * @requires mc != NULL
 * @return le prochain element (etat aléatoire)
*/
int next_element_alea(markov_t * mc, int e);

/**
 * La fonction print_MC(markov_t *, int) permet d'afficher la chaine de markov
 * @param mc est une liste d'element de markov
 * @param n est un entier representant un nombre d'etat
 * @requires mc != NULL
*/
void print_MC(markov_t * mc, int n);

/**
 * La fonction destroy_markov_chain(markov_t *) permet d'enlever l'allocation en memoire de la chaine de markov
 * @param mc est une liste d'element de markov
 * @requires mc != NULL
*/
void destroy_markov_chain(markov_t **mc);

#endif
