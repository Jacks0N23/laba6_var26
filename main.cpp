#include <iostream>
#include <c++/fstream>
#include <c++/iomanip>
#include "header_file.h"

using namespace std;

int main() {
    int n;

    cout << "Hello, Maaaan!" << endl;


    char in[80];
    cout << "Enter input file name " << endl;
    gets(in);
    ifstream input_file(in);

    char out[80];
    cout << "Enter output file name " << endl;
    gets(out);
    ofstream output_file(out);


    input_file >> n;
    if (n < 2) {
        cout << "Matrix size MUST BE > or = 2" << endl;
        exit(1);
    }
    output_file << n << "  numbers of lines" << endl;
    output_file << n << "  numbers of colomns" << endl;

    int **B = new int *[n];
    for (int k = 0; k < n; k++) {
        B[k] = new int[n];
    }


    Input(n,B,input_file);
    InputedMatrix(n,B,output_file);

    if(isMaxOnMainDiag(n,B))
    {

        makeMagic(n,B,output_file);
    }
    else
        output_file << "\n\nMax value isn't on Main Diagonal" << endl;



    input_file.close();
    output_file.close();

    for (int k = 0; k < n; k++) {
        delete[] B[k];
    }
    delete[] B;
}