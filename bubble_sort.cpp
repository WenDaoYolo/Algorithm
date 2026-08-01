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
void BubbleSort(int* arr,int len,int flag)
{
    bool exit=true;
	if(flag)
	{
		for(int i=0;i<len;i++)
		{
            exit=true;
			for(int j=0;j<len-i-1;j++)
			{
				if(arr[j]>arr[j+1])
				{
                    MySwap(arr[j],arr[j+1]);
                    exit=false;
                }
			}

            if(exit)
                break;
		}
	}
	else
	{
		for(int i=0;i<len;i++)
		{
            exit=true;
			for(int j=0;j<len-i-1;j++)
			{
				if(arr[j]<arr[j+1])
				{
                    MySwap(arr[j],arr[j+1]);
                    exit=false;
                }
			}

            if(exit)
                break;
		}
	}
}

int main()
{
	int arr1[]={1,14,6,33,25,88,-4};
	int len=sizeof(arr1)/sizeof(int);
	
	std::cout<<"before:";
	PrintArr(arr1,len);
	
	BubbleSort(arr1,len,1);
	
	std::cout<<"after:";
	PrintArr(arr1,len);
	
	return 0;
}