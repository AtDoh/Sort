#include<iostream>
#include<vector>
#include<sort.hpp>
#include<algorithm>
using namespace std;
int main(int argc,char**argv)
{
    vector<int> arr={3,5,1,7,2,9,1,10,13};
    for(int const&a:arr) cout<<a<<" ";
    sort::merge(arr.begin(),arr.end());
    cout<<"\n";
    for(int const&a:arr) cout<<a<<" ";
    sort::merge(arr.begin(),arr.end(),greater_equal<int>());
    cout<<"\n";
    for(int const&a:arr) cout<<a<<" ";
    return 0;
}