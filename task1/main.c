#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f(double y)
{
	return -y;
}
void euler(double x0,double y0,double h,double error,double x_end,double *final_y)
{
	double x=x0;
    double y=y0;
    double y_next;
    int steady_state_found=0;
    printf("x\t\ty\n");
while (x<x_end)
{
	y_next=y+h*f(y);
    x=x+h;
    printf("%.6f\t%.6f\n",x,y_next);
    if(fabs(y_next-y)<error)
    {  
         steady_state_found=1;
         *final_y=y_next;
         }
    y=y_next;
    }
    if (steady_state_found)
    {
        printf("在x范围内检测到定态值:y=%.6f\n",*final_y);
	}
    else 
    {
        *final_y=y;
        printf("在x范围内未检测到定态值,取最后一个y值作为定态值:%lf\n",*final_y);

    }
    }

int main() 
{
	double x0=0.0000000;
    double y0;
    double a;
    double h=0.001;
    double error=0.000001;
    double x_end;
	double final_y;

    printf("请输入a的值:");
    scanf("%lf",&a);

    y0=a;
    x_end=25.0*a;

    euler(x0,y0,h,error,x_end,&final_y);
	return 0;
}

