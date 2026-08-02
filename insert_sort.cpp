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

void InsertSort(int* arr,int len,int flag)
{
	int temp;
	if(flag)
	{
		for(int i=0;i<len-1;i++)
		{
			temp=arr[i+1];
			for(int j=i;j>=0;j--)
			{
				if(temp<arr[j])
					arr[j+1]=arr[j];
				else
				{
					arr[j+1]=temp;
					break;
				}

				if(j==0)
					arr[j]=temp;
			}
		}
	}
	else
	{
		for(int i=0;i<len-1;i++)
		{
			temp=arr[i+1];
			for(int j=i;j>=0;j--)
			{
				if(temp>arr[j])
					arr[j+1]=arr[j];
				else
				{
					arr[j+1]=temp;
					break;
				}

				if(j==0)
					arr[j]=temp;
			}
		}
	}
}

int main()
{
	int arr[]={4,7,3,2,-5,101};
	int len=sizeof(arr)/sizeof(int);

	std::cout<<"before:";
	PrintArr(arr,len);

	InsertSort(arr,len,0);

	std::cout<<"after:";
	PrintArr(arr,len);

	return 0;
}
