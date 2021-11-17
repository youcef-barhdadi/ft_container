

template<
    class T1,
    class T2
> struct pair
{
    public:
        T1 first;
        T2 second;

    pair& operator=( const pair<U1,U2>& other )
    {
        this->first = other.first;
        this->second = other.second;
    }

    bool operator ==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )   
    {
            return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

    // template< class T1, class T2 >
    bool operator!=( constpair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return !(lhs == rhs);
    }


    bool operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
    {
        return  lhs.first < rhs.first;
    }

    bool operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
    {
        return  lhs.first <= rhs.first;
    }

        bool operator>( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
    {
        return  lhs.first > rhs.first;
    }

    bool operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
    {
        return  lhs.first >= rhs.first;
    }

    pair()
    {

    }

    pair( const T1& x, const T2& y )
    {
        this->first = x;
        this->second = y;
    }

    pair( const pair<U1, U2>& p )
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