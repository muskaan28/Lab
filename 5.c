34
#include<stdio.h>
#include<math.h>
#define TIME 336 //length of FSK signal
#define PI 3.14
float fh[TIME],fl[TIME],FSK[TIME];
int input_string[8],scale_data[TIME];
void main()
{
int i,j,k,l;
printf("\nEnter your digital data string in the form of 1 & 0s\n");
for(i=0;i<8;i++) //data in binary format
scanf("%d",&input_string[i]);
k=0;
for(k=0;k<TIME;k++)
{
for(j=0;j<8;j++)
{
for(i=0;i<21;i++)
{
scale_data[k]=input_string[j]; // Scaling input data
k++;
}
}
}
for(i=0;i<TIME;i++)
{
fh[i]=sin(2*PI*2000*i/10000);//high frequency
fl[i]=sin(2*PI*1000*i/10000);//low frequency
}
//assigning high frequency to bit 1
k=0;
for(l=0;k<TIME;l++)
{
for(i=0;i<8;i++)
{
if(input_string[i]==1)
{
for(j=0;j<21;j++)
{
FSK[k]=fh[j];
k++;
}
}
else
//assigning low frequency to bit 0
{
if(input_string[i]==0)
{
for(j=0;j<21;j++)
{
FSK[k]=fl[j];
k++;
}}}}}}