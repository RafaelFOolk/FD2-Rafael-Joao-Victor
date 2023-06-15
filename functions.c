#include "functions.h"
#include <stdio.h>

void Get_String(char name[], int size) {

	setbuf(stdin,NULL);
	fgets(name, size, stdin);
	name[strcspn(name, "\n")] = '\0';
};

void Get_Vector(int name[], int size){

	setbuf(stdin,NULL);
	for(int a = 0; a < size; a++){
		scanf("%d", &name[a]);
	}
};

void Print_Vector(int name[], int size){

	setbuf(stdin,NULL);
	for(int a = 0; a < size; a++){
		printf("%d ", name[a]);
	}
};

void Get_Matrix(int row, int column, int name[row][column]){

	setbuf(stdin,NULL);
	for(int a = 0; a < row; a++){
		for (int b = 0; b < column; b++){
			printf("[%d][%d] = ", a, b);
			scanf("%d", &name[a][b]);
		}
	}
};

void Print_Matrix(int row, int column, int name[row][column]){

	setbuf(stdin,NULL);
	for(int a = 0; a < row; a++){
		for(int b = 0; b < column; b++){
			printf("[%d][%d] = %d\n", a, b, name[a][b]);
		}
	}
};
