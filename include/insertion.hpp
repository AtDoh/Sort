// Author : AT_Doh
// E-Mail : at.doh.dev@gmail.com
// Created : 2023.06.12
// Insertion Sort 알고리즘을 iterator 를 입력 받는 형식으로 구현함.
#ifndef __INSERTION_HPP__
#define __INSERTION_HPP__
#include<pch.hpp>
// 삽입 정렬
// 분류 : 제자리정렬,안정적인 정렬,삽입 정렬
// 시간복잡도(비교) : 최악( O(n^2) ),평균( O(n^2) ),최선( O(n^2) )
// 시간복잡도(교환) : 최악( O(n^2) ),평균( O(n^2) ),최선( O(n^2) )
// 공간복잡도 : O(1)
// 주어진 구간을 정렬된 구간, 정렬되지 않은 구간으로 나누어서 정렬되지 않은 구간의 값들을
// 정렬된 구간에 삽입할 위치를 찾아서 삽입한다.
// 중간에 삽입하기 때문에 배열의 경우 삽입한 위치부터 삽입한 값이 있던 원래 위치 앞 까지의 모든 값들을
// 한 칸 씩 뒤로 밀어야 한다.
template<typename It,typename Comp>
requires std::random_access_iterator<It>
void insertion(It begin,It end,Comp comp=pred::less<>())
{
    std::iter_value_t<It> val;
    It sortedBegin=begin,sortedEnd=begin;
    It now,tmp;
    while(begin!=end)
    {
        val=*begin;
        now=sortedBegin;
        while(now!=sortedEnd&&!comp(*begin,*now)) now=std::next(now);
        tmp=begin;
        while(now<tmp) 
        {
            iter_swap(tmp,prev(tmp));
            tmp=prev(tmp);
        }
        *now=val;
        sortedEnd=std::next(sortedEnd);
        begin=std::next(begin);
    }
}

template<typename It>
requires std::random_access_iterator<It>
void insertion(It begin,It end)
{
    insertion(begin,end,pred::less<std::iter_value_t<It> >());
}

#endif