#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Arr{
	int *pBase; //存储数组第一元素的地址 
	int len;//数组长度 
	int cnt;//数组有效个数 
};

void init_arr(struct Arr *pArr,int len);//初始化 
bool append_arr(struct Arr *pArr,int val);//追加 
bool insert_arr(struct Arr *pArr,int pos,int val);//插入 
bool delete_arr(struct Arr *pArr,int pos,int *pVal);//删除 
bool is_empty(struct Arr *pArr);//是否为空 
bool is_full(struct Arr *pArr);//是否为满 
void sort_arr();//排序 
void show_arr(struct Arr *pArr);//全部输出 
void inversion_arr();//倒置

int main()
{
	struct Arr arr;
	int val;//定义一个要删除的值 
	init_arr(&arr,6);
	
	show_arr(&arr);
	if(append_arr(&arr,1))
	{
		printf("追加成功！\n");
	}else{
		printf("追加失败！\n");
	}
	append_arr(&arr,2);
	append_arr(&arr,3);
	append_arr(&arr,4);
	append_arr(&arr,5);
	//append_arr(&arr,6);
	
	
	
	show_arr(&arr);
	insert_arr(&arr,3,10);
	show_arr(&arr);
	delete_arr(&arr,3,&val);
	show_arr(&arr);
	delete_arr(&arr,3,&val);
	show_arr(&arr);
	delete_arr(&arr,2,&val);
	show_arr(&arr);
	printf("%d ",val);
	
	return 0;
}

//初始化 
void init_arr(struct Arr *pArr,int length)
{
	pArr->pBase=(int *)malloc(sizeof(int)*length);
	if(pArr->pBase==NULL)
	{
		printf("动态分配内存失败！\n");
		exit(-1);//终止整个程序 
	}else{
		pArr->len=length;
		pArr->cnt=0;
	}
	return ;//表示函数结束 
} 


//判断是否为空
bool is_empty(struct Arr *pArr)
{
	if(pArr->cnt==0)
	{
		return true;
	}else{
		return false;
	}		
}

//判断是否已满
bool is_full(struct Arr *pArr)
{
	if(pArr->cnt==pArr->len)
	{
		return true;
	}else{
		return false;
	}
} 


//追加元素
bool append_arr(struct Arr *pArr,int val) 
{
	if(is_full(pArr))
	{
		return false;
	}else{
		pArr->pBase[pArr->cnt]=val;
		(pArr->cnt)++;
		return true;
	}
}

//插入元素
bool insert_arr(struct Arr *pArr,int pos,int val)
{
	//判断输入pos位置是否合法 
	if(is_full(pArr))
	{
		return false;
	}else if(pos<1||pos>pArr->cnt+1||pos>pArr->len){
		return false;
	}
	//先将pos位置既后面的元素后移，然后插入 
	else
	{
		int i=0;
		for(i=pArr->cnt-1;i>pos-1;--i)
		{
			pArr->pBase[i+1]=pArr->pBase[i];
		}
		pArr->pBase[pos-1]=val;
		pArr->cnt++;
		return true;
	}
	
}

//删除元素
bool delete_arr(struct Arr *pArr,int pos,int *pVal)//pos从1开始 
{
	if(is_empty(pArr))
	{
		return false;
	}
	//判断pos位置是否合法 
	else if(pos>pArr->cnt||pos<1)
	{
		return false;
	}
	else
	{
		*pVal=pArr->pBase[pos-1];
		int i=0;
		for(i=pos;i<pArr->cnt-1;++i)
		{
			pArr->pBase[i-1]=pArr->pBase[i];
		}
		pArr->cnt--;
		return true;
	}
} 



//输出全部元素 
void show_arr(struct Arr *pArr)
{
	int i=0;
	if(is_empty(pArr))
	{
		printf("数组为空！\n");
	}else{
		for(i=0;i<pArr->cnt;++i)
		{
			printf("%d ",pArr->pBase[i]);
		}
		printf("\n");
	}
	return ;
}
