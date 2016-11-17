#pragma once

#include <iostream>

#include <map>

#include <utility>
#include <numeric>
#include <algorithm>

#include <limits>

#include <cmath>

namespace lasvm
{
    template <typename real_t>
    class Instance
    {
    public:
        Instance( void);
        Instance( std::istream &);
        Instance( const Instance<real_t> &);
        Instance( Instance<real_t> && );
        ~Instance( void);

        void swap( const Instance<real_t> & );
        Instance<real_t>& operator=( Instance<real_t> );
        Instance<real_t>& operator=( Instance<real_t> && );

        real_t& operator[](size_t );

        Instance& operator+=( const Instance<real_t> &);
        Instance& operator-=( const Instance<real_t> &);

        typedef std::map<size_t, real_t>::iterator iterator;
        typedef std::map<size_t, real_t>::const_iterator const_interator;
        iterator begin( void);
        iterator end( void);

    private:
        std::map<size_t,real_t> vector;
        size_t length;

        friend std::ostream & operator<<( std::ostream &, const Instance<real_t> &);
        friend libsvm_ostream & operator<<( libsvm_ostream &, const Instance<real_t> &);
        friend csv_ostream & operator<<( csv_ostream &, const Instance<real_t> &);
        friend binary_ostream & operator<<( binary_ostream &, const Instance<real_t> &);
    };

    template<typename real_t> void swap( Instance<real_t>, Instance<real_t>);
    template<typename real_t> Instance<real_t> operator+( Instance<real_t>, const Instance<real_t>);
    template<typename real_t> Instance<real_t> operator-( Instance<real_t>, const Instance<real_t>);
    template<typename real_t> real_t operator*( Instance<real_t>, Instance<real_t>);
    template<typename real_t> bool operator==( Instance<real_t>, Instance<real_t>);
    template<typename real_t> bool operator!=( Instance<real_t>, Instance<real_t>);

}
