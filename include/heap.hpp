// Author : AT_Doh
// E-Mail : at.doh.dev@gmail.com
// Created : 2023.06.13
// Heap Sort 알고리즘을 iterator 를 입력 받는 형식으로 구현함.
#ifndef __HEAP_HPP__
#define __HEAP_HPP__
#include<pch.hpp>
#include"structure/heap.hpp"
// 힙 소트
// 분류 : 제자리정렬,비교정렬,불안정적인 정렬,선택 정렬
// 시간복잡도: 최악( O(n log n) ),평균( O(n log n) ),최선( O(n log n) )
// 공간복잡도 : O(1)
// Heap 이라는 자료구조를 사용하여 정렬을 수행하는 알고리즘.
// 내림차순 정렬을 위해서는 최소힙, 오름차순 정렬을 위해서는 최대힙을 사용한다.
template<typename It,typename Comp>
requires std::random_access_iterator<It>
void heap(It begin,It end,Comp comp=pred::less<>())
{
    using T=std::iter_value_t<It>;
    int size=std::distance(begin,end);
    // Heap 구조에서 정렬 방식을 템플릿 매개변수로 입력받도록 구현했기 때문에
    // 함수의 매개변수로 정렬 방식을 받는 정렬 함수에서 Heap 을 곧바로 생성할 수 없다.
    // 이를 처리하기 위해 pred::comparison_type 이라는 간단한 템플릿 메타 함수를 
    // 사용하여 입력 받은 정렬 방식 변수에서 정렬 방식 타입을 얻어와 Heap 에 전달해 주었다.
    data::heap<T,std::vector<T>,pred::comparison_type<T,Comp>::type> _heap(begin,end);
    for(It now=begin;now!=end;now=next(now))
    {
        *now=_heap.top();
        _heap.pop();
    }
}
template<typename It>
requires std::random_access_iterator<It>
void heap(It begin,It end)
{
    heap(begin,end,less<std::iter_value_t<It> >());
}
#endif