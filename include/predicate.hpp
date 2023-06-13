// Author : AT_Doh
// E-Mail : at.doh.dev@gmail.com
// Created : 2023.06.12
// Sorting 알고리즘에서 사용하기 위한 비교함수로 조건자(Predicate)를 Struct 형태로 구현함.
#ifndef __PREDICATE_HPP__
#define __PREDICATE_HPP__
namespace pred
{

template<typename T>
struct less
{
    constexpr bool operator()(T const&a,T const&b)
    {
        return a<b;
    }
};
template<typename T>
struct less_equal
{
    constexpr bool operator()(T const&a,T const&b)
    {
        return a<=b;
    }
};
template<typename T>
struct greater
{
    constexpr bool operator()(T const&a,T const&b)
    {
        return a>b;
    }
};
template<typename T>
struct greater_equal
{
    constexpr bool operator()(T const&a,T const&b)
    {
        return a>=b;
    }
};

template<typename T,typename Comp>
struct comparison_type
{
    using type=pred::less<T>;
};
template<typename T>
struct comparison_type<T,pred::less_equal<T> >
{
    using type=pred::less_equal<T>;
};
template<typename T>
struct comparison_type<T,pred::greater<T> >
{
    using type=pred::greater<T>;
};
template<typename T>
struct comparison_type<T,pred::greater_equal<T> >
{
    using type=pred::greater_equal<T>;
};

}
#endif