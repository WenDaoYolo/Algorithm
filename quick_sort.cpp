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

void QuickSortUp(int* arr,int left,int right)
{
    if(left>=right)
        return;

    int bv=arr[(left+right)/2];
    int i=left,j=right;
    while(i<=j)
    {
        while(arr[i]<bv&&i<right) i++; 
        while(arr[j]>bv&&j>left) j--;
        if(i<=j)
        {
	        MySwap(arr[i],arr[j]);
	        i++;
	        j--;
        }
    }
    QuickSortUp(arr,left,j);
    QuickSortUp(arr,i,right);
}

void QuickSortDown(int* arr,int left,int right)
{
    if(left>=right)
        return;
        
    int bv=arr[(left+right)/2];
    int i=left,j=right;
    while(i<=j)
    {
        while(arr[i]>bv&&i<right) i++; 
        while(arr[j]<bv&&j>left) j--;
        if(i<=j)
        {
	        MySwap(arr[i],arr[j]);
	        i++;
	        j--;
        }
    }
    QuickSortDown(arr,left,j);
    QuickSortDown(arr,i,right);
}

int main()
{
    int arr[]={-4,3,2,1,4,-2,17,14,122};
	int len=sizeof(arr)/sizeof(int);

	std::cout<<"before:";
	PrintArr(arr,len);

	QuickSortUp(arr,0,len-1);
	std::cout<<"after:";
	PrintArr(arr,len);

    QuickSortDown(arr,0,len-1);
    std::cout<<"after:";
	PrintArr(arr,len);

    return 0;
}