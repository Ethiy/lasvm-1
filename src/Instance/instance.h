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

        void swap( const Instance<REAL> & X) throw()
        {
            std::swap( length, X.length);
            std::swap( vector, X.vector);
        }
        
        Instance& operator=( const Instance<REAL> &)
        {
            X.swap(*this);
            return *this;
        }
        REAL& operator[](size_t index) {return vector[index];}
        REAL& 

        Instance& operator+=( const Instance<REAL> &)
        {
            length = std::max( length, X.length);
            std::transform( std::begin(X.vector), std::(X.vector), std::begin(vector), [ &vector, X.vector](std::pair<size_t,REAL> p)
                                                                                        {
                                                                                            //-----------------------------------------------------
                                                                                            return p;
                                                                                        }
                          );
            return *this;
        }
        Instance& operator-=( const Instance<REAL> &);//-----------------------------------------------------------------------------------
        Instance& operator*=( const Instance<REAL> &);//-----------------------------------------------------------------------------------

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
    inline void swap( Instance<REAL>& X, Instance<REAL>& Y) { X.swap(Y);}

    template<REAL>
    inline Instance<REAL> operator+( Instance<REAL> lhs, const Instance<REAL> & rhs)
    {
        lhs += rhs;
        return lhs;
    }

    template<REAL>
    inline Instance<REAL> operator-( Instance<REAL> lhs, const Instance<REAL> & rhs)
    {
        lhs -= rhs;
        return lhs;
    }

    template<REAL>
    inline Instance<REAL> operator*( Instance<REAL> lhs, const Instance<REAL> & rhs)
    {
        lhs *= rhs;
        return lhs;
    }

    template<REAL>
    inline bool operator==( Instance<REAL> lhs, const Instance<REAL> & rhs)
    {
        //------------------------------------------------------------------------------------------------
        return false;
    }

    template<REAL>
    inline bool operator!=( Instance<REAL>lhs, const Instance<REAL> & rhs) {return !operator==(lhs,rhs);}
}

#endif // !INSTANCE_H