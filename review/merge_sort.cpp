#include<iostream>
#include<vector>

template<class T>
void MergeSortUp(std::vector<T>& v,std::vector<T>& tmp,int left,int right)
{
    if(left>=right) return;

    int mid=(left+right)/2;
    MergeSortUp(v,tmp,left,mid);
    MergeSortUp(v,tmp,mid+1,right);

    int i=left,j=mid+1,index=0;
    while(i<=mid&&j<=right)
    {
        if(v[i]<=v[j])
            tmp[index++]=v[i++];
        else
            tmp[index++]=v[j++];
    }
    while(i<=mid) tmp[index++]=v[i++];
    while(j<=right) tmp[index++]=v[j++];

    for(int k=0;k<index;k++) v[left+k]=tmp[k];
}

template<class T>
void MergeSortDown(std::vector<T>& v,std::vector<T>& tmp,int left,int right)
{
    if(left>=right) return;

    int mid=(left+right)/2;
    MergeSortDown(v,tmp,left,mid);
    MergeSortDown(v,tmp,mid+1,right);

    int i=left,j=mid+1,index=0;
    while(i<=mid&&j<=right)
    {
        if(v[i]>=v[j])
            tmp[index++]=v[i++];
        else
            tmp[index++]=v[j++];
    }
    while(i<=mid) tmp[index++]=v[i++];
    while(j<=right) tmp[index++]=v[j++];
    
    for(int k=0;k<index;k++) v[left+k]=tmp[k];
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
    std::vector<int> v1_tmp=v1;
    std::vector<char> v2={'W','C','A','D','T','L','P'};
    std::vector<char> v2_tmp=v2;

    Print("v1: ",v1);
    Print("v2: ",v2);

    MergeSortUp(v1,v1_tmp,0,v1.size()-1);
    MergeSortDown(v2,v2_tmp,0,v2.size()-1);
    Print("sort v1: ",v1);
    Print("sort v2: ",v2);
}

int main()
{
    test();
    
    return 0;
}