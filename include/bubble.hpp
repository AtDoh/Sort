// Author : AT_Doh
// E-Mail : at.doh.dev@gmail.com
// Created : 2023.06.12
// Bubble Sort 알고리즘을 iterator 를 입력 받는 형식으로 구현함.
#ifndef __BUBBLE_HPP__
#define __BUBBLE_HPP__
#include<pch.hpp>

// 버블 정렬
// 분류 : 제자리 정렬,안정적인 정렬,교환 정렬
// 시간복잡도(비교) : 최악( O(n^2) ),평균( O(n^2) ),최선( O(n^2) )
// 시간복잡도(교환) : 최악( O(n^2) ),평균( O(n^2) ),최선( O(n^2) )
// 공간복잡도 : O(1)
// 인접한 원소들간의 비교를 통해 가장 큰 값이 뒤쪽으로 점차적으로 이동하면서 뒤 쪽부터 값을 확정한다.
// 이동하는 원소들이 마치 거품이 수면위로 올라가는 것 같다고 해서 버블 정렬이다.
template<typename It,typename Comp>
requires std::random_access_iterator<It>
void bubble(It begin,It end,Comp comp=pred::less<>())
{
    It now;
    while(end!=begin)
    {
        now=begin;
        while(std::next(now)!=end)
        {
            //
            if(!comp(*now,*std::next(now))) std::iter_swap(now,std::next(now));
            now=std::next(now);
        }
        end=std::prev(end);
    }
}

template<typename It>
requires std::random_access_iterator<It>
void bubble(It begin,It end)
{
    bubble(begin,end,pred::less<std::iter_value_t<It> >());
}
// 개선 가능성
// *한 주기를 반복하는 동안 한번도 교환이 일어나지 않았다면 정렬된 것으로 판단하도록 개선할 수 있다.


#endif