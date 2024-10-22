#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f(double y)
{return -y;
}
void eular(double x0,double y0,double h,double error)
{
double x=x0;
double y=y0;
double y_next;
printf("x\t\ty\n");
printf("%.6f\t%.6f\n",x,y);
while (1)
{y_next=y+h*f(y);
x=x+h;
printf("%.6f\t%.6f\n",x,y);
if(fabs(y_next-y)<error)
{printf("已达到定态值\n");
printf("近似定态值: y=%.6f",y_next);
break;}
y=y_next;
	
}

}

int main() 
{double x0=0.0000000;
double y0;
double a;
double h=0.001;
double error=0.000001;
printf("请输入a的值:");
scanf("%lf",&a);
y0=a;

eular(x0,y0,h,error);
	
	return 0;
}

