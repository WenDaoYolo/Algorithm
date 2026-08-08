#include<iostream>
#include<string.h>

void PrintArr(int* arr,int len)
{
	for(int i=0;i<len;i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}

void MergeSortUp(int* arr,int* temp,int left,int right)
{
	if(left>=right) return;
	
	int mid=(left+right)/2;
	MergeSortUp(arr,temp,left,mid);
	MergeSortUp(arr,temp,mid+1,right);
	
	int index=0,i=left,j=mid+1;
	while(i<=mid&&j<=right)
	{
		if(arr[i]<=arr[j])
			temp[index++]=arr[i++];
		else
			temp[index++]=arr[j++];
	}
	
	while(i<=mid) temp[index++]=arr[i++];
	while(j<=right) temp[index++]=arr[j++];
	for(int k=0;k<index;k++) arr[left+k]=temp[k];
}

void MergeSortDown(int* arr,int* temp,int left,int right)
{
    if(left>=right) return;
	
	int mid=(left+right)/2;
	MergeSortDown(arr,temp,left,mid);
	MergeSortDown(arr,temp,mid+1,right);
	
	int index=0,i=left,j=mid+1;
	while(i<=mid&&j<=right)
	{
		if(arr[i]>=arr[j])
			temp[index++]=arr[i++];
		else
			temp[index++]=arr[j++];
	}
	
	while(i<=mid) temp[index++]=arr[i++];
	while(j<=right) temp[index++]=arr[j++];
	for(int k=0;k<index;k++) arr[left+k]=temp[k];
}

int main()
{   
    int arr[]={-4,3,2,1,4,-2,17,14,122};
	int len=sizeof(arr)/sizeof(int);
    int* temp=new int[len];
    memset(temp,0,len*sizeof(int));

	std::cout<<"before:";
	PrintArr(arr,len);

	MergeSortUp(arr,temp,0,len-1);
	std::cout<<"after:";
	PrintArr(arr,len);

    MergeSortDown(arr,temp,0,len-1);
    std::cout<<"after:";
	PrintArr(arr,len);

    delete[] temp;
    return 0;
}