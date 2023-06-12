// Author : AT_Doh
// E-Mail : at.doh.dev@gmail.com
// Created : 2023.06.12
// Selection Sort 알고리즘을 iterator 를 입력 받는 형식으로 구현함.
#ifndef __SELECTION_HPP__
#define __SELECTION_HPP__
#include<pch.hpp>

// 선택 정렬
// 분류 : 제자리정렬,불안정적인 정렬,선택 정렬
// 시간복잡도(비교) : 최악( O(n^2) ),평균( O(n^2) ),최선( O(n^2) )
// 시간복잡도(교환) : 최악( O(n) ),평균( O(n) ),최선( O(n) )
// 공간복잡도 : O(1)
// 현재 구간의 가장 앞에서 부터 값을 확정지어 나가면서, 현재 구간의 가장 앞에 가장 작은 값이 오도록 값을 선택해서 교환한다.
// 1 7(1) 7(2) 3 2 와 같은 값이 주어질때
// 1 2 7(2) 3 7(1) -> 1 2 3 7(2) 7(1) 로 정렬되기 때문에 불안정한 정렬이다.
template<typename It,typename Comp>
requires std::random_access_iterator<It>
void selection(It begin,It end,Comp comp=pred::less<>())
{
    It now,tmp;
    while(begin!=end)
    {
        tmp=now=begin;
        while(next(now)!=end)
        {
            // 현재 구간에서 가장 작은 값의 위치를 찾는다.
            if(!comp(*tmp,*now)) tmp=now;
            now=std::next(now);
        }
        // 남은 구간 중 가장 작은 값을 찾아서 해당 구간의 가장 앞쪽 값과 교환한다.
        if(tmp!=end) std::iter_swap(begin,tmp);
        begin=std::next(begin);
    }
}
template<typename It>
requires std::random_access_iterator<It>
void selection(It begin,It end)
{
    selection(begin,end,pred::less<std::iter_value_t<It> >());
}
// 개선 가능성
// *한 주기를 수행하면서 최소값 뿐만 아니라 최대값도 찾아서 앞/뒤 값을 확정해 나가면 탐색 횟수를 절반으로 줄일 수 있다.
// *한 번 최솟값을 찾을때, 동일한 모든 값을 찾아서 미리정렬. 동일한 값이 많을 수록 유용함.


#endif