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
        Instance(void);
        Instance(std::size_t _size, real_t* _vector);
        Instance(std::map<size_t, real_t> sparse_vector);
        ~Instance(void);

        template<typename real_t>
        void swap(Instance<real_t> & other);
    private:
        std::size_t size;
        std::unique_ptr<real_t> vector;
    };
}
