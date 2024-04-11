#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include "projet.h"


void TacheUnique(const char *commande) {
    printf("Tache unique: commande '%s'\n", commande);
    system(commande);
}

void TachesDif(const char *commande, int delais, int iterations) {
    int i;
    for (i = 0; i < iterations; i++) {
        pid_t pid = fork(); // Créer un processus enfant
        if (pid == 0) { 
            TacheUnique(commande);
            exit(0); // Quitter le processus enfant
        } else if (pid < 0) { // Quitter le programme avec un code d'erreur si une erreur s'est produite lors de la création du processus enfant
            fprintf(stderr, "Erreur lors de la création du processus fils\n");
            exit(1); 
        }
        sleep(delais); // Délai entre chaque exécution
    }
    while (wait(NULL) > 0); // Attendre que tous les processus enfants se terminent pour quitter le programme
    exit(0); 
}
void arg4(char *argv[]) {
    commande = argv[1];
    delais = atoi(argv[2]);
    iterations = atoi(argv[3]);
}


int main(int argc, char *argv[]) {
    if (argc != 4)
    {
        printf("erreur dans la mise en place des arguments du programme veuillez suivre les indications suivantes:\n");
        printf("Usage: %s <commande> <delais> <iterations>\n", argv[0]);
        return 0;
    }
    arg4(argv);
    







    printf("Taches différés:\n");
    printf("Commande: %s\n", commande);
    printf("Delais: %d secondes\n", delais);
    printf("Iterations: %d\n", iterations);

    printf("Confirmer le programme ? (y/n): ");
    char confirm;
    scanf(" %c", &confirm);
    if (confirm == 'y' || confirm == 'Y') {
        TachesDif(commande, delais, iterations);
    }
    return 0;
}
