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

//flag: 1升序 0降序
void SelectSort(int* arr,int len,int flag)
{
	if(flag)
	{
		for(int i=0;i<len-1;i++)
		{
			int min=i;
			for(int j=i+1;j<len;j++)
			{
				if(arr[min]>arr[j])
					min=j;
			}
			if(i!=min)
				MySwap(arr[min],arr[i]);
		}
	}
	else
	{
		for(int i=0;i<len-1;i++)
		{
			int max=i;
			for(int j=i+1;j<len;j++)
			{
				if(arr[max]<arr[j])
					max=j;
			}
			if(i!=max)
				MySwap(arr[max],arr[i]);
		}
	}
}

int main()
{
	int arr[]={4,7,3,2,-5,101};
	int len=sizeof(arr)/sizeof(int);

	std::cout<<"before:";
	PrintArr(arr,len);

	SelectSort(arr,len,0);

	std::cout<<"after:";
	PrintArr(arr,len);

    return 0;
}