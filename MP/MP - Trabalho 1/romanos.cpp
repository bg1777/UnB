#include "romanos.hpp"

bool mais_de_quatro_repeticoes(const char *num_romano) {
    int frequencia[7] = {0};
    for (int i = 0; num_romano[i] != '\0'; i++) {
        char caractere = num_romano[i];
        switch (caractere) {
            case 'I':
                frequencia[0]++;
                break;
            case 'V':
                frequencia[1]++;
                break;
            case 'X':
                frequencia[2]++;
                break;
            case 'L':
                frequencia[3]++;
                break;
            case 'C':
                frequencia[4]++;
                break;
            case 'D':
                frequencia[5]++;
                break;
            case 'M':
                frequencia[6]++;
                break;
        }
    }

    for (int i = 0; i < 7; i++) {
        if (frequencia[i] > 4) {
            return true;
        }
    }

    return false;
}

bool tem_repeticao_consecutiva(const char *num_romano) {
    int contador = 1;
    char caractere_anterior = num_romano[0];
    for (int i = 1; num_romano[i] != '\0'; i++) {
        if (num_romano[i] == caractere_anterior) {
            contador++;
            if (contador > 3) {
                return true;
            }
        } else {
            contador = 1;
            caractere_anterior = num_romano[i];
        }
    }
    return false;
}

int valor_romano(char caractere) {
    switch (caractere) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1;
    }
}

int romanos_para_decimal(char const * num_romano) {
    if (mais_de_quatro_repeticoes(num_romano)) {
        return -1;
    }

    if (tem_repeticao_consecutiva(num_romano)) {
        return -1;
    }

    int decimal = 0;

    if (num_romano == nullptr || *num_romano == '\0') {
        return -1;
    }

    for (int i = 0; num_romano[i] != '\0'; i++) {
        int valor_atual = valor_romano(num_romano[i]);
        if (valor_atual == -1) {
            return -1;
        }

        if (num_romano[i + 1] != '\0' && valor_atual < valor_romano(num_romano[i + 1])) {
            if (i > 0 && valor_romano(num_romano[i - 1]) <= valor_atual) {
                return -1;
            }
            int subtracao = valor_romano(num_romano[i + 1]) - valor_atual;
            if (subtracao == 4 || subtracao == 5 || subtracao == 40 || subtracao == 50 || subtracao == 400 || subtracao == 500) {
                decimal -= valor_atual;
            } else {
                return -1;
            }
        } else {
            decimal += valor_atual;
        }
    }

    return decimal;
}
