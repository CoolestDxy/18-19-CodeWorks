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
private:
	int row,col,value;
};
class SparseMatrix
{
	SparseMatrix(int r, int c, int t);
	SparseMatrix FastTranspose();
private:
	int rows,cols,terms,capacity;
	MatixTerm * smArray;

};
SparseMatrix::SparseMatrix(int r, int c, int t)
{
	rows=r;
	cols=c;
	terms=t;
}
SparseMatrix SparseMatrix::FastTranspose()
{
	SparseMatrix b(cols,rows,terms);
	if(terms>0)
	{
		int * rowSize=new int[cols];
		for(int i=0;i<terms;++i)
		{
			++rowSize[smArray[i].col];
		}
		for(int i=0;i<terms;++i)
		{
			int res=1;
				for(int j=1;j<=i;++j)
			{
				res+=rowSize[i];
			}
		}
	}
}
	// int rowStart(int i)
	// {
	// 	int res=1;
	// 	for(int j=1;j<=i;++j)
	// 	{
	// 		res+=rowSize[i];
	// 	}
	// }