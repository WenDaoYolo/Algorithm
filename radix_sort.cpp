#include<iostream>

void PrintArr(int* arr,int len)
{
	for(int i=0;i<len;i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}

void MySwap(int& a,int& b)
{
    //注意：若两个数相同时，异或结果为0
    if(a==b) return;
	a=a^b;
	b=a^b;
	a=a^b;
}

//10个桶，每个桶又可以存储若干数据，可以定义二维动态数组，或自定义桶结构(比较麻烦)

struct bucketnode
{
	int data;
	bucketnode* next;
};

class bucket
{
	public:
		int len;
		bucketnode* head;
		bucketnode* tail;
		
		bucket()
		{
			this->len=0;
			this->head=new bucketnode;
			
			this->head->next=NULL;
			this->head->data=-999;
			this->tail=this->head;
		}
		
		void Add(int e)
		{
			bucketnode* tmp=new bucketnode;
			tmp->data=e;
			
			this->tail->next->data=e;
			tmp->next=NULL;
			this->tail=tmp;
			this->len++;
		}
		
        void Clear()
		{
			while(this->head->next!=NULL)
			{
				bucketnode* tmp=this->head->next;
				this->head->next=tmp->next;
				delete tmp;
			}
			this->len=0;
			this->tail=this->head;
		}

		~bucket()
		{
			while(this->head!=NULL)
			{
				bucketnode* tmp=this->head;
				this->head=tmp->next;
				delete tmp;
			}
			this->len=0;
			this->tail=this->head;
		}
};

int FindMax(int* arr,int len)
{
    int max=arr[0];
    for(int i=1;i<len;i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    return max;
}

void RadixSortUp(int* arr,int len)
{
    bucket arry[10];
    int max=FindMax(arr,len);
    int count=0;

    while(max>0)
    {
        max/=10;
        count++;
    }

    for(int i=0;i<count;i++)
    {
        
    }
}

void RadixSortDown()
{
	
}

int main()
{
	int arr[]={4,3,2,1,4,828,17,14,122};
	int len=sizeof(arr)/sizeof(int);

    std::cout<<"before:";
	PrintArr(arr,len);

	RadixSortUp(arr,len);
	std::cout<<"after:";
	PrintArr(arr,len);

    RadixSortDown();
    std::cout<<"after:";
	PrintArr(arr,len);
	
    return 0;
}