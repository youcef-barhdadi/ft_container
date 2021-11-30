
#pragma once
#include <iostream>
template<
    class T1,
    class T2
> struct pair
{
    public:
        T1 first;
        T2 second;

    pair& operator=( const pair& other )
    {
        this->first = other.first;
        this->second = other.second;
        return (*this);
    }

    bool operator ==( const pair& lhs )   
    {
        return !(this->first != lhs.first);
    }

    // template< class T1, class T2 >
    bool operator!=( const pair& lhs)
    {
        return !(this->first != lhs.first);
    }


    bool operator<( const pair& lhs)
    {
        return  this->first < lhs.first;
    }

    bool operator<=( const pair& lhs )
    {
        return  this->first <= lhs.first;
    }

        bool operator>( const pair& lhs)
    {
        return  this->first > lhs.first;
    }

    bool operator>=( const pair& lhs)
    {
        return  this->first >= lhs.first;
    }

    pair()
    {

    }

    pair( const T1& x, const T2& y )
    {
        this->first = x;
        this->second = y;
    }

    pair( const pair& p )
    {
        *this = p;
    }
};

template< class T1, class T2 >
pair<T1,T2> make_pair( T1 t, T2 u )
{
    pair<T1, T2> p;
    p.first = t;
    p.second = u;
    return p;
}
template< class T1, class T2 >
std::ostream& operator<<(std::ostream& os, const pair<T1,T2>& dt)
{
    os <<  "==>" << dt.first << std::endl;
    return os;
}