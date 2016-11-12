#pragma once

#include <iostream>
#include <map>
#include <utility>
#include <algorithm>

namespace lasvm
{
    template <typename real_t>
    class Instance
    {
    public:
        Instance( void);
        Instance( std::istream &);
        Instance( const Instance<real_t> &);
        Instance( const Instance<real_t> &&);
        ~Instance( void);

        void swap( const Instance<real_t> & );
        Instance<real_t>& operator=( Instance<real_t>);

        real_t& operator[](size_t );

        Instance& operator+=( const Instance<real_t> &);
        Instance& operator-=( const Instance<real_t> &);
        Instance& operator*=( const Instance<real_t> &);

    private:
        std::map<size_t,real_t> vector;
        size_t length;

        friend std::ostream & operator<<( std::ostream &, const Instance<real_t> &);
    };
}
