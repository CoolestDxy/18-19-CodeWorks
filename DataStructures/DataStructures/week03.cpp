//week03.cpp
/*
P107N01
How much time does it take to locate an arbitrary element A[i][j] in the representation of this section and to change its value;
时间复杂度O(m*n);
P107N02
Analyze carefully the computing tiem and storge requirements of function FastTranspace. What can you say about the existence of an even faster algotithm.
时间复杂度
time=terms+terms
O(n)
空间复杂度
useage=col+col+term
O(n)
继续优化方法,start数组多余,可根据size数组计算得出节约col个data内存.
*/
//P107N04
//Rewrite function FastTranspose……

class MatixTerm
{
	friend class SparseMatrix;
public:
	MatixTerm()
	{
		MatixTerm(1, 1, 0);
	}
	MatixTerm(int r, int c, int v)
	{
		row = r; col = c; value = v;
	}
	int row, col, value;
};
class SparseMatrix
{
public:
	friend void P107N04();

	SparseMatrix(int r, int c, int t)
	{
		rows = r;cols = c;terms = t;
		smArray = new MatixTerm[t];
	}
	SparseMatrix FastTranspose();
	int rows, cols, terms, capacity;
	MatixTerm * smArray;

};
int rowStart(int i, int* ths);
SparseMatrix SparseMatrix::FastTranspose()
{
	SparseMatrix b(cols, rows, terms);
	if (terms > 0)
	{
		int * rowSize = new int[cols] {0};
		for (int i = 0; i < terms; ++i)
		{
			++rowSize[smArray[i].col];
		}
		for (int i = 0; i < terms; ++i)
		{
			int j = rowStart(smArray[i].col, rowSize);
			b.smArray[j].row = smArray[i].col;
			b.smArray[j].col = smArray[i].row;
			b.smArray[j].value = smArray[i].value;
		}
		delete rowSize;
	}
	return b;
}
int rowStart(int i, int * ths)
{
	int res = 1;
	for (int j = 1; j <= i; ++j)
	{
		res += ths[i];
	}
	return res;
}
void P107N04()
{
	SparseMatrix a(10, 5, 6);
	a.smArray[0] = MatixTerm(1, 1, 4);
	a.smArray[1] = MatixTerm(1, 3, 6);
	a.smArray[2] = MatixTerm(3, 3, 5);
	a.smArray[3] = MatixTerm(4, 4, 8);
	a.smArray[4] = MatixTerm(4, 2, 1);
	a.smArray[5] = MatixTerm(5, 3, 7);
	a.FastTranspose();
}