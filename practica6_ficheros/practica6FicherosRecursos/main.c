//
//  main.c
//  practica5FicherosBinarios
//
//  Created by Administrador on 09/05/2023.
//  Copyright © 2023 Administrador. All rights reserved.
//


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct datosAlumno
{
    int nExp; //número de expediente del alumno
    char nombre[50]; //nombre del alumno
    char apellidos[100]; //apellidos de alumno
};

struct datosAsignatura
{
    int codigo; //código de la asignatura
    char nombreAsig[40]; //nombre de la asignatura
    int curso; //curso en que se imparte
};
struct datosMatriculado
{
    int nExp; //número de expediente del alumno matriculado
    int codigo; //código de la asignatura
    
};

void visualizarAlumnos(char nombre[]);
void visualizarAsignaturas(char nombre[]);
void visualizarMatriculados(char nombre[]);
int menu(void);

int main()
{
    int opc;
    
    do{
        opc = menu();
        switch (opc)
        {
            case 1:visualizarAlumnos("alumnos.bin");
                break;
            case 2: visualizarAsignaturas("asignaturas.bin");
                break;
            case 3: visualizarMatriculados("matriculados.bin");
                break;
                
            default:
                break;
        }
    } while (opc != 0);
    return 1;
}

int menu() {
    int opc;
    do {
        printf("\n1. Visualizar fichero alumnos");
        printf("\n2. Visualizar fichero asignaturas");
        printf("\n3. Visualizar fichero matriculados");
        printf("\n0. SALIR");
        printf("\nIntroduce una opcion: ");
        scanf("%d",&opc);
        
    } while (opc<0 || opc>3);
    return opc;
}

void visualizarAlumnos(char nf[])
{
    FILE *f;
    struct datosAlumno alum;
    
    f = fopen(nf, "rb");
    if (f == NULL) {
        printf("\n Error en la apertura\n");
        
    }
    else
    {
        fread(&alum, sizeof(struct datosAlumno), 1, f);
        while (!feof(f))
        {
            printf("\nExp: %d\t Nombre: %s %s", alum.nExp, alum.nombre, alum.apellidos);
            fread(&alum, sizeof(struct datosAlumno), 1, f);
        }
        printf("\n\n");
        fclose(f);
    }
}

void visualizarAsignaturas(char nf[])
{
    FILE *f;
    struct datosAsignatura asig;
    
    f = fopen(nf, "rb");
    if (f == NULL) { printf("\n Error en la apertura\n"); }
    else
    {
        
        fread(&asig, sizeof(struct datosAsignatura), 1, f);
        while (!feof(f))
        {
            printf("\nCodigo: %d\t NombreAsignatura: %s\t Curso: %d", asig.codigo, asig.nombreAsig, asig.curso);
            fread(&asig, sizeof(struct datosAsignatura), 1, f);
        }
        printf("\n\n");
        fclose(f);
    }
}
void visualizarMatriculados(char nf[])
{
    FILE *f;
    struct datosMatriculado m;
    
    f = fopen(nf, "rb");
    if (f == NULL) { printf("\n Error en la apertura\n"); }
    else
    {
        
        fread(&m, sizeof(struct datosMatriculado), 1, f);
        while (!feof(f))
        {
            printf("\nExp: %d\t CodigoAsignatura: %d", m.nExp, m.codigo);
            fread(&m, sizeof(struct datosMatriculado), 1, f);
        }
        printf("\n\n");
        fclose(f);
    }
}



