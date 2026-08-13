#include<iostream>

void PrintArr(int* arr,int len)
{
	for(int i=0;i<len;i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}

int OrderSearch(int* arr,int len,int target)
{
    for(int i=0;i<len;i++)
    {
        if(arr[i]==target)
            return i;
    }
    return -1;
}   

int main()
{
	int arr[]={4,7,3,2,-5,101};
	int len=sizeof(arr)/sizeof(int);
    int pos=-1;

	std::cout<<"data:";
	PrintArr(arr,len);
    pos=OrderSearch(arr,len,2);

    if(pos>=0)
        std::cout<<"find it,position:"<<pos<<std::endl;
    else
        std::cout<<"not exist"<<std::endl;

    return 0;
}