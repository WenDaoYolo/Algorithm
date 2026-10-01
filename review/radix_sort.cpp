#include<algorithm>
#include<iostream>
#include<vector>

void RadixSortUp(std::vector<int>& v,int radix_nums)
{
    auto max_it=std::max_element(v.begin(),v.end());
    int max=*max_it,count=0;
    while(max)
    {
        count++;
        max/=10;
    }

    std::vector<std::vector<int>> bucket(radix_nums);

    int n=1;
    while(count>0)
    {
        for(int i=0;i<v.size();i++)
        {
            int index=(v[i]/n)%10;
            bucket[index].push_back(v[i]);
        }
        count--,n*=10;

        for(int v_index=0,j=0;j<radix_nums;j++)
        {
            for(auto it=bucket[j].begin();it!=bucket[j].end();it++)
                v[v_index++]=*it;
            bucket[j].clear();
        }
    }
}

void RadixSortDown(std::vector<int>& v,int radix_nums)
{
    auto max_it=std::max_element(v.begin(),v.end());
    int max=*max_it,count=0;
    while(max)
    {
        count++;
        max/=10;
    }

    std::vector<std::vector<int>> bucket(radix_nums);

    int n=1;
    while(count>0)
    {
        for(int i=0;i<v.size();i++)
        {
            int index=(v[i]/n)%10;
            bucket[index].push_back(v[i]);
        }
        count--,n*=10;

        for(int v_index=0,j=radix_nums-1;j>=0;j--)
        {
            for(auto it=bucket[j].begin();it!=bucket[j].end();it++)
                v[v_index++]=*it;
            bucket[j].clear();
        }
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
    std::vector<int> v1={6,4,1,199,445,114,45};
    std::vector<int> v2={6,4,1,199,445,114,45};

    Print("v1: ",v1);
    Print("v2: ",v2);
    RadixSortUp(v1,10);
    RadixSortDown(v2,10);
    Print("sort v1: ",v1);
    Print("sort v2: ",v2);
}

int main()
{
    test();

    return 0;
}