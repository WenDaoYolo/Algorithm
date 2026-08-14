#include<iostream>

struct IndexNode
{
    int block_max,block_min;
    int start;
    int len;
};

struct IndexTable
{
    IndexNode* ptr;
    int len;
};

int OrderSearch(int* arr,int start,int len,int target)
{
    for(int i=start;i<start+len;i++)
    {
        if(arr[i]==target)
            return i;
    }
    return -1;
}

int BlockingSearch(IndexTable& idxt,int* arr,int a_len,int target)
{
    int left=0,right=idxt.len-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(target>(idxt.ptr)[mid].block_max)
            left=mid+1;
        else if(target<(idxt.ptr)[mid].block_min)
            right=mid-1;
        else
        {
            int pos=OrderSearch(arr,idxt.ptr[mid].start,idxt.ptr[mid].len,target);
            if(pos>=0)
                return pos;
        }
    }
    return -1;
}      

void CreatIndexTable(IndexTable& idxt)
{
    idxt.len=4;
    idxt.ptr=new IndexNode[idxt.len];

    idxt.ptr[0].start=0;
    idxt.ptr[0].block_max=13;
    idxt.ptr[0].block_min=6;
    idxt.ptr[0].len=3;

    idxt.ptr[1].start=3;
    idxt.ptr[1].block_max=22;
    idxt.ptr[1].block_min=14;
    idxt.ptr[1].len=5;

    idxt.ptr[2].start=8;
    idxt.ptr[2].block_max=136;
    idxt.ptr[2].block_min=60;
    idxt.ptr[2].len=3;

    idxt.ptr[3].start=11;
    idxt.ptr[3].block_max=178;
    idxt.ptr[3].block_min=144;
    idxt.ptr[3].len=3;
}

void PrintArr(int* arr,int len)
{
	for(int i=0;i<len;i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}

int main()
{
    int data[14]={13,6,10,14,18,16,14,22,132,136,60,144,178,166};  
    int len=sizeof(data)/sizeof(int);
    IndexTable idxt;
    CreatIndexTable(idxt);

    std::cout<<"data:";
    PrintArr(data,len);

    int pos=BlockingSearch(idxt,data,len,136);
    if(pos>=0)
        std::cout<<"find it,position:"<<pos<<std::endl;
    else
        std::cout<<"not exist"<<std::endl;

    delete[] idxt.ptr;
    idxt.ptr=NULL;
    return 0;
}