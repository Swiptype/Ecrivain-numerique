/**
Fichier sauvegarde.h
Auteur(s): KEFI Elias 22103997
*/
#ifndef __SAUVEGARDE_H__
#define __SAUVEGARDE_H__
#include <stdio.h>
// Vous travaillerez ici

void ecrire_dans_fichier(char *texte, char *chemin);

/**
 * La fonction ecrire_dans_fichier(char *texte, char *chemin) permet de creer un fichier texte et d'y insérer un texte.
 * @param texte est la chaîne de caractère a mettre dans le fichier
 * @param chemin est le nom du fichier texte qui sera creer
*/

FILE* ouvrir_fichier_en_ajout(const char* chemin);

/**
 * La fonction ouvrir_fichier_en_ajout(const char* chemin) ouvre uun fichier en mode "ajout" et renvoie le descripteur de fichier
 * @param chemin est le nom du fichier qui vas être creer
 * @return le descripteur de fichier
*/

void ecrire_chaine_dans_fichier(FILE* fichier, const char* chaine);

/**
 * La fonction ecrire_chaine_dans_fichier(FILE* fichier, const char* chaine) permet d'inserer un texte dans un fichier ouvert en mode "ajout"
 * @param fichier est le descripteur du fichier ouvert en mode "ajout"
 * @param chaine est le texte a introduire dans le fichier
*/
#endif
