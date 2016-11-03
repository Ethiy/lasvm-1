#ifdef INSTANCE_H
#define INSTANCE_H

#include <iostream>
#include <map>
#include <utility>
#include <algorithm>

namespace lasvm
{
    /*!
    * Instance<REAL> class
    */
    template <typename REAL>
    class Instance
    {
    public:
        Instance( void);
        Instance( std::istream &);
        Instance( const Instance<REAL> &);
        Instance( const Instance<REAL> &&);
        ~Instance( void);
        
        Instance& operator=( const Instance<REAL> &);
        Instance& operator+=( const Instance<REAL> &);
        Instance& operator-=( const Instance<REAL> &);
        Instance& operator*=( const Instance<REAL> &);

    private:
        std::map<size_t,REAL> vector;
        size_t length;

        friend std::ostream & operator<<( std::ostream &, const Instance<REAL> &);
    };

    template<REAL>
    inline Instance<REAL>::Instance( void):length(0) {}
    template<REAL>
    inline Instance<REAL>::Instance( const Instance<REAL> &X): length(X.length), vector(X.vector){}
    template<REAL>
    inline Instance<REAL>::Instance( const Instance<REAL> &&X ) noexcept : length( std::move(X.length)), vector( std::move(X.vector)) {}
    template<REAL>
    inline Instance<REAL>::~Instance( void){}
    
    template<REAL>
    inline Instance<REAL> & operator=( const Instance<REAL> & X)
    {
        std::swap( length, X.length);
        std::swap( vector, X.vector);
        return *this;
    }

    template<REAL>
    inline Instance<REAL> operator+=( Instance<REAL> lhs, const Instance<REAL> & rhs)
    {
        return lhs;
    }

    template<REAL>
    inline Instance<REAL> operator-=( Instance<REAL> lhs, const Instance<REAL> & rhs)
    {
        return lhs;
    }

    template<REAL>
    inline Instance<REAL> operator*=( Instance<REAL> lhs, const Instance<REAL> & rhs)
    {
        return lhs;
    }

}

#endif // !INSTANCE_H