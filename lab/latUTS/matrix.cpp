#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int rowA, columnA, rowB, columnB;
	scanf("%d %d", &rowA, &columnA);
	scanf("%d %d", &rowB, &columnB);
	double matA[rowA][columnA] = {};
	double matB[rowB][columnB] = {};
	if(columnA != rowB){
		printf("Tidak bisa dikali\n");
	}else{
		double matResult[rowA][columnB] = {};
		for(int i = 0; i < rowA; i++){
			for(int j = 0; j < columnA; j++){
				scanf("%lf", &matA[i][j]);
			}
		}
		for(int i = 0; i < rowB; i++){
			for(int j = 0; j < columnB; j++){
				scanf("%lf", &matB[i][j]);
			}
		}
		for(int i = 0; i < rowA; i++){
			for(int j = 0; j < columnB; j++){
				for(int k = 0; k < columnA; k++){
					matResult[i][j] += (matA[i][k]*matB[k][j]); 
				}
			}
		}
		for(int i = 0; i < rowA; i++){
			for(int j = 0; j < columnB; j++){
				printf("%.1lf ", matResult[i][j]);
			}
			printf("\n");
		}
	}
}
