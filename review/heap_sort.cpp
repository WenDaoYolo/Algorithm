#include<iostream>
#include<vector>

template<class T>
void AdjustBigHeap(std::vector<T>& v,int root,int end)
{
    int left=root*2+1,right=root*2+2,max=root;
    if(left<end&&v[max]<v[left])
        max=left;
    if(right<end&&v[max]<v[right])
        max=right;

    if(max!=root)
    {
        std::swap(v[max],v[root]);
        AdjustBigHeap(v,max,end);
    }
}

template<class T>
void BigHeapSort(std::vector<T>& v)
{
    for(int i=v.size()/2-1;i>=0;i--)
        AdjustBigHeap(v,i,v.size());
    
    for(int j=v.size()-1;j>0;j--)
    {
        std::swap(v[0],v[j]);
        AdjustBigHeap(v,0,j);
    }
}

template<class T>
void AdjustSmallHeap(std::vector<T>& v,int root,int end)
{
    int left=root*2+1,right=root*2+2,min=root;
    if(left<end&&v[min]>v[left])
        min=left;
    if(right<end&&v[min]>v[right])
        min=right;

    if(min!=root)
    {
        std::swap(v[min],v[root]);
        AdjustSmallHeap(v,min,end);
    }
}

template<class T>
void SmallHeapSort(std::vector<T>& v)
{
    for(int i=v.size()/2-1;i>=0;i--)
        AdjustSmallHeap(v,i,v.size());
    
    for(int j=v.size()-1;j>0;j--)
    {
        std::swap(v[0],v[j]);
        AdjustSmallHeap(v,0,j);
    }
}

////////////////////////////////////////////////////////////

template<class T>
void Print(const char* str,std::vector<T>& v)
{
    std::cout<<str;
    for(auto it1=v.begin();it1!=v.end();it1++)
        std::cout<<*it1<<" ";
    std::cout<<std::endl;
}

void test()
{
    std::vector<int> v1={6,4,1,-3,-4,114,45};
    std::vector<char> v2={'W','C','A','D','T','L','P'};

    Print("v1: ",v1);
    Print("v2: ",v2);

    BigHeapSort(v1);
    SmallHeapSort(v2);
    Print("sort v1: ",v1);
    Print("sort v2: ",v2);
}

int main()
{
    test();

    return 0;
}