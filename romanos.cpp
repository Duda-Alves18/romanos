/*Copyright 2021 Maria Eduarda Alves de Sousa*/
#include <iostream>
#include <string>
using std::string;

int romanos(char letras) {
    if (letras== 'I') {
        return 1;
    }
    if (letras== 'V') {
        return 5;
    }
    if (letras== 'X') {
        return 10;
    }
    if (letras== 'L') {
        return 50;
    }
    if (letras== 'C') {
        return 100;
    }
    if (letras== 'D') {
        return 500;
    }
    if (letras== 'M') {
        return 1000;
    }
    return 0;
}
int transformar(string romanos_completo) {
    int i, tamanho, aux = 0, ant = 0, atual = 0, ant2 = 0;
    int ant3 = 0;

    tamanho = romanos_completo.length() ;
    for (i=tamanho ; i>= 0 ; i--) {
        atual = romanos(romanos_completo[i]);

        if (atual == 1) {
            if (ant == 500) {
    
                return -1;
            }
            if (ant == 1000) {
    
                return -1;
            }
        }

        if (atual == 5) {
            if (ant == 5) {
                return -1;
            }
        }

        if (atual == 50) {
            if (ant == 50) {
                return -1;
            }
        }

        if (atual == 500) {
            if (ant == 500) {
                return -1;
            }
        }

        if (atual == 1000 && ant == 1000 && ant2 == 1000 && ant3 == 1000) {
            return -1;
        }

        if (atual == 500 && ant == 500 && ant2 == 500 && ant3 == 500) {
            return -1;
        }

        if (atual == 50 && ant == 50 && ant2 == 50 && ant3 == 50) {
            return -1;
        }

        if (atual == 100 && ant == 100 && ant2 == 100 && ant3 == 100) {
            return -1;
        }
        
        if (atual == 10 && ant == 10 && ant2 == 10 && ant3 == 10) {

            return -1;
        }

        if (atual == 1 && ant == 1 && ant2 == 1 && ant3 == 1) {

            return -1;
        }

        if (romanos(romanos_completo[i])>= ant) {
            aux = aux+romanos(romanos_completo[i]);
            
            if (aux > 3000){
                return -1;
            }
        } else {
            aux = aux-romanos(romanos_completo[i]);
        }

        ant3 = ant2;
        ant2 = ant;
        ant = atual;
    }
    return aux;
}