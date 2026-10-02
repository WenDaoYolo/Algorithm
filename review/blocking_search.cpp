#include<iostream>
#include<vector>

struct idx_node
{
    int start,max,min,len;
    idx_node(int st,int ma,int mi,int le)
    {
        start=st;
        max=ma;
        min=mi;
        len=le;
    }
};

template<class T>
int BlockingSearch(const std::vector<T>& data,const std::vector<idx_node>& idx,T target)
{
    int left=0,right=idx.size()-1,mid;
    while(mid=(left+right)/2,left<=right)
    {
        if(target>data[idx[mid].max])
            left=mid+1;
        else if(target<data[idx[mid].min])
            right=mid-1;
        else
        {
            for(int i=idx[mid].start;i<idx[mid].len;i++)
                if(data[i]==target) return i;
        }
    }
    return -1;
}

///////////////////////////////////////////////////////////////////

void CreateData(std::vector<idx_node>& idx,std::vector<char>& data)
{
    data.push_back('B');
    data.push_back('C');
    data.push_back('A');
    idx.emplace_back(0,1,2,3);

    data.push_back('H');
    data.push_back('J');
    data.push_back('I');
    data.push_back('L');
    data.push_back('K');
    data.push_back('M');
    idx.emplace_back(3,8,3,6);

    data.push_back('O');
    data.push_back('P');
    idx.emplace_back(9,10,9,2);

    data.push_back('Y');
    data.push_back('X');
    data.push_back('Z');
    idx.emplace_back(11,13,12,3);
}

void Test()
{
    std::vector<idx_node> idx;
    std::vector<char> data;
    CreateData(idx,data);

    int index=BlockingSearch(data,idx,'A');
    if(index!=-1)
        std::cout<<"find A,index:"<<index<<std::endl;
    else
        std::cout<<"A is not exist"<<std::endl;
    
    index=BlockingSearch(data,idx,'U');
    if(index!=-1)
        std::cout<<"find U,index:"<<index<<std::endl;
    else
        std::cout<<"U is not exist"<<std::endl;
}

int main()
{
    Test();
    
    return 0;
}