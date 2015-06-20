//
// Created by Alexandr on 01.06.2015.
//

#ifndef LABA6_VAR26_HEADER_FILE_H
#define LABA6_VAR26_HEADER_FILE_H

/*
 *26. Дана матрица B из N строк и N столбцов. Если в матрице B элемент с максимальным значением
(среди всех элементов этой матрицы) лежит на главной диагонали, присвоить начальным элементам
последовательности С1, С2, ..., СN
2 значения элементов матрицы, лежащих выше главной диагонали,
а остальным элементам этой последовательности – значения прочих элементов матрицы.
 */

#include <iostream>
#include <c++/fstream>
#include <c++/iomanip>

using namespace std;

void  Input(int n, int **A, ifstream& input_file) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input_file >> A[i][j];
        }
    }
}

void InputedMatrix(int n,int **A, ofstream& output_file )
{

    output_file << "\nInputed Matrix" << endl;
    for (int i = 0; i < n; i++) {
        output_file << endl;
        for (int j = 0; j < n; j++) {
            output_file << setw(5) << A[i][j];

        }
    }
}
bool isMaxOnMainDiag(int n, int** A)
{
    bool t = false;
    int max = A[0][1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if( A[i][j] >= max && i==j)
            {
                max = A[i][j];
                t = true;
            }
        }
    }
    return t;
}

void makeMagic(int n,int** B, ofstream& output_file)
{

    int* C = new int[n];
    int k=0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                C[k] = B[i][j];
                k++;
            }
        }
    }

    for (int i = 0; i <n-1 ; i++)
    {
        for (int j = i+1; j <n ; j++)
        {
            C[k] = B[i][j];
            k++;
        }
    }

    for (int i = 0; i <n ; i++)
    {
        for (int j = 0; j <i ; ++j)
        {

            C[k] =B[i][j];
            k++;
        }
    }

    output_file << "\n\nNew Massiv " << endl;

    for (int i = 0; i <k; i++) {
        output_file << setw(5) << C[i] << endl;
    }


}

#endif //LABA6_VAR26_HEADER_FILE_H
