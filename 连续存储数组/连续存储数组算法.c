#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Arr{
	int *pBase; //�洢�����һԪ�صĵ�ַ 
	int len;//���鳤�� 
	int cnt;//������Ч���� 
};

void init_arr(struct Arr *pArr,int len);//��ʼ�� 
bool append_arr(struct Arr *pArr,int val);//׷�� 
bool insert_arr(struct Arr *pArr,int pos,int val);//���� 
bool delete_arr(struct Arr *pArr,int pos,int *pVal);//ɾ�� 
bool is_empty(struct Arr *pArr);//�Ƿ�Ϊ�� 
bool is_full(struct Arr *pArr);//�Ƿ�Ϊ�� 
void sort_arr();//���� 
void show_arr(struct Arr *pArr);//ȫ����� 
void inversion_arr();//����

int main()
{
	struct Arr arr;
	int val;//����һ��Ҫɾ����ֵ 
	init_arr(&arr,6);
	
	show_arr(&arr);
	if(append_arr(&arr,1))
	{
		printf("׷�ӳɹ���\n");
	}else{
		printf("׷��ʧ�ܣ�\n");
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

//��ʼ�� 
void init_arr(struct Arr *pArr,int length)
{
	pArr->pBase=(int *)malloc(sizeof(int)*length);
	if(pArr->pBase==NULL)
	{
		printf("��̬�����ڴ�ʧ�ܣ�\n");
		exit(-1);//��ֹ�������� 
	}else{
		pArr->len=length;
		pArr->cnt=0;
	}
	return ;//��ʾ�������� 
} 


//�ж��Ƿ�Ϊ��
bool is_empty(struct Arr *pArr)
{
	if(pArr->cnt==0)
	{
		return true;
	}else{
		return false;
	}		
}

//�ж��Ƿ�����
bool is_full(struct Arr *pArr)
{
	if(pArr->cnt==pArr->len)
	{
		return true;
	}else{
		return false;
	}
} 


//׷��Ԫ��
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

//����Ԫ��
bool insert_arr(struct Arr *pArr,int pos,int val)
{
	//�ж�����posλ���Ƿ�Ϸ� 
	if(is_full(pArr))
	{
		return false;
	}else if(pos<1||pos>pArr->cnt+1||pos>pArr->len){
		return false;
	}
	//�Ƚ�posλ�üȺ����Ԫ�غ��ƣ�Ȼ����� 
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

//ɾ��Ԫ��
bool delete_arr(struct Arr *pArr,int pos,int *pVal)//pos��1��ʼ 
{
	if(is_empty(pArr))
	{
		return false;
	}
	//�ж�posλ���Ƿ�Ϸ� 
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



//���ȫ��Ԫ�� 
void show_arr(struct Arr *pArr)
{
	int i=0;
	if(is_empty(pArr))
	{
		printf("����Ϊ�գ�\n");
	}else{
		for(i=0;i<pArr->cnt;++i)
		{
			printf("%d ",pArr->pBase[i]);
		}
		printf("\n");
	}
	return ;
}
