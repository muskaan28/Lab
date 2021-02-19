#include "L138_LCDK_aic3106_init.h"
#define GAIN 0.6
#define BUF_SIZE 16000
int16_t input,output,delayed;
int16_t buffer[BUF_SIZE];
int i = 0;
interrupt void interrupt4(void) // interrupt service routine
{
input = input_left_sample();
delayed = buffer[i];
output = delayed + input;
buffer[i] = input + delayed*GAIN;
i = (i+1)%BUF_SIZE;
output_left_sample(output);
return;
}
int main(void)
{
int i;
for (i=0 ; i<BUF_SIZE ; i++)
{
buffer[i] = 0;
}
L138_initialise_intr(FS_8000_HZ,ADC_GAIN_30DB,DAC_ATTEN_0DB,LCDK_MIC_INPUT);
while(1);
}