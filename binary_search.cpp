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

int BinarySearch(int* arr,int len,int target)
{
    int left=0,right=len-1,mid=(left+right)/2;
    while(left<=right)
    {
        if(arr[mid]==target)
            return mid;
        else if(arr[mid]>target)
        {
            right=mid-1;
            mid=(left+right)/2;
        }
        else
        {
            left=mid+1;
            mid=(left+right)/2;
        }
    }
    return -1;
}

int main()
{
	int arr[]={4,7,3,2,-5,101};
	int len=sizeof(arr)/sizeof(int);
    int pos=-1;

	std::cout<<"before:";
	PrintArr(arr,len);
    QuickSortUp(arr,0,len-1);
    std::cout<<"after:";
    PrintArr(arr,len);

    pos=BinarySearch(arr,len,7);
    if(pos>=0)
        std::cout<<"find it,position:"<<pos<<std::endl;
    else
        std::cout<<"not exist"<<std::endl;

    return 0;
}