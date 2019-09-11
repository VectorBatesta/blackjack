#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

typedef struct hand{
    int valor;
    char naipe;
    char carta;
}handstr;

int main() {
    int querjogar = 1;
    while(querjogar==1) {
        int done = 0;

        handstr hand[21];
        for (int i = 21; i >= 0; i--)
            hand[i] = '#';

        char resposta;
        printf("Quer jogar BlAcKjAcK?/?1?? XD\n[Y/N] Resposta: \n");
        scanf("%c", &resposta);

        if (resposta == 'n') {
            printf("\nfalow vei");
            return 0;
        }

        int quant=0;

        int cartanum;
        char cartacha[] = {'A', 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K'};
        char naipe[] = {'o', 'e', 'c', 'p'};

        int foipego[52];
        for(int i = 0; i<52; i++)
            foipego[i] = 0;

        while(quant<2) {
            while (done == 0) {
                cartanum = rand() % 52;
                if (foipego[cartanum] != 1){
                    foipego[cartanum] = 1;
                    done = 1;

                    hand[quant].naipe = naipe[cartanum / 13];
                    hand[quant].valor = cartanum % 13;
                    hand[quant].carta = cartacha[cartanum % 13];
                }
            }
            quant++;
        }

        while(hand->valor <= 21) {
            printf("QUAL SUA SELECAO??"
                   "\n1-mais carta"
                   "\n2-stop");
            scanf("%i", &resposta);
            if (resposta == 1) {
                while (done == 0) {
                    cartanum = rand() % 52;
                    if (foipego[cartanum] != 1) {
                        foipego[cartanum] = 1;
                        done = 1;

                        hand[quant].naipe = naipe[cartanum / 13];
                        hand[quant].valor =+ cartanum % 13;
                        hand[quant].carta = cartacha[cartanum % 13];
                    }
                }
                quant++;
            }
        }
    }

    return 0;
}
