#include <stdio.h>
//异或交换两个值
#define swap(a,b) (a^=b,b^=a,a^=b)


void maxheap_down(int data[], int start, int end)
{
	int c = start;
	int l = 2*c + 1;
	int tmp = data[c];//当前节点的大小
	for(;l <= end; c = l,l=2*l +1)//下次循环开始起始位置c初始化为交换的节点，l初始化为交换节点的左孩子
	{
		//l为左右加点中较大的
		if(l < end && data[l] < data[l+1])
			l++;
		if(tmp >= data[l])
			break;
		else
		{
			data[c] = data[l];
			data[l] = tmp;
		}
	}
}

//节点索引为i的左孩子索引为2*i + 1,右孩子索引为2*i+2，父节点索引为floor((i-1)/2)
int main(int argc, char * args[])
{
	printf("args:%s\n", args[0]);
	printf("pid:%d\n", getpid());
	int data[] = {10,100,65,45,87,98,76,98,101};
	int i;
	int ilen = sizeof(data)/sizeof(data[0]);
	printf("origin data\n");
	for(i =0; i < ilen; i++)
		printf("%d ", data[i]);
	printf("\n");
	//初始化为最大堆(排序后为升序),i起始位置为最尾节点的父节点
	for(i = (ilen - 2)/2; i>=0;i-- )
		maxheap_down(data, i, ilen - 1);
	printf("after init heap\n");
	for(i = 0; i< ilen; i++)
		printf("%d ", data[i]);
	printf("\n");
	//堆顶元素依次和末尾元素交换
	for(i = ilen -1 ;i > 0;i--)
	{
		swap(data[0], data[i]);
		maxheap_down(data, 0, i-1);//使剩余元素为一个大顶堆
	}
	printf("after sort heap\n");
	for(i = 0; i< ilen; i++)
		printf("%d ", data[i]);
	printf("\n");
}
