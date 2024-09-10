#include "C:\Users\suhan\Coding_Projects\Machine_Learning\LinearAlgebraFramework\matrix.h"
#include <stdlib.h>
using namespace std;

/*

compilation script : g++ main.cpp "C:\Users\suhan\Coding_Projects\Machine_Learning\LinearAlgebraFramework\matrix_config.cpp" "C:\Users\suhan\Coding_Projects\Machine_Learning\LinearAlgebraFramework\matrix_constructors.cpp" "C:\Users\suhan\Coding_Projects\Machine_Learning\LinearAlgebraFramework\matrix_manip.cpp" "C:\Users\suhan\Coding_Projects\Machine_Learning\LinearAlgebraFramework\matrix_opoverloads.cpp" "C:\Users\suhan\Coding_Projects\Machine_Learning\LinearAlgebraFramework\matrix_cholesky.cpp" -o main

*/

int main(void) {

    FILE * file;
    file = fopen("data.csv","r");

    if(file == NULL) {throw std::invalid_argument("File returns null pointer.");}

    Matrix dataSet(200,4);
    Matrix outputMatrix(200,1);

    for(int i = 0; (i < 200); i++) {

        fscanf(file,
        "%f,%f,%f,%f,%f\n",
        &dataSet.MatrixData[i][0],
        &dataSet.MatrixData[i][1],
        &dataSet.MatrixData[i][2],
        &dataSet.MatrixData[i][3],
        &outputMatrix.MatrixData[i][0]);
        
    }

    fclose(file);

    Matrix weightEstimate(4,1);
    Matrix A(200,200);
    Matrix B(4,1);

    A = (dataSet.Transpose())*dataSet;
    B = (dataSet.Transpose())*outputMatrix;

    cout << (dataSet*(A.linearEquSol(B))-outputMatrix);
    return 0;

}