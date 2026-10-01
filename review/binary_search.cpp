#include<iostream>
#include<vector>

template<class T>
int binary_search(const std::vector<T>& v,T target)
{
    int left=0,right=v.size()-1,mid=(left+right)/2;
    while(left<=right)
    {
        if(v[mid]<target)
            left=mid+1;
        else if(v[mid]>target)
            right=mid-1;
        else
            return mid;
        mid=(left+right)/2;
    }
    return -1;
}

///////////////////////////////////////////////////////////

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

void test()
{
    std::vector<int> v1={1,3,5,6,9,14};
    std::vector<char> v2={'w','a','c','d','y'};

    int index=0;

    if((index=binary_search(v1,6))!=-1)
        std::cout<<"find 6,index:"<<index<<std::endl;
    else
        std::cout<<"6 is not exist"<<std::endl;

    //unorder
    if((index=binary_search(v2,'w'))!=-1)
        std::cout<<"find w,index:"<<index<<std::endl;
    else
        std::cout<<"w is not exist"<<std::endl;

    //order
    QuickSortUp(v2,0,v2.size()-1);
    if((index=binary_search(v2,'w'))!=-1)
        std::cout<<"find w,index:"<<index<<std::endl;
    else
        std::cout<<"w is not exist"<<std::endl;
}

int main()
{
    test();

    return 0;
}