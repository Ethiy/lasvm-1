#include "instance.h"


namespace lasvm
{
    // ------------ Constructors: void, std::string, copy and move --------------------------------------
    template<real_t> Instance<real_t>::Instance( void):length(0) {}
    template<real_t> Instance<real_t>::Instance( const Instance<real_t> &other): 
                                                            length(other.length), vector(other.vector){}
    template<real_t> Instance<real_t>::Instance( const Instance<real_t> &&other ) noexcept :
                                        length( std::move(other.length)), vector( std::move(other.vector)) {}
    template<real_t> Instance<real_t>::~Instance( void){}


    // ------------------- Copy-Swap implementation ----------------------------------------------------
    void Instance<real_t>::swap( const Instance<real_t> & other) throw()
    {
        std::swap( length, other.length);
        std::swap( vector, other.vector);
    }

    Instance<real_t>& Instance<real_t>::operator=( Instance<real_t> other)
    {
        other.swap(*this);
        return *this;
    }
    template<real_t> void swap( Instance<real_t>& X, Instance<real_t>& Y)
    {
        using std::swap;
        X.swap(Y);
    }

    //------------------------ Operators: [], +=, -=, *= ------------------------------------------------
    real_t& operator[](size_t index)
    {
        
        if()
            return ;
        else
            return 0;
    }
    Instance<real_t>& Instance<real_t>::operator+=( const Instance<real_t> & other);
    {
        length = std::max( length, other.length);
        std::for_each( std::begin(other.vector), std::(other.vector), [ &vector](std::pair<size_t,real_t> p)
                                                                        {
                                                                            //-----------------------------------------------------
                                                                        }
                      );
        return *this;
    }
    Instance<real_t>& Instance<real_t>::operator-=( const Instance<real_t> &)
    {
        return *this;
    }
    Instance<real_t>& Instance<real_t>::operator*=( const Instance<real_t> &)
    {
        return *this;
    }


    //--------------------------- Operators: +, -, * ----------------------------------------------------
    template<real_t> Instance<real_t> operator+( Instance<real_t> lhs, const Instance<real_t> & rhs)
    {
        lhs += rhs;
        return lhs;
    }

    template<real_t> Instance<real_t> operator-( Instance<real_t> lhs, const Instance<real_t> & rhs)
    {
        lhs -= rhs;
        return lhs;
    }

    template<real_t> Instance<real_t> operator*( Instance<real_t> lhs, const Instance<real_t> & rhs)
    {
        lhs *= rhs;
        return lhs;
    }

    template<real_t> bool operator==( Instance<real_t> lhs, const Instance<real_t> & rhs)
    {
        //------------------------------------------------------------------------------------------------
        return false;
    }

    template<real_t> bool operator!=( Instance<real_t>lhs, const Instance<real_t> & rhs)
    {
        return !operator==(lhs,rhs);
    }

    std::ostream & Instance<real_t>::operator<<( std::ostream &, const Instance<real_t> &)
    {

    }

}
