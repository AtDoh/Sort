#include<iostream>
#include<vector>
#include<deque>
#include<sort.hpp>
using namespace std;
int main(int argc,char**argv)
{
    vector<int> arr={3,5,1,7,2,9,1,10,13};
    deque<int> deq={3,5,1,7,2,9,1,10,13};
    // data::heap<int> heap(arr,pred::less<int>());
    // data::heap<int> heap(arr);
    sort::data::heap<int,deque<int>,less<int> > heap(deq);
    // data::heap<int,vector<int>,greater<int> > heap(arr);
    // data::heap<int> heap{pred::less<int>()};
    // data::heap<int,vector<int>,greater<int> > heap;
    for(int const&a:arr) 
    {
        cout<<a<<" ";
        // heap.push(a);
    }
    cout<<"\n";
    while(!heap.empty())
    {
        cout<<heap.top()<<" ";
        heap.pop();
    }
    cout<<"\n";
    sort::heap(arr.begin(),arr.end(),pred::greater<int>());
    for(int const&a:arr) 
    {
        cout<<a<<" ";
    }
    return 0;
}