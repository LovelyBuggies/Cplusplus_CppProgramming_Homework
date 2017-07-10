#include "Matrix.hpp"
#include "BooleanMatrix.hpp"

BooleanMatrix::BooleanMatrix(const BooleanMatrix &sample) : Matrix(sample) {}
BooleanMatrix::BooleanMatrix(int r, int c) : Matrix(r,c) {}
//constructor

bool BooleanMatrix::replace(matrix_element_type e, int r, int c)
{
	return Matrix::replace(e,r,c);
}

BooleanMatrix BooleanMatrix::operator&(const BooleanMatrix &m)
{
    assert(m.row == row);
    assert(m.columns == columns);
    BooleanMatrix temp(*this);
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= columns; j++) {
            if(temp.matrix[ELEMENT_POS(i, j)] + m.matrix[ELEMENT_POS(i, j)]==2)
            temp.matrix[ELEMENT_POS(i,j)]=1;
            else 
            temp.matrix[ELEMENT_POS(i,j)]=0;
        }
    }
    return temp;
}

BooleanMatrix BooleanMatrix::operator|(const BooleanMatrix &m)
{
    assert(m.row == row);
    assert(m.columns == columns);
    BooleanMatrix temp(*this);
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= columns; j++) {
            if(temp.matrix[ELEMENT_POS(i, j)] + m.matrix[ELEMENT_POS(i, j)]==0)
            temp.matrix[ELEMENT_POS(i,j)]=0;
            else 
            temp.matrix[ELEMENT_POS(i,j)]=1;
        }
    }
    return temp;
}

BooleanMatrix BooleanMatrix::BooleanProduct(const BooleanMatrix &m) const
{
    assert(columns == m.row);
    BooleanMatrix temp(row, m.columns);
    for (int i = 1; i <= temp.row; i++) {
        for (int j = 1; j <= temp.columns; j++) {
            for (int s = 1; s <= columns; s++) {
                temp.matrix[(i - 1) * temp.columns + j - 1] +=
                matrix[ELEMENT_POS(i, s)] *
                m.matrix[(s - 1) * m.columns + j - 1];
                if(temp.matrix[(i - 1) * temp.columns + j - 1]==0)
                	temp.matrix[(i - 1) * temp.columns + j - 1]=0;
                else
                	temp.matrix[(i - 1) * temp.columns + j - 1]=1;
            }
        }
    }
    return temp;
}