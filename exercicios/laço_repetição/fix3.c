#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Crie um algoritmo que informe se o valor lido é primo ou não. Um número primo é aquele que é divisível apenas por 1 e por ele mesmo.
int main(){
        setlocale(LC_ALL, ".UTF8");
        
        int num, i, count = 0;
    
        printf("Digite um número: ");
        scanf("%d", &num);
    
        for(i = 1; i <= num; i++){
            if(num % i == 0){
                count++;
            }
        }
    
        if(count == 2){
            printf("%d é um número primo.\n", num);
        } else {
            printf("%d não é um número primo.\n", num);
        }
    
        return 0;
    }