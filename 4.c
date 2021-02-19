
#include<stdio.h>
#include<math.h>
#define FREQ 500
int tb=2; //sampling rate multiplier for interpolated signal
float tx[128]; //to store sine(input) wave Signal
float ty[256]; // to store Interpolated signal
float x[256],y[256]; //to store decemated Signal
void main()
{
int txx,ti,tc,td;
int a,b,d;
int i,j,z,g;
int tj,tcc,tz;
int ta=128;
for(i=0;i<127;i++)
{
tx[i]=sin(2*3.14*FREQ*i/24000); //generating sine wave
printf("%f\n",tx[i]);
}
//Interpolation
tc = tb - 1;
txx = 0;
for (ti=1;ti<=ta;ti++)
{
ty[ti+txx] = tx[ti];
tcc = ti+txx;
tz = ti;
for (tj = 1 ; tj<=tc ;tj++)
{
ty[tcc+1] = 0; //adding zeros in between samples
ti = ti+1;
tcc = tcc+1;
}
txx = tcc-tz;
ti = ti-tc;
}
td = ta*tb; //Length of interpolated signal
for(ti=1;ti<=td;ti++)
{
printf("\n The Value of output ty[%d]=%f",ti,ty[ti]);
}
//Decimation
b=2; //Sampling rate divider for decimated signal
j=1;
for (g=1;g<=128;g++)
{
y[g] = ty[j];
j = j+b;
printf("%f\n",y[g]);
}
}