#include <stdio.h>
#include <windows.h>
#include <time.h>

#define Middle_Size 5//窗口长度

typedef struct 
{
	int index ;
	double filterArray[Middle_Size];
}MiddleCoe;

MiddleCoe M_T0;

//double filterArray_x[Middle_Size] = {0.0, 0.0, 0.0, 0.0, 0.0};

double MiddleFilter(const double ResrcData, int *index, double *filterArray)
{
	int i, end, tmp;
	double a[Middle_Size];
	filterArray[*index] = ResrcData;
	//printf("%d\n",index);
	for(i = 0; i < Middle_Size; i++)
	{
		a[i] = filterArray[i];
	}
	//冒泡排序
	for( i = 0; i < Middle_Size - 1; i++)
	{
		int end = i;
		double temp = a[end + 1];
		while(end >= 0 && a[end] > temp)
		{
			a[end + 1] = a[end];
			--end;
		}
		a[end + 1] = temp;
	}
	if((--(*index)) < 0)
		*index = Middle_Size - 1;
	
	return  (a[1] + a[2] + a[3]) / 3;    //(a[1] + a[2] + a[3]) / 3; 
}

int main(){
    double r;
	double res=5.2,res_f;//假设5.2为实际值，res_f为测量值
	M_T0.index = 0;//VS进行初始化
	double noise;
	for (int i = 0;i<100;i++){
		noise = ((rand()%21+1)*0.1-1.0)*0.5;//噪声
		/*if(i%2==0){
			res_f = res + (i%10)*0.1;
		}
		else{
			res_f = res - (i%10)*0.1;
		}*/
		res_f = res + noise;
    	r = MiddleFilter(res_f,&M_T0.index, M_T0.filterArray);
    	printf("%d: %lf  %d  %lf\n",i,r,M_T0.index,noise);
		//res = res+0.2;
		}
    system("pause");
    return 0;
}
