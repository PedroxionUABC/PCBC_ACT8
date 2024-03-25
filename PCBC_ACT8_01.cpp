// Pedro Carlos Balderrama Campos
//
// Fecha: 24 de marzo del 2024
// PCBC_ACT8_01.cpp
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// Valores constantes
#define te 10
#define rango_minimo 30
#define rango_maximo 70
// Vectores globales
int vec1[te];
int vec2[te];
int vec3[te * 2];
int mat[4][5];
// Prototipos
void pdr_printOptions();
void clear();
void menu();
int evaluarRango(int x);
void pause();
// Prototipos especificos
void vec_manual();
void vec_random();
void vec_fusion();
void vec_print_all();
void mat_fill();
void mat_print();
void imprimirVector3();
// main
int main()
{
    int a, b;
    srand(time(NULL));
    menu();
    return 0;
}
//
void pdr_printOptions()
{
    clear();
    printf("\n1.- Llenar el vector 1 manualmente\n");
    printf("2.- Llenar el vector 2 aleatorimente\n");
    printf("3.- Llenar el vector 3 con vector 1 y 2\n");
    printf("4.- Imprimir vectores\n");
    printf("5.- Llenar matriz 4x5\n");
    printf("6.- Imprimir matriz\n");

    printf("0.- Salir\n");
}
// menu
void menu()
{
    char op[5];
    int menuOption = 0;
    do
    {
        pdr_printOptions();
        printf("\nIngresa una opcion: ");
        fflush(stdin);
        gets(op);
        menuOption = atoi(op);
        switch (menuOption)
        {
        case 1:
            vec_manual();
            break;
        case 2:
            vec_random();
            break;
        case 3:
            vec_fusion();
            imprimirVector3();
            break;
        case 4:
            vec_print_all();
            break;
        case 5:
            mat_fill();
            break;
        case 6:
            mat_print();
            break;
        case 0:
            break;
        default:
            printf("\nOpción no válida\n");
        }
    } while (menuOption != 0);
}
// Funciones

void pdr_stringCopyTo1(int a[te])
{
    for (int i = 0; i < te; i++)
    {
        vec1[i] = a[i];
    }
}
void pdr_stringCopyTo2(int a[te])
{
    for (int i = 0; i < te; i++)
    {
        vec2[i] = a[i];
    }
}
void vec_fusion()
{
    int i, j = 0;
    for (i = 0; i < te; i++)
    {
        vec3[i] = vec1[i];
    }
    for (; i < te * 2; i++)
    {
        vec3[i] = vec2[j];
        j++;
    }
}
void vec_manual()
{
    clear();
    char num[5];
    int vec_man[te];
    printf("\nNota: los numeros tienen que estar en un rango entre 30 y 70\n\n");
    for (int i = 0; i < te; i++)
    {
        printf("Escribe el valor #%d del vector: ", i + 1);
        // Lo que vimos en clase para convertir char --> entero
        fflush(stdin);
        gets(num);
        vec_man[i] = atoi(num);
        //
        if (evaluarRango(vec_man[i]) != 1)
        {
            printf("\nNo escribiste un numero que estuviera dentro del rango\n");
            i--;
        }
    }
    printf("\nSe capturo el vector con exito!\n");
    pause();
    pdr_stringCopyTo1(vec_man);
}
void vec_random()
{
    clear();
    printf("\n");
    int vec_ran[te], unique;
    for (int i = 0; i < te; i++)
    {
        do
        {
            unique = 1;
            vec_ran[i] = 1 + rand() % (21 - 1);
            for (int j = 0; j < i; j++)
            {
                if (vec_ran[j] == vec_ran[i])
                {
                    unique = 0;
                    break;
                }
            }
        } while (!unique);
        printf("El valor #%d es igual a: %d\n", i + 1, vec_ran[i]);
    }
    pause();
    pdr_stringCopyTo2(vec_ran);
}
void vec_print_all()
{
    clear();
    for (int i = 0; i < te; i++)
    {
        printf("El valor #%d del vector #1 es: %d\n", i + 1, vec1[i]);
    }
    printf("\n");
    for (int i = 0; i < te; i++)
    {
        printf("El valor #%d del vector #2 es: %d\n", i + 1, vec2[i]);
    }
    printf("\n");
    for (int i = 0; i < te * 2; i++)
    {
        printf("El valor #%d del vector #3 es: %d\n", i + 1, vec3[i]);
    }
    pause();
}
void mat_fill()
{
    clear();
    int l = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (l < te * 2)
            {
                mat[i][j] = vec3[l];
                l++;
            }
        }
    }
    printf("Matriz de 4x5 llenada con exito!");
    pause();
}
void mat_print()
{
    clear();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    pause();
}
// Prototipos menos importantes
int evaluarRango(int x)
{
    if (x >= rango_minimo && x <= rango_maximo)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void clear()
{
    system("clear");
}
void pause()
{
    fflush(stdin);
    printf("\nPresiona Enter para continuar...");
    getchar();
}
void imprimirVector3()
{
    clear();
    for (int i = 0; i < te * 2; i++)
    {
        printf("El valor #%d es: %d\n", i + 1, vec3[i]);
    }
    pause();
}