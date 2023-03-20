#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
void readFile(ifstream& rfile);
void plusMinusFiles(ofstream &, ofstream&, ifstream&);
void fileGWriting(ifstream&, ifstream&, ofstream&);


int main() {

	ofstream fFile("file.txt");
	if (!fFile)
	{
		cout << "error1" << endl;
		return 1;
	}
	int n;
	int ch;
	/*cout << "1 - static array, 2 - dynamic array; your number: ";
	cin >> ch;*/
	cout << "kol-vo chisel v fayle = ";
	cin >> n;
	/*enum eArrayInit
	{
		Uninited = 0, Static, Dynamic,
	};


	cout << " Выберите тип инициализации:\n"
		<< Static << ".одномерный массив\n"
		<< Dynamic << ".двумерный\n";
	cout << "Любая другая кнопка завершит программу\n Ваш выбор: ";
	switch(ch)
	{ }*/
	const int arrayfil[] = { 1, -2, 3, -3, -1, 2, 4, -4, -5, 5 };

	int* arrFilDyn = new int [n];
	/*cout << "input dynamic arrray. (amount of positive numbers = amount of negative numbers): ";
	for (int i = 0; i < n; i++) {
		cin >> arrFilDyn[i];
	}*/
	//функция создания файла	
	for (int i = 0; i <= n - 1; i++)
	{
		int v = arrayfil[i];
		fFile << v << endl;
	}
	/*for (int i = 0; i <= n - 1; i++)
	{
		int v = arrFilDyn[i];
		fFile << v << endl;
	}*/
	fFile.flush();
	ifstream rfile("file.txt");
	if (!rfile)
	{
		cout << "error2" << endl;
		return 2;
	}
	rfile.close();
	rfile.clear();
	rfile.open("file.txt");
	readFile(rfile);
	rfile.close();
	rfile.clear();
	rfile.open("file.txt");
	ofstream minusFile("fileMinus.txt");
	ofstream plusFile("filePlus.txt");
	ifstream RminusFile("fileMinus.txt");
	ifstream RplusFile("filePlus.txt");
	plusMinusFiles(plusFile, minusFile, rfile);
	cout << endl;
	readFile(RminusFile);
	cout << endl;
	readFile(RplusFile);

	ofstream gFile("fileG.txt");
	RplusFile.close();
	RplusFile.clear();
	RplusFile.open("filePlus.txt");
	RminusFile.close();
	RminusFile.clear();
	RminusFile.open("fileMinus.txt");
	fileGWriting(RminusFile, RplusFile, gFile);
	
	ifstream grFile("fileG.txt");
	readFile(grFile);

	delete[]  arrFilDyn;
	return 0;
}
void readFile(ifstream& rfile)
{
	int v;
	rfile >> v;
	while (!rfile.fail())  //while( !infile.eof())
	{
		cout << v << " ";
		rfile >> v;
	}
	cout << endl;
}
void plusMinusFiles(ofstream& plusFile, ofstream& minusFile, ifstream& rfile) {
	int v;
	rfile >> v;
	while (!rfile.eof()) {
		//cout << v << " ";
		if (v > 0)
			plusFile << v << endl;
		else
			minusFile << v << endl;
		rfile >> v;
	}
	
}
void fileGWriting(ifstream& RminusFile, ifstream& RplusFile, ofstream& gFile) {
	int minus;
	int plus;
	RminusFile >> minus;
	RplusFile >> plus;
	while (!RminusFile.eof() && !RplusFile.eof()) {
		for (int i = 0; i < 2; i++) {
			gFile << plus << endl;
			RplusFile >> plus;
		}
		for (int i = 0; i < 2; i++) {
			gFile << minus << endl;
			RminusFile >> minus;
		}
	}
}