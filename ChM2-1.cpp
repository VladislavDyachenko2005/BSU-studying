#include <iostream>
#include <math.h>
#include<iomanip>
using namespace std;
double function1(double x1, double x2);
double function2(double x1, double x2);
double f1derivative11(double x1, double x2);
double f1derivative12(double x1, double x2);
double f2derivative21(double x1, double x2);
double f2derivative22(double x1, double x2);
void residualVector(double* vNev, double x1, double x2);
double* gauss(double** matrix, double* y, const int n, float accur);
void outputMatrix(double** matrix, double* y, const int n);
# define M_PI           3.14159265358979323846
const double eps = 1e-9;
const double dif = 0.001;
void main() {
	double x1 = 1, x2 = 0;
    float accur=1e9;
	const int n = 2;
	double* vNev, *xVect;
	vNev = new double[n];
    xVect = new double[n];
	double** a = new double* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new double[n];
	}
	a[0][0] = f1derivative11(x1, x2);
	a[1][0] = f1derivative12(x1, x2);
	a[0][1] = f2derivative21(x1, x2);
	a[1][1] = f2derivative22(x1, x2);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << a[j][i] << " ";
		}
		cout << endl;
	}
    xVect = gauss(a, vNev, n, accur);
    for (int i = 0; i < n; i++) {
        cout << "x" << i+1 << " = "<< xVect[i] << " " << endl;
    }
}
double function1(double x1, double x2) {
	return (sin(x1) - x2 - 1.32);
}
double function2(double x1, double x2) {
	return (cos(x2) - x1 + 0.85);
}
double f1derivative11(double x1, double x2) {
	return((function1(x1 + dif, x2) - function1(x1, x2)) / (dif));
}
double f1derivative12(double x1, double x2) {
	return((function1(x1, x2 + dif) - function1(x1, x2)) / (dif));
}
double f2derivative21(double x1, double x2) {
	return((function2(x1 + dif, x2) - function2(x1, x2)) / (dif));
}
double f2derivative22(double x1, double x2) {
	return((function2(x1, x2 + dif) - function2(x1, x2)) / (dif));
}
//double f1Proizv11(double x1, double x2) {
//	return(cos(x1));
//}
//double f1Proizv12(double x1, double x2) {
//	return(-1);
//}
//double f1Proizv21(double x1, double x2) {
//	return(-sin(x2));
//}
//double f1Proizv22(double x1, double x2) {
//	return(-1);
//}
void residualVector(double* vNev, double x1, double x2)
{
	vNev[0] = -function1(x1, x2);
	vNev[1] = -function2(x1, x2);
}
void outputMatrix(double** matrix, double* y, const int n) {
    cout << endl << "matrix: " << endl;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {

            cout << matrix[j][i] << setw(10);

        }
        cout << "|" << y[j] << " " << endl;
    }
}
double* gauss(double** matrix, double* y, const int n, float accur)
{
    double* xVect, max, roundH;
    int k, index, round;
    const double eps = 0.00001;  // точность
    xVect = new double[n];
    k = 0;
    while (k < n)
    {
        // Поиск максимума
        max = abs(matrix[k][k]);
        index = k;
        for (int i = k + 1; i < n; i++)
        {
            if (abs(matrix[i][k]) > max)
            {
                max = abs(matrix[i][k]);
                index = i;
            }
        }

        if (max < eps)
        {
            // диаг элем = 0?
            cout << "Решение получить невозможно из-за нулевого столбца ";
            cout << index << " матрицы A" << endl;
            return 0;
        }
        for (int j = 0; j < n; j++)
        {
            swap(matrix[k][j], matrix[index][j]);
        }
        swap(y[k], y[index]);
        if (k > 0)
            outputMatrix(matrix, y, n);
        // Нормализация уравнений
        for (int i = k; i < n; i++)
        {
            double temp = matrix[i][k];
            if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
            for (int j = 0; j < n; j++) {
                matrix[i][j] = matrix[i][j] / temp;
                round = matrix[i][j] * accur;
                roundH = round;
                matrix[i][j] = roundH / accur;
            }
            y[i] = y[i] / temp;
            round = y[i] * accur;
            roundH = round;
            y[i] = roundH / accur;
            if (i == k)  continue; // уравнение не вычитать само из себя
            for (int j = 0; j < n; j++)
                matrix[i][j] = matrix[i][j] - matrix[k][j];
            y[i] = y[i] - y[k];
        }
        if (k == n - 1) {
            outputMatrix(matrix, y, n);
        }
        k++;
    }
    // обратная подстановка
    for (k = n - 1; k >= 0; k--)
    {
        xVect[k] = y[k];
        for (int i = 0; i < k; i++)
            y[i] = y[i] - matrix[i][k] * xVect[k];
    }
    return xVect;
}
