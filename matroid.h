#ifndef MATROID_H
#define MATROID_H


#include <stdio.h>
#include <stdbool.h>
#include <omp.h>
#include "qvec.h"

size_t MAX_LENGTH = 2048;

typedef struct 
{
	qvec(int,0) *S;
	qvec(int,1) *I;
	bool (*funcion)(int);

}Matroid;


void analizarMatroids(Matroid matroids[],size_t length){
	
	for (int matroidNumber = 0; matroidNumber < length;matroidNumber++){
		for (int i = 0; i < matroids[matroidNumber].S->len ; ++i){
			
			if (matroids[matroidNumber].funcion((qvec_at(matroids[matroidNumber].S,i) ) ) == 1 ){
				qvec_push(matroids[matroidNumber].I,qvec_at(matroids[matroidNumber].S,i));
			}
		}
	}
}

qvec(int,3)* interseccionIs(Matroid matroids[],size_t length){

	qvec(int,3) *respuesta= qvec_new(int,3);

	int interseccion[MAX_LENGTH];
	memset(interseccion,0,MAX_LENGTH*sizeof(int));

	for (int matroidNumber = 0; matroidNumber < length;matroidNumber++){
		for (int i = 0; i < matroids[matroidNumber].I->len ; ++i){
			int numFound = qvec_at(matroids[matroidNumber].I,i);
			interseccion[numFound]++;
		}
	}

	size_t size = sizeof(interseccion)/sizeof(interseccion[0]);

	for (size_t i = 0;i<= size;i++){
		if (interseccion[i] == length){
			qvec_push(respuesta,i);
		}
	}
	
	return respuesta;

}
#endif