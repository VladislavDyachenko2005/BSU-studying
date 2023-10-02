#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void outputVector(double vectorB[], const int size);
void outputMatrix(double vectorB[], const int size, double matrix[3][3]);
void rounding (double* a, int accur);


int main()
{
	double a, round;
	const int n = 3;
	int accur=100000;
	double vectorB[n] = { 15.71, 43.78, 37.11 }, vectorBMem[n] = { 15.71, 43.78, 37.11 };
	
	for (int i = 0; i <= 2; i++) {
		cout << vectorB[i] << " ";
	}
	cout << endl;
	double matrix[n][n], matrixMem[n][n];  //задаем матрицу
	/*
	double l1, l2, l3;
	cout << "write down l1: ";
	cin >> l1>> endl;
	cout << "write down l2: ";
	cin >> l2 >> endl;
	cout << "write down l3: ";
	cin >> l3 endl;
	matrix[0][0] = (2*l1 + 4*l2); matrix[1][0] = 2*(l1-l2); matrix[2][0] = 2(l1-l2);
	matrix[0][1] = 2*(l1-l2); matrix[1][1] = 2*l1+l2+3*l3; matrix[2][1] = 2*l1+l2-3*l3;
	matrix[0][2] = 2*(l1-l2); matrix[1][2] = 2*l1+l2-3*l3; matrix[2][2] = 2*l1+l2+3*l3;
	//double vectorB[n] = { -4*l1, -4l1+l2+9*l3, -4l1+l2-9*l3 }, vectorBMem[n] = { -4*l1, -4l1+l2+9*l3, -4l1+l2-9*l3 } ,roundH;
	*/


	matrix[0][0] = 2.75; matrix[1][0] = 1.78; matrix[2][0] = 1.11;
	matrix[0][1] = 3.28; matrix[1][1] = 0.71; matrix[2][1] = 1.15;
	matrix[0][2] = 1.15; matrix[1][2] = 2.70; matrix[2][2] = 3.58;
	for (int i = 0; i <= 2; i++) { //копируем её в "буфер" (другая матрица)
		for (int j = 0; j <= 2; j++) {
			matrixMem[i][j] = matrix[i][j];
		}

	}

	//outputMatrix(vectorB, n, matrix);

	double max = matrix[0][0]; //поиск максимального числа на позиции 1-ый элемент, 1-ый столбец
	int maxSt = 0;
	for (int i = 0; i <= 2; i++) {
		if (max < matrix[0][i]) {
			max = matrix[0][i];
			maxSt = i; //номер наибольшей строки
		}


	}
	//обмен строк (1 строка и строка с самым большим первым элементом меняются местами)
	if (maxSt != 0) {
		for (int i = 0; i <= 2; i++) {
			swap(matrix[i][0], matrix[i][maxSt]);
		}
		swap(vectorB[0], vectorB[maxSt]);
	}

	//outputMatrix(vectorB, n, matrix);
	double number1 = matrix[0][0]; // поэлементно делим первую строку на первый элемент строки 2
	for (int i = 0; i <= 2; i++) {
		matrix[i][0] = matrix[i][0] / number1;
		round = matrix[i][0];    //округление вручную
		rounding(&round, accur);
		matrix[i][0] = round;

	}
	vectorB[0] /= number1;
	
	round = vectorB[0]; //округление вручную
	rounding(&round, accur);
	vectorB[0] = round;

	//outputMatrix(vectorB, n, matrix);
	double gaussMatrixHelp[3]; //столблец, где записаны первые члены 2 и 3 строки матрицы
	for (int i = 1; i <= 2; i++) {
		gaussMatrixHelp[i] = matrix[0][i];
	}
	for (int j = 1; j <= 2; j++) {
		for (int i = 0; i <= 2; i++) {
			matrix[i][j] -= matrix[i][0] * gaussMatrixHelp[j];//от всех элеметов 2 и 3 строки поэлементно отнимают элементы 1-ой строки, поэлементно домноженные на элементы 2 и 3
			round = matrix[i][j];//округление
			rounding(&round, accur);
			matrix[i][j] = round;
		}
		vectorB[j] -= vectorB[0] * gaussMatrixHelp[j];
		round = vectorB[j];//округление
		rounding(&round, accur);
		vectorB[j] = round;
	}
	
	outputMatrix(vectorB, n, matrix);
	max = matrix[1][1]; //спуск по диагонали на 1
	maxSt = 1;
	for (int i = 0; i <= 2; i++) {//поиск наиб элемента между 2 и 3 строками в столбце 2
		if (max < matrix[1][i]) {
			max = matrix[1][i];
			maxSt = i;
		}


	}
	if (maxSt != 1) {
		for (int i = 1; i <= 2; i++) {//обмен
			swap(matrix[i][1], matrix[i][maxSt]);
		}
		swap(vectorB[1], vectorB[maxSt]);
	}
	number1 = matrix[1][1]; // поэлементно делим 2 строку на 2 элемент строки
	for (int i = 1; i <= 2; i++) {
		matrix[i][1] = matrix[i][1] / number1;
		round = matrix[i][1];//округление
		rounding(&round, accur);
		matrix[i][1] = round;

	}
	vectorB[1] /= number1;
	round = vectorB[1];//округление
	rounding(&round, accur);
	vectorB[1] = round;

	//outputMatrix(vectorB, n, matrix);
	for (int i = 0; i <= 2; i++) {
		gaussMatrixHelp[i] = matrix[1][i];//сохранение элементов строки 2
	}
	
	for (int i = 1; i <= 2; i++) {
		matrix[i][2] -= matrix[i][1] * gaussMatrixHelp[2]; // поэлементно отнимаем от 3-й строки элементы второй строки, домноженные на первый элемент 3-ей строки.
		round = matrix[i][2];//округление
		rounding(&round, accur);
		matrix[i][2] = round;
	}
	vectorB[2] -= vectorB[1] * gaussMatrixHelp[2];//округление
	round = vectorB[2];
	rounding(&round, accur);
	vectorB[2] = round;

	outputMatrix(vectorB, n, matrix);
	number1 = matrix[2][2];//спускаемся по диагонали на элемент 3 3 и делим его и вектор В на самого себя(на элемент 3 3)

	matrix[2][2] /= number1;//округление
	round = matrix[2][2];
	rounding(&round, accur);
	matrix[2][2] = round;

	vectorB[2] /= number1; //округление
	round = vectorB[2];
	rounding(&round, accur);
	
	vectorB[2] = round; 

	outputMatrix(vectorB, n, matrix);
	double xVect[3]; //находим Х
	xVect[2] = vectorB[2];
	xVect[1] = vectorB[1] - (vectorB[2] * matrix[2][1]);
	xVect[0] = vectorB[0] - (vectorB[2] * matrix[2][0]) - (xVect[1] * matrix[1][0]);
	cout << endl << " x1= " << xVect[0] << " ; x2= " << xVect[1] << " ; x3= " << xVect[2] << ".";
	//находим ветор невязки
	double vectorNevyaz[3]={0, 0, 0};
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			vectorNevyaz[i] += matrixMem[j][i]*xVect[j];
		}
	}
	outputVector(vectorNevyaz, n);
	cout << "vector nevyazki" << endl;
	for (int i = 0; i <= 2; i++) {
		cout << vectorNevyaz[i] - vectorBMem[i] << endl;
	}

	//решение Ax=Ax'--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	for (int i = 0; i <= 2; i++) { //копируем её в "буфер" (другая матрица)
		for (int j = 0; j <= 2; j++) {
			matrix[i][j] = matrixMem[i][j];
		}
	}
	for (int i = 0; i <= 2; i++) {
		vectorB[i] = vectorNevyaz[i];
	}
	outputMatrix(vectorB, n, matrix);
	max = matrix[0][0]; //поиск максимального числа на позиции 1-ый элемент, 1-ый столбец
	maxSt = 0;
	for (int i = 0; i <= 2; i++) {
		if (max < matrix[0][i]) {
			max = matrix[0][i];
			maxSt = i; //номер наибольшей строки
		}


	}
	//обмен строк (1 строка и строка с самым большим первым элементом меняются местами)
	if (maxSt != 0) {
		for (int i = 0; i <= 2; i++) {
			swap(matrix[i][0], matrix[i][maxSt]);
		}
		swap(vectorB[0], vectorB[maxSt]);
	}

	outputMatrix(vectorB, n, matrix);
	number1 = matrix[0][0]; // поэлементно делим первую строку на первый элемент строки 2
	for (int i = 0; i <= 2; i++) {
		matrix[i][0] = matrix[i][0] / number1;
		round = matrix[i][0]; //округление вручную
		rounding(&round, accur);
		matrix[i][0] = round;

	}
	vectorB[0] /= number1;
	round = vectorB[0]; //округление вручную
	rounding(&round, accur);
	vectorB[0] = round;

	outputMatrix(vectorB, n, matrix);
	//столблец, где записаны первые члены 2 и 3 строки матрицы
	for (int i = 1; i <= 2; i++) {
		gaussMatrixHelp[i] = matrix[0][i];
	}
	for (int j = 1; j <= 2; j++) {
		for (int i = 0; i <= 2; i++) {
			matrix[i][j] -= matrix[i][0] * gaussMatrixHelp[j];//от всех элеметов 2 и 3 строки поэлементно отнимают элементы 1-ой строки, поэлементно домноженные на элементы 2 и 3
			round = matrix[i][j];//округление
			rounding(&round, accur);
			matrix[i][j] = round;
		}
		vectorB[j] -= vectorB[0] * gaussMatrixHelp[j];
		round = vectorB[j];//округление
		rounding(&round, accur);
		vectorB[j] = round;
	}

	outputMatrix(vectorB, n, matrix);
	max = matrix[1][1]; //спуск по диагонали на 1
	maxSt = 1;
	for (int i = 0; i <= 2; i++) {//поиск наиб элемента между 2 и 3 строками в столбце 2
		if (max < matrix[1][i]) {
			max = matrix[1][i];
			maxSt = i;
		}


	}
	if (maxSt != 1) {
		for (int i = 1; i <= 2; i++) {//обмен
			swap(matrix[i][1], matrix[i][maxSt]);
		}
		swap(vectorB[1], vectorB[maxSt]);
	}
	number1 = matrix[1][1]; // поэлементно делим 2 строку на 2 элемент строки
	for (int i = 1; i <= 2; i++) {
		matrix[i][1] = matrix[i][1] / number1;
		round =  matrix[i][1];//округление
		rounding(&round, accur);
		matrix[i][1] = round;

	}
	vectorB[1] /= number1;
	round = vectorB[1];//округление
	rounding(&round, accur);
	vectorB[1] = round;

	outputMatrix(vectorB, n, matrix);
	for (int i = 0; i <= 2; i++) {
		gaussMatrixHelp[i] = matrix[1][i];//сохранение элементов строки 2
	}

	for (int i = 1; i <= 2; i++) {
		matrix[i][2] -= matrix[i][1] * gaussMatrixHelp[2]; // поэлементно отнимаем от 3-й строки элементы второй строки, домноженные на первый элемент 3-ей строки.
		round = matrix[i][2];//округление
		rounding(&round, accur);
		matrix[i][2] = round;
	}
	vectorB[2] -= vectorB[1] * gaussMatrixHelp[2];//округление
	round = vectorB[2];
	rounding(&round, accur);
	vectorB[2] = round;

	outputMatrix(vectorB, n, matrix);
	number1 = matrix[2][2];//спускаемся по диагонали на элемент 3 3 и делим его и вектор В на самого себя(на элемент 3 3)

	matrix[2][2] /= number1;//округление
	round = matrix[2][2];
	rounding(&round, accur);
	matrix[2][2] = round;

	vectorB[2] /= number1; //округление
	round = vectorB[2];
	rounding(&round, accur);
	vectorB[2] = round;

	outputMatrix(vectorB, n, matrix);
	double xVect2[3]; //находим Х
	xVect2[2] = vectorB[2];
	xVect2[1] = vectorB[1] - (vectorB[2] * matrix[2][1]);
	xVect2[0] = vectorB[0] - (vectorB[2] * matrix[2][0]) - (xVect2[1] * matrix[1][0]);
	cout << endl << " x1= " << xVect2[0] << " ; x2= " << xVect2[1] << " ; x3= " << xVect2[2] << ".";
	double modul1,xMod1=0, modul2, xMod2=0, pogreshnost;
	for (int i = 0; i <= 2; i++) {
		xMod1 += pow((xVect2[i]-xVect[i]), 2);
	}
	for (int i = 0; i <= 2; i++) {
		xMod2 += pow(xVect[i], 2);
	}
	modul1 = pow((xMod1), 0.5);
	modul2 = pow((xMod2), 0.5);
	pogreshnost = modul1 / modul2;
	cout << "Pogreshnost= ";
	cout << pogreshnost << endl;
}




void rounding(double* a, int accur) {
	int round;
	double roundH;
	double approx;
	approx = *a;
	round = accur * approx;
	roundH = round;
	approx = roundH / accur;
	*a = approx;
}
void outputVector(double vectorB[], const int size) {
	cout << "vectornev= " << endl;
	for (int i = 0; i <= size - 1; i++) {
		cout << vectorB[i] << " "<<endl;
	}
}
void outputMatrix(double vectorB[], const int size, double matrix[3][3]) {
	cout << endl << "matrix: " << endl;
	for (int j = 0; j <= size - 1; j++) {
		for (int i = 0; i <= size - 1; i++) {

			cout << matrix[i][j] << setw(10);

		}
		cout << "|"<< vectorB[j] << " " << endl;
	}
}
