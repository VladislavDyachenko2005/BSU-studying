/*Дана последовательность ненулевых целых чисел, за которой следует 0. Напечатать сначала все отрицательные числа этой последовательности, затем - все
положительные(в любом порядке)*/
#include <iostream>
//#include <conio.h>
using namespace std;
 

void cikl(int* ar2, int K);


void print(int* ar)
{

    if (*ar > 0)
    {
        print(ar + 1);
        cout << *ar << " ";
    }
    else if (*ar < 0)
    {
        cout << *ar << " ";
        print(ar + 1);
    }
}
 
int main()
{
    int N;
    cout << "input N:" << endl;
    cin >> N;
    int K = N;

    int* ar2 = new int[K];
    int* ar = new int[N];
    cout << "vvelite massiv 1 iz " << N << " chisel ne ravnih noly, 0 budet proignorirovan" << endl;
    for (int i = 0; i < N - 1; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            i--;
            cout  << endl  << "chislo 0 propuscheno" << endl;
            continue;
        } else 
            ar[i] = a;
    }
    //if (CheckValue != 1) {
        ar[N - 1] = 0;
        print(ar);
        cout << ar[N - 1] << endl<< endl;
    //}
    
    delete ar;
    cout << "vvelite massiv 2 iz " << K << "chisel ne ravnih noly, 0 budet proignorirovan" << endl;
    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            i--;
            cout << "chislo 0 propuscheno" << endl;
            continue;
        }
        else
            ar2[i] = a;
    }
   
        ar2[K - 1] = 0;
        cikl(ar2, N);
  
    return 0;
}
    /*for (int i = 0; i < N; i++) {
        cout << endl;
        cout << ar2[i] << " ";
    }*/
void cikl(int* ar2, int K) {
    for (int i = 0; i < K; i++) {
        if (ar2[i] < 0) {
            cout << ar2[i] << " ";
        }
    }
    for (int i = 0; i < K; i++) {
        if (ar2[i] > 0) {
            cout << ar2[i] << " ";
        }
    }
    cout << ar2[K - 1];
}


