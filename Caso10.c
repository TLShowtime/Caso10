#include <stdio.h>
#include <stdbool.h> 
#include "matroid.h"


typedef char* string;

typedef struct {
    int x, y;
} Tuple;

bool buscarImpares(int x){
	if (x %2 != 0){
		return true;
	}
	return false;
}

bool buscarPrimo(int x){
	int divisor = 1;
	int divisores = 0;
	do {
		if (x % divisor == 0){
			divisores++;
		}
		divisor++;
	} while(divisor <= x);

	return divisores == 2; 
}

bool esFibonacci(int x){
	int pre = 0;
	size_t pos = 1;
	while (pre <= x){
		if (pre == x){
			return true;
		}
		int suma = pre + pos;
		pre = pos;
		pos = suma;
	}
	return false;

}

int main()
{
    Matroid M1;
    M1.S = qvec_new(int,0, 1, 2, 3);
    M1.I = qvec_new(int,1);
    M1.funcion = &buscarImpares;

    
    //qvec_print(M1.S);
    //qvec_print(M1.I);
    

    Matroid M2;
	M2.S = qvec_new(int,0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18);
    M2.I = qvec_new(int,1);
    M2.funcion = &buscarPrimo;

    
    //qvec_print(M2.S);
    //qvec_print(M2.I);
    

    Matroid M3;
	M3.S = qvec_new(int,0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,31,41,54,66,100,122,156);
    M3.I = qvec_new(int,1);
    M3.funcion = &esFibonacci;

    
    //qvec_print(M3.S);
    //qvec_print(M3.I);
	

    Matroid matroides[] = {M1,M2,M3};

    size_t size = sizeof(matroides)/sizeof(matroides[0]);

    analizarMatroids(matroides,size);

    qvec_print(matroides[0].S);
    qvec_print(matroides[0].I);
    qvec_print(matroides[1].S);
    qvec_print(matroides[1].I);
    qvec_print(matroides[2].S);
    qvec_print(matroides[2].I);
    printf("\n");
    

	Matroid M4;
    M4.S = qvec_new(int,0, 1, 2, 3,4,5,6,7,8,9,10,14,15,87,132,123);
    M4.I = qvec_new(int,1);
    M4.funcion = &buscarImpares;

    Matroid M5;
    M5.S = qvec_new(int,0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18);
    M5.I = qvec_new(int,1);
    M5.funcion = &buscarImpares;
    
    Matroid M6;
    M6.S = qvec_new(int,0,1,6,7,8,9,10,11,12,13,14,15,16,17,18);
    M6.I = qvec_new(int,1);
    M6.funcion = &buscarImpares;

    Matroid M7;
    M7.S = qvec_new(int,0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,21,31,41,60,70);
    M7.I = qvec_new(int,1);
    M7.funcion = &buscarImpares;

    Matroid M8;
    M8.S = qvec_new(int,0,1,14,15,16,17,18,20,30,40,50);
    M8.I = qvec_new(int,1);
    M8.funcion = &buscarImpares;

    Matroid matroidsTwo[] = {M4,M5,M6,M7,M8};

    size = sizeof(matroidsTwo)/sizeof(matroidsTwo[0]);

    analizarMatroids(matroidsTwo,size);
    


    qvec(int,3) *M_Inter = interseccionIs(matroidsTwo,size);

    qvec_print(matroidsTwo[0].I);
    qvec_print(matroidsTwo[1].I);
    qvec_print(matroidsTwo[2].I);
    qvec_print(matroidsTwo[3].I);
    qvec_print(matroidsTwo[4].I);
    printf("Interseccion I es: ");
    qvec_print(M_Inter);



    qvec_free(M1.S);
    qvec_free(M1.I);
    qvec_free(M2.S);
    qvec_free(M2.I);
    qvec_free(M3.S);
    qvec_free(M3.I);
    qvec_free(M4.S);
    qvec_free(M4.I);
    qvec_free(M5.S);
    qvec_free(M5.I);
    qvec_free(M6.S);
    qvec_free(M6.I);
    qvec_free(M7.S);
    qvec_free(M7.I);
    qvec_free(M8.S);
    qvec_free(M8.I);

    qvec_free(M_Inter);
    
}