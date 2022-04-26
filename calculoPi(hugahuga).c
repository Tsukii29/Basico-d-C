#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float calculoPi(int quantidadedePontos){

    float i = 0, y = 0, x = 0, distancia = 0, dentro = 0, conta = 0;

     srand(time(NULL));
    float max = RAND_MAX;

        for (i = 0; i < quantidadedePontos; i++){
            x = rand();
            y = rand();
            x = x / max;
            y = y / max;
            distancia = sqrt(y * y + x * x);
            if (distancia <= 1){
                dentro++;
            }
        }
    conta = 4 * dentro / quantidadedePontos;
    return conta;
    printf("obrigado pela paciencia huga huga");
}

int main(void){

    printf("%f\n", calculoPi(10));
    printf("%f\n", calculoPi(100));
    printf("%f\n", calculoPi(1000));
    printf("%f\n", calculoPi(10000));

    return 0;
}
