//**********************************************
//***********************************************************************
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>生成的数据模型为Y=a*X+b
#include <iostream>

#define DATA_NUM 20

double x[DATA_NUM] = { 1,  2, 3,	4,	5,	6,	7,	8,	9,	10,	11,	12,	13,	14,	15,	16 };

double y[DATA_NUM] = {
    108.298968, 201.1937087,306.8137136,  400.1896281,503.1942015,604.9508544,705.4288505,  808.7680557,909.140237,1003.458472, 1100.745679,  1200.032985,1305.621112,1402.857483,1500.369506,  1600.246594,
};

double x_aver = 0;
double y_aver = 0;

void aver(double* x_data, double* y_data, uint32_t num)
{
    uint32_t i = 0;
    double x_sum = 0;
    double y_sum = 0;

    for (i = 0; i < num; i++)
    {
        printf("%1f %lf\r\n", *x_data, *y_data);
        x_sum += *x_data++;
        y_sum += *y_data++;
    }
    x_aver = x_sum / num;
    y_aver = y_sum / num;

}
void caucle(double* x_data, double* y_data, uint32_t num)
{
    uint32_t i = 0;
    double a = 0;
    double b = 0;
    double numerator = 0;
    double denominator = 0;
    double denominator_1 = 0;

    for (i = 0; i < num; i++)
    {
        numerator += (*x_data - x_aver) * (*y_data);
        denominator += ((*x_data) * (*x_data));
        denominator_1 += (*x_data);
        x_data++;
        y_data++;
    }
    denominator = denominator - (denominator_1 * denominator_1) / num;
    a = numerator / denominator;
    b = y_aver - a * x_aver;
}
int main()
{
    uint32_t i = 0;
    //******************************生成随机数
    for (i = 0; i < DATA_NUM; i++)
    {
        x[i] = i;
        y[i] = i * 100 + rand() % 20 + 10;
        printf("%1f %lf\r\n", x[i], y[i]);
    }
    aver(x, y, DATA_NUM);
    caucle(x, y, DATA_NUM);
}
