// Author : AT_Doh
// E-Mail : at.doh.dev@gmail.com
// Created : 2023.06.13
// Quick Sort 알고리즘을 iterator 를 입력 받는 형식으로 구현함.
#ifndef __QUICK_HPP__
#define __QUICK_HPP__
#include<pch.hpp>

template<typename It,typename Comp>
requires std::random_access_iterator<It>
It partition(It begin,It end,Comp comp)
{
    if(begin==end||next(begin)==end) return end;
    It pivot=begin,left=next(begin),right=prev(end);
    while(left<=right)
    {
        while(left<=right&&comp(*left,*pivot)) left=next(left);
        while(left<=right&&!comp(*right,*pivot)) right=prev(right);
        if(left<=right) std::iter_swap(left,right);
    }
    std::iter_swap(right,pivot);
    return right;
}
// 선택 정렬
// 분류 : 제자리정렬,불안정적인 정렬,파티셔닝 정렬,분할정복,재귀
// 시간복잡도 : 최악( O(n^2) ),평균( O(n log n) ),최선( O(n log n) )
// 공간복잡도 : O(log n)
// 공간복잡도는 설계에 따라 다르게 나타나는데, 제자리정렬로 구현한경우 재귀로 인해 O(log n) 정도의
// 공간이 추가로 필요하다.
template<typename It,typename Comp>
void quick(It begin,It end,Comp comp=pred::less<>())
{
    It pivot=sort::partition(begin,end,comp);
    if(pivot==end) return;
    quick(begin,pivot,comp);
    quick(next(pivot),end,comp);
}
template<typename It>
void quick(It begin,It end)
{
    quick(begin,end,less<std::iter_value_t<It> >());
}
#endif