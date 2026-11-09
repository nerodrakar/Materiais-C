#include <stdio.h>

int main(){

    FILE *arquivo;

    arquivo = fopen("arquivo.txt", "r");
    if (arquivo){
        
        char c;
        while ((c = fgetc(arquivo)) != EOF){
            printf("%c", c);
        }
        fclose(arquivo);
    }
}