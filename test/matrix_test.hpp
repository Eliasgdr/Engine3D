#ifndef ENGINE3D_MATRIX_TEST_HPP
#define ENGINE3D_MATRIX_TEST_HPP

#include "../include/matrix.hpp"

void matrixTest() {
    //Test matrice de int
    iMatrix matrix1(3, 3);
    matrix1.fill(2);
    matrix1.display();

    iMatrix matrix2(3, 3);
    matrix2.fill(3);
    matrix2.display();

    iMatrix sumMatrix = matrix1 + matrix2;
    cout << "Sum Matrix:\n";
    sumMatrix.display();

    iMatrix productMatrix = matrix1 * matrix2;
    cout << "Product Matrix:\n";
    productMatrix.display();

    //Test matrice de float
    fMatrix floatMatrix1(2, 3);
    floatMatrix1.fill(1.5);
    floatMatrix1.display();

    fMatrix floatMatrix2(3, 2);
    floatMatrix2.fill(2.5);
    floatMatrix2.display();

    fMatrix floatProductMatrix = floatMatrix1 * floatMatrix2;
    cout << "Floating Point Product Matrix:\n";
    floatProductMatrix.display();

    //Test matrice identité
    iMatrix identityMatrix = identity(4);
    cout << "Identity Matrix:\n";
    identityMatrix.display();
}

#endif //ENGINE3D_MATRIX_TEST_HPP