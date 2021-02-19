#include<stdio.h>
#include<stdlib.h>
#ifndef DCT_MAIN_H
#define IMAGE_LEN 256
#define IMAGE_SIZE (IMAGE_LEN*IMAGE_LEN)
#define BLOCK_LEN 8
#define BLOCK_SIZE (BLOCK_LEN*BLOCK_LEN)
#endif
#define IM_HEIGHT 256
#define IM_WIDTH 256
#define Pixels 225*225
extern const unsigned char GRAY_BMP[];
extern unsigned char LOGO[];
extern const unsigned char gImage_wolf[];
unsigned char finimg[65536];
#pragma DATA_SECTION(images,".EXT_RAM");
unsigned char images[3][IM_HEIGHT][IM_WIDTH];
unsigned int i,temp;
char smooth_mask[3][3] = {{1,2,1},{2,4,2},{1,2,1}};
char sharp_mask[3][3]={{0,-1,0},{-1,5,-1},{0,-1,0}};
int y,x;
void smoothing_filter()
{
	for(y=0;y<IM_HEIGHT;y++)
	IMG_conv_3x3_i8_c8s_cn((const unsigned char *restrict)&images[0][y][0],(unsigned char*restrict)&images[1][y][0], IM_WIDTH, (char *restrict)smooth_mask, 4);
}
void sharpening_filter()
{
	for(y=0;y<IM_HEIGHT;y++)
	IMG_conv_3x3_i8_c8s_cn((const unsigned char *restrict)&images[0][y][0],(unsigned char*restrict)&images[1][y][0], IM_WIDTH, (char *restrict)sharp_mask, 0);
}
void threshold()
{
	IMG_thr_gt2max_8_cn(&images[0][0][0], &images[1][0][0], IM_WIDTH, IM_HEIGHT, 128);
}
void sobeledge()
{
	IMG_sobel_3x3_8_cn(&images[0][0][0], &images[1][0][0], IM_WIDTH, IM_HEIGHT);
}
void main()
{
	memset(images,0,sizeof(images));
	for(i=1050;i<5100;i++)
		finimg[i]=LOGO[i];
	for(i=5100;i<65536;i++)
		finimg[i]=gImage_wolf[i];

		memcpy((void *)images[0],(void *)&finimg[0],IM_HEIGHT*IM_WIDTH);
		sobeledge();
		threshold();
		sharpening_filter();
		smoothing_filter();
}
