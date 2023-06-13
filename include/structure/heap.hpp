#ifndef __DATA_HEAP_HPP__
#define __DATA_HEAP_HPP__
#include<pch.hpp>
namespace data
{

// 완전이진트리(Complete Binary Tree)의 일종으로, 영단어 Heap 은 '무엇인가를 
// 연달아 쌓아올린 더미' 라는 뜻을 가지고 있는데, 자료구조 Heap 또한 데이터들을
// 특정한 순서대로 쌓아 나간다.
// 힙은 최대 힙(Max Heap), 최소 힙(Min Heap) 두가지로 나눌 수 있는데, 최대 힙의
// 경우 모든 부모노드는 자신보다 작은 값들만 자식노드로 가지고, 최소 힙의 경우 
// 자신보다 큰 노드만 자식 노드로 가지게 된다.
template<
typename T,
typename Allocator=std::vector<T>,
typename Comp=pred::less<typename Allocator::value_type> 
>
// predicate 로 less 를 사용하는 경우 최대힙, greater 를 사용하면 최소힙이 된다.
requires std::random_access_iterator<typename Allocator::iterator>
class heap
{
    using It=typename Allocator::iterator;
    Allocator mNodes;
    Comp mComp;
    // 힙이 아닌 배열을 힙으로 만들기 위해서는 최상위 노드부터 한 레벨씩 내려가면서
    // 부모 노드와 비교를 통해 주어진 부모,자식 조건을 만족시켜 나가야 한다.
    void _heapify(It begin,It end)
    {
        for(It now=begin;now!=end;now=std::next(now))
        {
            It next=now;
            while(next!=end) next=_checkup(begin,end,next);
        }
    }
    // 주어진 노드와 부모 노드의 값에 대해 주어진 Comp 로 비교를 수행하여
    // 부모,자식 노드를 규칙에 맞게 재배치한다.
    It _checkup(It begin,It end,It now)
    {
        if(now==begin) return end;
        int idx=std::distance(begin,now);
        It par=std::next(begin,idx/2+(idx%2?0:-1));
        if(mComp(*par,*now))
        {
            std::iter_swap(par,now);
            return par;
        }
        return end;
    }
    // 주어진 노드와 두 자식 노드의 값에 대해 주어진 Comp 로 비교를 수행하여
    // 부모,자식 노드를 규칙에 맞게 재배치한다.
    It _checkdown(It begin,It end,It now)
    {
        if(now>=end) return end;
        int idx=std::distance(begin,now);
        int size=std::distance(begin,end);
        int child=idx<<1;
        It left,right;
        left=child+1<size?std::next(begin,child+1):end;
        right=left==end?end:std::next(left);
        // left 자식 노드가 없는 경우 현재 노드는 리프 노드이다.
        if(left!=end)
        {
            It tar;
            // right 자식 노드가 없다면 left 자식 노드와 현재 노드를 비교해야 한다.
            if(right==end) tar=left;
            // 두 자식 노드 중 현재 노드와 비교할 노드를 선택해야 한다.
            // 최대힙의 경우 두 자식 중 더 큰 값을 가진 노드가 비교 대상이된다.
            // 이는 만약, 현재 노드와 자식 노드 간에 교환이 일어난다면, 교환된 자식노드와
            // 교환되지 않은 자식노드들간에도 부모,자식 조건을 만족해야 하기 때문이다.
            else tar=mComp(*left,*right)?right:left;
            if(mComp(*now,*tar))
            {
                std::iter_swap(now,tar);
                return tar;
            }
        }
        return end;
    }
public:
    heap() : mComp()
    {
        
    }
    heap(Allocator const&alloc) : mComp()
    {
        mNodes=alloc;
        _heapify(mNodes.begin(),mNodes.end());
    }
    heap(Allocator&&alloc) : mComp()
    {
        mNodes=std::move(alloc);
        _heapify(mNodes.begin(),mNodes.end());
    }
    heap(It begin,It end) : mComp()
    {
        mNodes=Allocator(std::distance(begin,end));
        for(It now=mNodes.begin();begin!=end;++begin,++now) *now=*begin; 
        _heapify(mNodes.begin(),mNodes.end());
    }
    T top() const
    {
        return mNodes.front();
    }
    void push(T val)
    {
        mNodes.push_back(val);
        It now=std::prev(mNodes.end());
        while(now!=mNodes.end()) now=_checkup(mNodes.begin(),mNodes.end(),now);
    }
    void pop()
    {
        mNodes.front()=mNodes.back();
        mNodes.pop_back();
        It now=mNodes.begin();
        while(now!=mNodes.end()) now=_checkdown(mNodes.begin(),mNodes.end(),now);
    }
    bool empty()
    {
        return mNodes.empty();
    }
};

}
#endif