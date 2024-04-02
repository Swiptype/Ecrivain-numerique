#include"markov.h"
/**
Fichier markov.c
Auteur(s): TEURTERIE Alexis teurter211
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ETAT 10  

/**
 * La fonction creer_markov_element(unsigned int, int) permet de creer un element markov representant un etat
 * @param seed est un entier qui permet de controler l'aleatoire
 * @param n est un entier qui represente le nombre d'etat à avoir
 * @return un element de markov
*/
markov_t creer_markov_element(unsigned int seed, int n) {
    srand(seed);
    markov_t new_m;
    new_m.nb_etats = n;
    new_m.poids = n;
    new_m.matrice_transition = malloc(MAX_ETAT * sizeof(double));
    double total_prob = 0;
    for (size_t i = 0; i < n; i++)
    {
        /* code */
        new_m.matrice_transition[i] = (double) rand() / RAND_MAX;
        total_prob += new_m.matrice_transition[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        /* code */
        new_m.matrice_transition[i] /= total_prob;
    }
    return new_m;
}

/**
 * La fonction creer_markov_chaine(unsigned int, int) permet de creer une chaine de markov
 * @param seed est un entier qui permet de controler l'aleatoire
 * @param n est un entier qui represente le nombre d'etat à avoir
 * @return une chaine de markov
*/
markov_t * creer_markov_chaine(unsigned int seed, int n) {
    markov_t * mc = malloc( MAX_ETAT * (MAX_ETAT * sizeof(double) + 2 * sizeof(int) ) );
    
    for (int j = 0; j < MAX_ETAT; j++)
    {
        /* code */
        mc[j] = creer_markov_element(seed,n); 
        mc[j].poids = 0;
    }
    printf("Done\n");
    return mc;    
}

/**
 * La fonction ajout_etat_MC(markov_t *, int, int) permet d'ajouter un etat si la chaine le peut
 * @param mc est une liste d'element de markov
 * @requires mc != NULL
 * @return 0 si erreur sinon 1
*/
int ajout_etat_MC(unsigned int seed, markov_t * mc) {

    if (mc[0].nb_etats == MAX_ETAT)
    {
        /* code */
        return 0;
    }

    int n = mc[0].nb_etats + 1;

    mc[n-1] = creer_markov_element(seed, n);

    for (int i = 0; i < mc[0].nb_etats; i++)
    {
        /* code */
        mc[i].matrice_transition[mc[i].nb_etats] = 0;
        mc[i].nb_etats++;
    }
    return 1;
    
}

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
int augmt_poids(markov_t * mc, int e1, int e2) {
    if (e1 >= MAX_ETAT || e2 >= MAX_ETAT)
    {
        /* Il y a une erreur */
        printf("Au moins un des parametres est égale ou supérieur au nombre maximal d'états !");
        return 0;
    }

    double total = 0;
    for (int i = 0; i < mc[e1].nb_etats; i++)
    {
        /* On change les probabilites dans la matrice de transition */
        if (i == e2)
        {
            /* Si on est sur l'etat e2 on veut augmenter le taux */
            mc[e1].matrice_transition[i] = (mc[e1].poids * mc[e1].matrice_transition[i] + 1) / (mc[e1].poids + 1);
        } else
        {
            /* Si on n'est pas sur l'etat e2 on veut baiser le taux */
            mc[e1].matrice_transition[i] = (mc[e1].poids * mc[e1].matrice_transition[i]) / (mc[e1].poids + 1);
        }
        total += mc[e1].matrice_transition[i];
    }
    mc[e1].poids += 1; 
    printf("somme des probabilites : %f\n", total);
    return 1;
}

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
double prob_e1_e2(markov_t * mc, int e1, int e2) {
    return mc[e1].matrice_transition[e2];
}


/**
 * La fonction suite_proba_matrice(double *, int) permet de creer un tableau ou les probabilites du tableau liste se cumule successivement
 * @param liste est une tableau de double (des probabilites)
 * @param n est un entier representant le nombre d'elements
 * @requires n < MAX_ETAT
 * @requires somme(liste) == 1
 * @return une liste d'object de type double
*/
double * suite_proba_matrice(double * liste, int n) {
    double * tab_proba = malloc(n * sizeof(double));
    tab_proba[0] = liste[0];
    for (int i = 1; i < n; i++)
    {
        /* code */
        tab_proba[i] = tab_proba[i-1] + liste[i];
    }
    return tab_proba;
}

/**
 * La fonction next_element(markov_t *, int) permet de recuperer un entier (etat) aleatoirement parmi ceux possible
 * @param mc est une liste d'element de markov
 * @param e1 est l'element de base
 * @requires e1 < MAX_ETAT
 * @requires mc != NULL
 * @return le prochain element (etat aléatoire)
*/
int next_element(markov_t * mc, int e) {
    double proba = (double) rand() / RAND_MAX;
    double * tab_proba = suite_proba_matrice(mc[e].matrice_transition, mc[e].nb_etats);
    for (int i = 0; i < mc[e].nb_etats; i++)
    {
        if (proba < tab_proba[i])
        {
            return i;
        }
        
    }
    return MAX_ETAT;
}

/**
 * La fonction print_MC(markov_t *, int) permet d'afficher la chaine de markov
 * @param mc est une liste d'element de markov
 * @param n est un entier representant un nombre d'etat
 * @requires mc != NULL
*/
void print_MC(markov_t * mc, int n) {
    for (int i = 0; i < n; i++)
    {
        /* code */
        for (int j = 0; j < n; j++)
        {
            /* code */
            printf("%f ", mc[i].matrice_transition[j]);
        }
        printf("\n");
    }
}

/**
 * La fonction destroy_markov_chain(markov_t *) permet d'enlever l'allocation en memoire de la chaine de markov
 * @param mc est une liste d'element de markov
 * @requires mc != NULL
*/
void destroy_markov_chain(markov_t **mc) {
    for (int i = 0; i < MAX_ETAT; i++)
    {
        /* code */
        free(mc[i]->matrice_transition);
        //mc[i]->nb_etats = 0;
        //mc[i]->poids = 0;
    }
    free(mc);
    mc = NULL;
}
/*
int main() {
    int seed = 2333;
    int n = 2;
    markov_t * mc = creer_markov_chaine(seed, n);
    print_MC(mc, n);

    ajout_etat_MC(seed, mc);
    n++;

    //On test le changement du poids
    int e1 = 0; int e2 = 2;
    printf("%f\n", prob_e1_e2(mc, e1, e2));
    augmt_poids(mc, e1, e2);
    printf("%f\n", prob_e1_e2(mc, e1, e2));

    //On affiche la chaine de markov
    print_MC(mc, n);

    //On detruit la chaine de markov
    destroy_markov_chain(&mc);
    return 0;
}
*/