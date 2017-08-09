#include <stdio.h>

void quick_sort(int s[], int l, int r)
{
	int i,j,x;
	if(l < r)
	{
		i = l;
		j= r;
		x = s[i];//初始元素位置取第一个
		while( i < j )
		{
			while(i < j && s[j] > x)//从右往左找到第一个小于x的元素
				j--;
			if(i < j)
				s[i++] = s[j];
			while(i < j && s[i] < x)//从左往右找第一个大于x的元素
				i++;
			if(i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quick_sort(s, l, i-1);//递归调用
		quick_sort(s, i+1, r);
	}
}
int main(int argc,char * args[])
{
	int data[] = {50,100,65,45,87,8,98,76,98,101};
	int i;
	int ilen = sizeof(data)/sizeof(data[0]);
	printf("origin data\n");
	for(i = 0; i< ilen; i++)
		printf("%d ", data[i]);
	printf("\n");
	quick_sort(data, 0, ilen-1);
	printf("after sort\n");
	for(i = 0; i< ilen; i++)
		printf("%d ", data[i]);
	printf("\n");
}
