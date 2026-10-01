#include<iostream>
#include<vector>

template<class T>
int order_search(const std::vector<T>&v,T target)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==target)
            return i;
    }
    return -1;
}

void test()
{
    std::vector<int> v1={1,4,7,14,6,123,666};
    std::vector<char> v2={'w','a','t','u','o','p'};
    int index=0;

    if((index=order_search(v1,999))!=-1)
        std::cout<<"find 999,index:"<<index<<std::endl;
    else
        std::cout<<"999 is not exist"<<std::endl;
    if((index=order_search(v2,'t'))!=-1)
        std::cout<<"find t,index:"<<index<<std::endl;
    else
        std::cout<<"t is not exist"<<std::endl;
}

int main()
{
    test();

    return 0;
}