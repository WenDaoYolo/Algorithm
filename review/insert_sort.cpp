#include<iostream>
#include<vector>

template<class T>
void InsertSortUp(std::vector<T>& v)
{
    auto order_it=v.begin();
    while(order_it!=v.end()-1)
    {
        auto find_it=order_it;
        T value=*(order_it+1);

        while(find_it!=v.begin()-1&&value<*find_it)
        {
            *(find_it+1)=*find_it;
            find_it--;
        }

        *(find_it+1)=value;
        order_it++;
    }
}

template<class T>
void InsertSortDown(std::vector<T>& v)
{
    auto order_it=v.begin();
    while(order_it!=v.end()-1)
    {
        auto find_it=order_it;
        T value=*(order_it+1);

        while(find_it!=v.begin()-1&&value>*find_it)
        {
            *(find_it+1)=*find_it;
            find_it--;
        }

        *(find_it+1)=value;
        order_it++;
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

    InsertSortUp(v1);
    InsertSortDown(v2);
    Print("sort v1: ",v1);
    Print("sort v2: ",v2);
}

int main()
{
    test();

    return 0;
}