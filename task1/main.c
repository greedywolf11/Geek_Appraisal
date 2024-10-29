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
    double steady_state_value=0.0;
    printf("x\t\ty\n");
while (x<x_end)
{
	y_next=y+h*f(y);
    if(fabs(y_next-y)<error)
    {  
        if(!steady_state_found)
       {
        steady_state_found=1;
        steady_state_value=y_next;
        }
         }
    printf("%.6f\t%.6f\n",x,y_next);
    x=x+h;
    y=y_next;
    
    }
    if (steady_state_found)
    {
        *final_y=steady_state_value;
	}
    else 
    {
        *final_y=y;
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
    printf("最终的定态值或近似定态值为:%lf",final_y);
	return 0;
}

