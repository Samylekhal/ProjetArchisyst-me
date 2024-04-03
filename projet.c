#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

char *commande;
int delais ;
int iterations;

void TacheUnique(const char *commande) {
    printf("Tache unique: commande '%s'\n", commande);
    system(commande);
}

void TachesDif(const char *commande, int delais, int iterations) {
    int i;
    for (i = 0; i < iterations; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            TacheUnique(commande);
            exit(0);
        } else if (pid < 0) {
            fprintf(stderr, "Erreur lors de la création du processus fils\n");
            exit(1);
        }
        sleep(delais);
    }
    while (wait(NULL) > 0);
    exit(0);
}

void arg4(char *argv[]) {
    commande = argv[1];
    delais = atoi(argv[2]);
    iterations = atoi(argv[3]);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Erreur élement manquant ou mal inséré\nExemple: %s '<commande>' <delais> <iterations>\n", argv[0]);
        return 1;
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
