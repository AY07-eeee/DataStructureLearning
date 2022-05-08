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
bool insert_arr();//���� 
bool delete_arr();//ɾ�� 
bool is_empty(struct Arr *pArr);//�Ƿ�Ϊ�� 
bool is_full(struct Arr *pArr);//�Ƿ�Ϊ�� 
void sort_arr();//���� 
void show_arr(struct Arr *pArr);//ȫ����� 
void inversion_arr();//����

int main()
{
	struct Arr arr;
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
	append_arr(&arr,6);
	
	
	
	show_arr(&arr);
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
