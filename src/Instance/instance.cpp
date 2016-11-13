#include "instance.h"


namespace lasvm
{
    // ------------ Constructors: void, std::string, copy and move --------------------------------------
    template<typename real_t> Instance<real_t>::Instance( void):length(0) {}
    template<typename real_t> Instance<real_t>::Instance( const Instance<real_t> &other): 
                                                        length(other.length), vector(other.vector){}
    template<typename real_t> Instance<real_t>::Instance( Instance<real_t> && other ) noexcept
    {
        length = std::move( other.length);
        vector = std::move( other.vector);
    }
    template<typename real_t> Instance<real_t>::~Instance( void){}


    // ------------------- Copy-Swap implementation ----------------------------------------------------
    template<typename real_t>
    void Instance<real_t>::swap( const Instance<real_t> & other) throw()
    {
        std::swap( length, other.length);
        std::swap( vector, other.vector);
    }

    template<typename real_t>
    Instance<real_t>& Instance<real_t>::operator=( Instance<real_t> other)
    {
        other.swap(*this);
        return *this;
    }
    template<typename real_t>
    void swap( Instance<real_t>& lhs, Instance<real_t>& rhs)
    {
        using std::swap;
        lhs.swap(rhs);
    }

    template<typename real_t>
    Instance<real_t>& Instance<real_t>::operator=( Instance<real_t> && other) noexcept
    {
        length = std::exchange( other.length, 0);
        vector = std::exchange( other.vector, std::map<size_t, real_t>());
        return *this;
    }

    //------------------------ Operators: [], +=, -=, *= ------------------------------------------------
    template<typename real_t> 
    real_t& Instance<real_t>::operator[](size_t index)
    {
        auto it = vector.find(index);
        if(it != vector.end())
            return vector[index];
        else
            return 0;
    }
    template<typename real_t>
    Instance<real_t>& Instance<real_t>::operator+=( const Instance<real_t> & other)
    {
        length = std::max( length, other.length);
        std::for_each( std::begin(other.vector), std::end(other.vector), [&vector](std::pair<size_t,real_t> p)
                                                                            {
                                                                                auto iterator = vector.find( p.first);
                                                                                if( iterator != m.end())
                                                                                    vector[p.first] += p.second;
                                                                                else
                                                                                    vector[p.first] = p.second;
                                                                            }
                                                                        );
        return *this;
    }
    template<typename real_t>
    Instance<real_t>& Instance<real_t>::operator-=( const Instance<real_t> &)
    {
        length = std::max( length, other.length);
        std::for_each( std::begin(other.vector), std::end(other.vector), [&vector](std::pair<size_t,real_t> p)
                                                                            {
                                                                                auto iterator = vector.find( p.first);
                                                                                if( iterator != m.end())
                                                                                    vector[p.first] -= p.second;
                                                                                else
                                                                                    vector[p.first] = 0 - p.second;
                                                                            }
                                                                        );
        return *this;
    }

    //--------------------------- Operators: +, -, * ----------------------------------------------------
    template<typename real_t> 
    Instance<real_t> operator+( Instance<real_t> lhs, Instance<real_t> rhs)
    {
        lhs += rhs;
        return lhs;
    }

    template<typename real_t> 
    Instance<real_t> operator-( Instance<real_t> lhs, Instance<real_t> rhs)
    {
        lhs -= rhs;
        return lhs;
    }

    template<typename real_t>
    real_t operator*( Instance<real_t> lhs, Instance<real_t> rhs)
    {
        std::vector<real_t> mapped;
        std::transform( std::begin(lhs.vector), std::end(lhs.vector), std::begin(mapped),
                        [&lhs.vector,rhs.vector](std::pair<size_t,real_t> p)
                            {
                                auto iterator = (rhs.vector).find( p.first);
                                if( iterator != m.end())
                                    return lhs.vector[p.first] * iterator->second;
                                else
                                    return .0;
                            }
                    );
        return std::accumulate( std::begin(mapped), std::end(mapped), .0);
    }

    template<typename real_t>
    Instance<real_t> operator*( real_t scalar,const Instance<real_t> & instance)
    {
        std::map<size_t,real_t> result;
        if(scalar)
            std::for_each(std::begin(instance.vector), std::end(instance.vector),
                            [scalar,&result](std::pair<size_t,real_t> p)
                            {
                                result[p.first] *= scalar;
                            } 
                        );
        return ;
    }

    //--------------------------- Operators: ==, != ----------------------------------------------------
    template<typename real_t>
    bool operator==( Instance<real_t> lhs, const Instance<real_t> & rhs)
    {
        return std::all_of(std::begin( rhs.vector), std::end( rhs.vector), 
                            [=](std::pair<size_t,real_t> p)
                            {
                                auto iterator = (lhs.vector).find(p.first);
                                if(iterator != end)
                                    return std::abs( lhs.vector[p.first] - rhs[p.first]) < std::numeric_limits<real_t>::epsilon();
                                else
                                    return std::abs( rhs.vector[p.first]) < std::numeric_limits<real_t>::epsilon();
                            }
                        );
    }

    template<typename real_t>
    bool operator!=( Instance<real_t>lhs, const Instance<real_t> & rhs)
    {
        return !operator==(lhs,rhs);
    }

    //----------------------------- Operators: << --------------------------------------------------------
    template<typename real_t>
    std::ostream & operator<<( std::ostream & os, const Instance<real_t> & instance)
    {
        os << <<;
        return os;
    }

}
