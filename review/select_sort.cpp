#include<iostream>
#include<vector>

template<class T>
void SelectSortUp(std::vector<T>& v)
{
    for(auto it1=v.begin();it1!=v.end()-1;it1++)
    {
        auto min_it=it1;
        for(auto it2=min_it+1;it2!=v.end();it2++)
        {
            if(*it2<*min_it)
                min_it=it2;
        }
        std::swap(*min_it,*it1);
    }
}

template<class T>
void SelectSortDown(std::vector<T>& v)
{
    for(auto it1=v.begin();it1!=v.end()-1;it1++)
    {
        auto max_it=it1;
        for(auto it2=max_it+1;it2!=v.end();it2++)
        {
            if(*it2>*max_it)
                max_it=it2;
        }
        std::swap(*max_it,*it1);
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

    SelectSortUp(v1);
    SelectSortDown(v2);
    Print("sort v1: ",v1);
    Print("sort v2: ",v2);
}

int main()
{
    test();

    return 0;
}