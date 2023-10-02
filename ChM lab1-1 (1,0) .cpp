#include <iostream>
using namespace std;
void outputVector(double vectorB[], const int size);
void outputMatrix( const int size, double matrix[3][3]);


int main()
{
	double a;
	const int n = 3;
	double vectorB[n] = { 15.71, 43.78, 37.11 };
	for (int i = 0; i <= 2; i++) {
		cout << vectorB[i] << " ";
	}
	cout << endl;
	double matrix[n][n];
	matrix[0][0] = 2.75; matrix[1][0] = 1.78; matrix[2][0] = 1.11;
	matrix[0][1] = 3.28; matrix[1][1] = 0.71; matrix[2][1] = 1.15;
	matrix[0][2] = 1.15; matrix[1][2] = 2.70; matrix[2][2] = 3.58;
	outputVector(vectorB, n);
	outputMatrix(n, matrix);
	
	double max = matrix[0][0];
	int maxSt = 0;
	for (int i = 0; i <= 2; i++) {
		if (max < matrix[0][i]) {
			max = matrix[0][i];
			maxSt = i;
		}


	}
	//обмен строк (1 строка и строка с самым большим первым элементом мен€ютс€ местами)
	if (maxSt != 0) {
		for (int i = 0; i <= 2; i++) {
			swap(matrix[i][0], matrix[i][maxSt]);
		}
		swap(vectorB[0], vectorB[maxSt]);
	}
	outputVector(vectorB, n);
	outputMatrix(n, matrix);
	double number1 = matrix[0][0]; // поэлементно делим первую строку на первый элемент строки
	for (int i = 0; i <= 2; i++) {
		matrix[i][0] = matrix[i][0] / number1;
		
	}
	vectorB[0] /= number1;
	outputVector(vectorB, n);
	outputMatrix(n, matrix);
	double gaussMatrixHelp[3]; //столблец, где записаны первые члены 2 и 3 строки матрицы
	for (int i = 1; i <= 2; i++) {
		gaussMatrixHelp[i] = matrix[0][i];
	}
	for (int j = 1; j <= 2; j++) {
		for (int i = 0; i <= 2; i++) {
			matrix[i][j] -= matrix[i][0]* gaussMatrixHelp[j];
			
		}
		vectorB[j] -= vectorB[0] * gaussMatrixHelp[j];
	}
	outputVector(vectorB, n);
	outputMatrix(n, matrix);
	max = matrix[0][0];
	maxSt = 1;
	if (maxSt != 1) {
		for (int i = 1; i <= 2; i++) {
			swap(matrix[i][1], matrix[i][maxSt]);
		}
		swap(vectorB[1], vectorB[maxSt]);
	}
	if (maxSt != 1) {
		for (int i = 1; i <= 2; i++) {
			swap(matrix[i][1], matrix[i][maxSt]);
		}
		swap(vectorB[1], vectorB[maxSt]);
	}
	number1 = matrix[1][1]; // поэлементно делим 2 строку на 2 элемент строки
	for (int i = 1; i <= 2; i++) {
		matrix[i][1] = matrix[i][1] / number1;

	}
	vectorB[1] /= number1;
	outputVector(vectorB, n);
	outputMatrix(n, matrix);
}
void outputVector(double vectorB[], const int size) {
	cout << "vector B= ";
	for (int i = 0; i <= size-1; i++) {
		cout << vectorB[i] << " ";
	}
}
void outputMatrix(const int size, double matrix[3][3]) {
	cout << endl << "matrix= " << endl;
	for (int j = 0; j <= size-1; j++) {
		for (int i = 0; i <= size-1; i++) {

			cout << matrix[i][j] << " ";

		}
		cout << endl;
	}
}
