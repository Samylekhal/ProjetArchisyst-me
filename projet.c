#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

void TacheUnique(const char *commande) {
    printf("Tache unique: commande '%s'\n", commande);
    system(commande);
}


void TachesDif(const char *commande, int delais, int iterations) {
    int i;
    for (i = 0; i < iterations; i++) {
        printf("Iteration n°%d: commande '%s'\n", i+1, commande);
        system(commande);
        sleep(delais);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s '<commande>' <delais> <iterations>\n", argv[0]);
        return 1;
    }

    char *commande = argv[1];
    int delais = atoi(argv[2]);
    int iterations = atoi(argv[3]);

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
