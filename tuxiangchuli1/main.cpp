#include <stdio.h>

#define W 40 //定义验证码图片的宽度
#define H 20 //定义验证码图片的宽度
#define N 4 //定义字符位数,一般是4位
#define BMP_filename "E:\\vc6.0\\mfc\\tuxiangchuli1\\test.bmp"
int x,y,i,s,temp;
int YZM[W][H]={0};
int YZM_red[W][H]={0};
int YZM_green[W][H]={0};
int YZM_blue[W][H]={0};
int rec[W]={0};
int lf[N],rt[N],up[N],dw[N];
char result[N];


int main()
{
	FILE *fp=fopen(BMP_filename,"rb");//以二进制只读方式打开BMP文件
	for(i=0;i<54;i++)temp=fgetc(fp);//跳过54个字节的文件头数据
	for(y=H-1;y>=0;y--)//BMP图片数据是倒序存储的，据说是为了下载显示方便，呵呵
	{
	for(x=0;x<W;x++){YZM_blue[x][y]=fgetc(fp);YZM_green[x][y]=fgetc(fp);YZM_red[x][y]=fgetc(fp);}
	//依次读取每个像素的RGB值
	}
	fclose(fp);//关闭文件


	for(x=0;x<W;x++)for(y=0;y<H;y++)
	{
		if(YZM_red[x][y]*0.3+YZM_green[x][y]*0.6+YZM_blue[x][y]*0.1<200)YZM[x][y]=1;else YZM[x][y]=0;
		//red*0.3+green*0.6+blue*0.1 是计算亮度的公式
	} 
	//如果图片里有干扰点，可以用下面的语句去除。
	for(x=1;x<W-1;x++)for(y=1;y<H-1;y++)
	{
		if(YZM[x][y]==1 && YZM[x-1][y-1]==0 && YZM[x][y-1]==0 && YZM[x+1][y-1]==0 && YZM[x-1][y]==0 && YZM[x+1][y]==0 && YZM[x-1][y+1]==0 && YZM[x][y+1]==0 && YZM[x+1][y+1]==0)
			YZM[x][y]=0;
		//如果一个点的值是1，而且它的周围8个点的值都是0，那么这个点就是干扰点 
	}

	for(y=0;y<H;y++) 
	{
		for(x=0;x<W;x++)
		{
			printf(" %c",YZM[x][y]+'0');
		}
			
		printf("\n");
	}

	for(x=0;x<W;x++)
	{ 
		s=0;
		for(y=0;y<H;y++)s=s+YZM[x][y];
		if(s>0)rec[x]=1;else rec[x]=0;//rec记录数组的断连情况
	}
	for(i=0,x=1;x<W-1;x++)
		if(rec[x-1]==0 && rec[x]==1 && rec[x+1]==1)
		{
			i++;lf[i]=x;
		}//计算每个字符的左边界
	for(i=0,x=1;x<W-1;x++)if(rec[x-1]==1 && rec[x]==1 && rec[x+1]==0)
	{
		i++;rt[i]=x;
	}//计算每个字符的右边界
	for(i=1;i<=N;i++)for(x=0;x<W;x++)for(y=0;y<H;y++) if(x>=lf[i] && x<=rt[i] && YZM[x][y]==1)
		YZM[x][y]=i;
	for(y=H-1;y>=0;y--)for(x=0;x<W;x++)for(i=1;i<=N;i++)if(YZM[x][y]==i)
		up[i]=y;//计算每个字符的上边界


	for(i=1;i<=N;i++)
	{
		if( YZM[lf[i]+0][up[i]+0]==0 && YZM[lf[i]+1][up[i]+0]==0 && YZM[lf[i]+2][up[i]+0]==0 &&
			YZM[lf[i]+0][up[i]+1]==0 && YZM[lf[i]+1][up[i]+1]==0 && YZM[lf[i]+2][up[i]+1]==i &&
			YZM[lf[i]+0][up[i]+2]==0 && YZM[lf[i]+1][up[i]+2]==i && YZM[lf[i]+2][up[i]+2]==i &&
			YZM[lf[i]+0][up[i]+3]==i && YZM[lf[i]+1][up[i]+3]==i && YZM[lf[i]+2][up[i]+3]==0 &&
			YZM[lf[i]+0][up[i]+4]==i && YZM[lf[i]+1][up[i]+4]==i && YZM[lf[i]+2][up[i]+4]==0 )
			result[i-1]='0';
		if( YZM[lf[i]+0][up[i]+0]==0 && YZM[lf[i]+1][up[i]+0]==0 && YZM[lf[i]+2][up[i]+0]==i &&
			YZM[lf[i]+0][up[i]+1]==0 && YZM[lf[i]+1][up[i]+1]==i && YZM[lf[i]+2][up[i]+1]==i &&
			YZM[lf[i]+0][up[i]+2]==i && YZM[lf[i]+1][up[i]+2]==i && YZM[lf[i]+2][up[i]+2]==i &&
			YZM[lf[i]+0][up[i]+3]==0 && YZM[lf[i]+1][up[i]+3]==0 && YZM[lf[i]+2][up[i]+3]==i &&
			YZM[lf[i]+0][up[i]+4]==0 && YZM[lf[i]+1][up[i]+4]==0 && YZM[lf[i]+2][up[i]+4]==i )
			result[i-1]='1';
		if( YZM[lf[i]+0][up[i]+0]==0 && YZM[lf[i]+1][up[i]+0]==0 && YZM[lf[i]+2][up[i]+0]==i &&
			YZM[lf[i]+0][up[i]+1]==0 && YZM[lf[i]+1][up[i]+1]==i && YZM[lf[i]+2][up[i]+1]==i &&
			YZM[lf[i]+0][up[i]+2]==i && YZM[lf[i]+1][up[i]+2]==i && YZM[lf[i]+2][up[i]+2]==0 &&
			YZM[lf[i]+0][up[i]+3]==0 && YZM[lf[i]+1][up[i]+3]==0 && YZM[lf[i]+2][up[i]+3]==0 &&
			YZM[lf[i]+0][up[i]+4]==0 && YZM[lf[i]+1][up[i]+4]==0 && YZM[lf[i]+2][up[i]+4]==0 )
			result[i-1]='2';
		if( YZM[lf[i]+0][up[i]+0]==0 && YZM[lf[i]+1][up[i]+0]==i && YZM[lf[i]+2][up[i]+0]==i &&
			YZM[lf[i]+0][up[i]+1]==i && YZM[lf[i]+1][up[i]+1]==i && YZM[lf[i]+2][up[i]+1]==0 &&
			YZM[lf[i]+0][up[i]+2]==0 && YZM[lf[i]+1][up[i]+2]==0 && YZM[lf[i]+2][up[i]+2]==0 &&
			YZM[lf[i]+0][up[i]+3]==0 && YZM[lf[i]+1][up[i]+3]==0 && YZM[lf[i]+2][up[i]+3]==0 &&
			YZM[lf[i]+0][up[i]+4]==0 && YZM[lf[i]+1][up[i]+4]==0 && YZM[lf[i]+2][up[i]+4]==0 )
			result[i-1]='3';
		if( YZM[lf[i]+0][up[i]+0]==0 && YZM[lf[i]+1][up[i]+0]==0 && YZM[lf[i]+2][up[i]+0]==0 &&
			YZM[lf[i]+0][up[i]+1]==0 && YZM[lf[i]+1][up[i]+1]==0 && YZM[lf[i]+2][up[i]+1]==0 &&
			YZM[lf[i]+0][up[i]+2]==0 && YZM[lf[i]+1][up[i]+2]==0 && YZM[lf[i]+2][up[i]+2]==0 &&
			YZM[lf[i]+0][up[i]+3]==0 && YZM[lf[i]+1][up[i]+3]==0 && YZM[lf[i]+2][up[i]+3]==i &&
			YZM[lf[i]+0][up[i]+4]==0 && YZM[lf[i]+1][up[i]+4]==i && YZM[lf[i]+2][up[i]+4]==i )
			result[i-1]='4';
		if( YZM[lf[i]+0][up[i]+0]==i && YZM[lf[i]+1][up[i]+0]==i && YZM[lf[i]+2][up[i]+0]==i &&
			YZM[lf[i]+0][up[i]+1]==i && YZM[lf[i]+1][up[i]+1]==i && YZM[lf[i]+2][up[i]+1]==0 &&
			YZM[lf[i]+0][up[i]+2]==i && YZM[lf[i]+1][up[i]+2]==i && YZM[lf[i]+2][up[i]+2]==0 &&
			YZM[lf[i]+0][up[i]+3]==i && YZM[lf[i]+1][up[i]+3]==i && YZM[lf[i]+2][up[i]+3]==0 &&
			YZM[lf[i]+0][up[i]+4]==i && YZM[lf[i]+1][up[i]+4]==i && YZM[lf[i]+2][up[i]+4]==i )
			result[i-1]='5';
		if( YZM[lf[i]+0][up[i]+0]==0 && YZM[lf[i]+1][up[i]+0]==0 && YZM[lf[i]+2][up[i]+0]==i &&
			YZM[lf[i]+0][up[i]+1]==0 && YZM[lf[i]+1][up[i]+1]==i && YZM[lf[i]+2][up[i]+1]==i &&
			YZM[lf[i]+0][up[i]+2]==i && YZM[lf[i]+1][up[i]+2]==i && YZM[lf[i]+2][up[i]+2]==0 &&
			YZM[lf[i]+0][up[i]+3]==i && YZM[lf[i]+1][up[i]+3]==i && YZM[lf[i]+2][up[i]+3]==0 &&
			YZM[lf[i]+0][up[i]+4]==i && YZM[lf[i]+1][up[i]+4]==i && YZM[lf[i]+2][up[i]+4]==0 )
			result[i-1]='6';
		if( YZM[lf[i]+0][up[i]+0]==i && YZM[lf[i]+1][up[i]+0]==i && YZM[lf[i]+2][up[i]+0]==i &&
			YZM[lf[i]+0][up[i]+1]==0 && YZM[lf[i]+1][up[i]+1]==0 && YZM[lf[i]+2][up[i]+1]==0 &&
			YZM[lf[i]+0][up[i]+2]==0 && YZM[lf[i]+1][up[i]+2]==0 && YZM[lf[i]+2][up[i]+2]==0 &&
			YZM[lf[i]+0][up[i]+3]==0 && YZM[lf[i]+1][up[i]+3]==0 && YZM[lf[i]+2][up[i]+3]==0 &&
			YZM[lf[i]+0][up[i]+4]==0 && YZM[lf[i]+1][up[i]+4]==0 && YZM[lf[i]+2][up[i]+4]==0 )
			result[i-1]='7';
		if( YZM[lf[i]+0][up[i]+0]==0 && YZM[lf[i]+1][up[i]+0]==0 && YZM[lf[i]+2][up[i]+0]==i &&
			YZM[lf[i]+0][up[i]+1]==0 && YZM[lf[i]+1][up[i]+1]==i && YZM[lf[i]+2][up[i]+1]==i &&
			YZM[lf[i]+0][up[i]+2]==i && YZM[lf[i]+1][up[i]+2]==i && YZM[lf[i]+2][up[i]+2]==0 &&
			YZM[lf[i]+0][up[i]+3]==0 && YZM[lf[i]+1][up[i]+3]==i && YZM[lf[i]+2][up[i]+3]==i &&
			YZM[lf[i]+0][up[i]+4]==0 && YZM[lf[i]+1][up[i]+4]==0 && YZM[lf[i]+2][up[i]+4]==i )
			result[i-1]='8';
		if( YZM[lf[i]+0][up[i]+0]==0 && YZM[lf[i]+1][up[i]+0]==0 && YZM[lf[i]+2][up[i]+0]==i &&
			YZM[lf[i]+0][up[i]+1]==0 && YZM[lf[i]+1][up[i]+1]==i && YZM[lf[i]+2][up[i]+1]==i &&
			YZM[lf[i]+0][up[i]+2]==i && YZM[lf[i]+1][up[i]+2]==i && YZM[lf[i]+2][up[i]+2]==0 &&
			YZM[lf[i]+0][up[i]+3]==i && YZM[lf[i]+1][up[i]+3]==i && YZM[lf[i]+2][up[i]+3]==0 &&
			YZM[lf[i]+0][up[i]+4]==0 && YZM[lf[i]+1][up[i]+4]==i && YZM[lf[i]+2][up[i]+4]==i )
			result[i-1]='9';
	}
	printf("%s\n",result);//输出识别结果

	return 0;
}

