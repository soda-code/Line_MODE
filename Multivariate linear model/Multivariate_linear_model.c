#include "Matrix_Calculations.h"
#include "stdio.h"
#include "stdint.h"

#define Rows  3  //***行
#define Cols  3  //***列

double array[Rows][Cols] =
{
	{1,2,6.5},
	{3,4,0  },
	{0,8,3.6}
};
int main()
{
	uint16_t i = 0;
	uint16_t j = 0;
	matrix* data;
	matrix* data_T;
	matrix* data_OUT;
	data = Mnew(Rows, Cols);
	data_T = Mnew(Rows, Cols);
	data_OUT = Mnew(Rows, 1);
	// 将二维数组的值赋给双重指针
	for (i = 0; i < Rows; i++) {
		for (j = 0; j < Cols; j++) {
			data->A[i][j] = array[i][j];
		}
	}
	for (j = 0; j < Cols; j++) 
	{
		data_OUT->A[j][0] = array[0][j];
	}


	data_T = Mtrans(data);
	data = Mmulti(data_T, data);
	printf("相乘逆为：\n");
	Mprintf(data);
	data = Minv(data);
	printf("矩阵逆为：\n");
	Mprintf(data);
	data = Mmulti(data, data_T);
	printf("矩阵转置为：\n");
	Mprintf(data);
	data_OUT = Mmulti(data, data_OUT);
	printf("W为：\n");
	Mprintf(data_OUT);
	Mfree(data);
	Mfree(data_T);
	Mfree(data_OUT);
	return 0;
}
