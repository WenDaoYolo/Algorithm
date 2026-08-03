#include<iostream>

void PrintArr(int* arr,int len)
{
	for(int i=0;i<len;i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}

void MySwap(int& a,int& b)
{
	a=a^b;
	b=a^b;
	a=a^b;
}

void QuickSortUp(int* arr,int left,int right)
{
    int base=(left+right)/2;
    if(left+1==right||left==right)
    {
        if(arr[left]>arr[right])
            MySwap(arr[left],arr[right]);
    }
    else
    {
        int i=left,j=right;
        while(i<j)
        {
            while(arr[i]<arr[base])
                i++;
            while(arr[j]>arr[base])
                j--;
            if(i<j)
                MySwap(arr[i],arr[j]);
        }
        QuickSortUp(arr,left,base);
        QuickSortUp(arr,base+1,right);
    }
}

void QuickSortDown(int* arr,int left,int right)
{
    int base=(left+right)/2;
    if(left+1==right||left==right)
    {
        if(arr[left]<arr[right])
            MySwap(arr[left],arr[right]);
    }
    else
    {
        int i=left,j=right;
        while(i<j)
        {
            while(arr[i]>arr[base])
                i++;
            while(arr[j]<arr[base])
                j--;
            if(i<j)
                MySwap(arr[i],arr[j]);
        }
        QuickSortDown(arr,left,base);
        QuickSortDown(arr,base+1,right);
    }
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