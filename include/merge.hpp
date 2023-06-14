// Author : AT_Doh
// E-Mail : at.doh.dev@gmail.com
// Created : 2023.06.14
// Merge Sort 알고리즘을 iterator 를 입력 받는 형식으로 구현함.
#ifndef __MERGE_HPP__
#define __MERGE_HPP__
#include<pch.hpp>
template<typename It>
void copy_forword(It&src,It&tar)
{
    *tar=*src;
    tar=std::next(tar);
    src=std::next(src);
}

// 병합 정렬
// 분류 : 비교정렬,안정적인 정렬,합병 정렬,분할정복,재귀
// 시간복잡도 : 최악( O(n log n) ),평균( O(n log n) ),최선( O(n log n) )
// 공간복잡도 : O(n)
// 주어진 구간을 더이상 쪼갤수 없을때 까지 하나 이상의 항목을 포함하고 있는
// n 개의 조각으로 쪼개어 나간후에, 각 구간들을 정렬하면서 병합해 나가는 정렬 알고리즘.
// 병합 정렬은 외부 정렬에도 적용이 가능하다. 전체 데이터를 몇개의 구간으로 나누고 이들 구간들은
// 내부 정렬을 통해 정렬하고 각 구간별로 파일에 저장한다.
// 각 파일별로 몇개의 구간으로 다시 나누고 각 파일별로 한개의 조각만 주메모리에 올려서 이들을
// 병합 정렬로 정렬한다.
// 2-way 방식으로 구현하였다.
template<typename It,typename Comp>
requires std::random_access_iterator<It>
// 안정적으로 정렬하기 위해서는 less_equal , greater_equal 을 사용해야 한다.
void merge(It begin,It end,Comp comp=pred::less_equal<>())
{
    int size=std::distance(begin,end);
    if(size<2) return;
    It pivot=std::next(begin,size/2);
    merge(begin,pivot,comp);
    merge(pivot,end,comp);
    std::vector<std::iter_value_t<It> > tmp(size);
    It left=begin,right=pivot,now=tmp.begin();
    // 정렬되어 있는 2개의 구간을 하나의 구간으로 합쳐준다.
    while(left<pivot||right<end)
    {
        if(left==pivot) copy_forword(right,now);
        else if(right==end) copy_forword(left,now);
        else if(comp(*left,*right)) copy_forword(left,now);
        else copy_forword(right,now);
    }
    now=tmp.begin();
    // 정렬된 새로운 배열을 원래 배열에 복사한다.
    while(begin!=end) copy_forword(now,begin);
}
template<typename It>
requires std::random_access_iterator<It>
void merge(It begin,It end)
{
    merge(begin,end,pred::less<std::iter_value_t<It> >());
}

#endif