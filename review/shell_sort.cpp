#include<iostream>
#include<vector>

template<class T>
void ShellSortUp(std::vector<T>& v)
{
    for(int grap=v.size()/2;grap>=1;grap/=2)
    {
        for(auto it1=v.begin();it1<v.end()-1;it1+=grap)
        {
            auto order_it=it1,find_it=order_it;
            T value=*(order_it+grap);

            while(find_it!=v.begin()-grap&&value<*find_it)
            {
                *(find_it+grap)=*find_it;
                find_it-=grap;
            }
            *(find_it+grap)=value;
        }
    }
}

template<class T>
void ShellSortDown(std::vector<T>& v)
{
    for(int grap=v.size()/2;grap>=1;grap/=2)
    {
        for(auto it1=v.begin();it1<v.end()-1;it1+=grap)
        {
            auto order_it=it1,find_it=order_it;
            T value=*(order_it+grap);

            while(find_it!=v.begin()-grap&&value>*find_it)
            {
                *(find_it+grap)=*find_it;
                find_it-=grap;
            }
            *(find_it+grap)=value;
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
    std::vector<int> v1={6,4,1,-3,-4,114,45};
    std::vector<char> v2={'W','C','A','D','T','L','P'};

    Print("v1: ",v1);
    Print("v2: ",v2);

    ShellSortUp(v1);
    ShellSortDown(v2);
    Print("sort v1: ",v1);
    Print("sort v2: ",v2);
}

int main()
{
    test();

    return 0;
}