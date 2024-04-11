#ifndef PROJET_H
#define PROJET_H

// les variables globales

// une chaine de caractère contenant la commande à executer
char *commande;

// le delais en seconde entre chaque répétition de la commande
int delais ;

// le nombre de répétitions de la commande
int iterations;



// les fonctions

/**
 * @brief 
 * Execute la commande donnée en argument avec la fonction system
 * @param commande
 * La commande à executer
*/
void TacheUnique(const char *commande);


/**
 * @brief 
 * Execute la commande de manière différée avec un fork en se basant sur le delais et le nombre d'itérations
*/
void TachesDif(const char *commande, int delais, int iterations);

/**
 * @brief 
 * Transpose les valeurs des arguments dans les variables commandes, delais et iterations
 * @param argv
 * Le tableau des arguments
*/
void arg4(char *argv[]);

#endif