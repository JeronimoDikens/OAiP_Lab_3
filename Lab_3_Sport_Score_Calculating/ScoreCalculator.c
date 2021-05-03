#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int setterCountReferee() {
	int ref;
	printf("Please, enter the number of referees. More of 2 and less of 11. \n");
	scanf_s("%d", &ref);
	if (!(ref < 3 || ref>10)) {
		printf("Number of referees set as %d \n\n", ref);
		return ref;
	}
	else {
		printf("Number of referees set as 10 \n\n");
		ref = 10;
		return ref;
	}
}

int setterCountSportsmans() {
	int ref;
	printf("Please, enter the number of sportsmans . More of 2 and less of 11. \n");
	scanf_s("%d", &ref);
	if (!(ref < 3 || ref>10)) {
		printf("Number of sportsmans set as %d \n\n", ref);
		return ref;
	}
	else {
		printf("Number of sportsmans set as 10 \n\n");
		ref = 10;
		return ref;
	}
}

void arrayPrinter(float** array, int n, int m) {
	for (int i = 0; i < n; i += 1) {
		printf("\n");
		for (int j = 0; j < m; j += 1) {
			printf("%4.2f \t", array[i][j]);
		}
	}
	printf("\n\n");
}
float** arrayCreator(int n, int m) {
	printf("The table of results was created with: \n Sportsman %d \n Referees %d\n\n", n, m);

	float** array;
	array = (float**)calloc(n, sizeof(float));

	for (int i = 0; i < n; i += 1) {
		array[i] = (float*)calloc(m, sizeof(float));
	}

	return array;
}

void setterMarkArray(float** array, int n, int m) {
	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < m; j += 1) {
			array[i][j] = (float)(rand() % 10);
		}
	}

	printf("\nReferees left their marks");
	arrayPrinter(array, n, m);
}


void sorterMarkArray(float** array, int n, int m) {
	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < m - 1; j += 1) {
			for (int k = 0; k < m - 1; k += 1) {
				if (array[i][k] > array[i][k + 1]) {
					float temp = array[i][k];
					array[i][k] = array[i][k + 1];
					array[i][k + 1] = temp;
				}
			}
		}
	}
}

void calcMean(float** array, int n, int m) {
	float mean_num;
	for (int i = 0; i < n; i += 1) {
		mean_num = 0;
		printf("\n");
		for (int j = 1; j < m - 1; j += 1) {
			printf("%4.2f\t", array[i][j]);
			mean_num += array[i][j];
		}
		printf("\t mean value %4.2f", (mean_num / (m - 2)));
	}
}



int main() {


	int numberSport = setterCountSportsmans();
	int numberRef = setterCountReferee();


	float** tableOfResults;

	tableOfResults = arrayCreator(numberSport, numberRef);

	setterMarkArray(tableOfResults, numberSport, numberRef);

	sorterMarkArray(tableOfResults, numberSport, numberRef);

	arrayPrinter(tableOfResults, numberSport, numberRef);

	calcMean(tableOfResults, numberSport, numberRef);

	free(tableOfResults);
	return 0;
}