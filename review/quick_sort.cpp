#include<iostream>
#include<vector>

template<class T>
void QuickSortUp(std::vector<T>& v,int left,int right)
{
    if(left>=right) return;
    T bvalue=v[(left+right)/2];
    auto left_it=v.begin()+left,right_it=v.begin()+right;

    while(left_it<=right_it)
    {
        while(*left_it<bvalue) left_it++;
        while(*right_it>bvalue) right_it--;
        if(left_it<=right_it)
        {
            std::swap(*left_it,*right_it);
            left_it++;
            right_it--;
        }
    }
    QuickSortUp(v,left,right_it-v.begin());
    QuickSortUp(v,left_it-v.begin(),right);
}

template<class T>
void QuickSortDown(std::vector<T>& v,int left,int right)
{
    if(left>=right) return;
    T bvalue=v[(left+right)/2];
    auto left_it=v.begin()+left,right_it=v.begin()+right;

    while(left_it<=right_it)
    {
        while(*left_it>bvalue) left_it++;
        while(*right_it<bvalue) right_it--;
        if(left_it<=right_it)
        {
            std::swap(*left_it,*right_it);
            left_it++;
            right_it--;
        }
    }
    QuickSortDown(v,left,right_it-v.begin());
    QuickSortDown(v,left_it-v.begin(),right);
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

    QuickSortUp(v1,0,v1.size()-1);
    QuickSortDown(v2,0,v2.size()-1);
    Print("sort v1: ",v1);
    Print("sort v2: ",v2);
}

int main()
{
    test();

    return 0;
}