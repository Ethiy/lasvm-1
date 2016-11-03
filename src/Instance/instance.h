#ifdef INSTANCE_H
#define INSTANCE_H

#include <iostream>
#include <map>

namespace lasvm
{
    /*!
    * Instance class
    */
    template <typename REAL>
    class Instance
    {
    public:
        Instance( void);
        Instance( std::istream&);
        ~Instance( void);

        friend Instance operator+(const left_instance &, const right_instance &);
        friend Instance operator-(const left_instance &, const right_instance &);
        friend Instance operator*(const left_instance &, const right_instance &);

        size_t zero_norm();
        REAL absolute_value_norm();
        REAL euclidian_norm();
        REAL uniform_norm();

    private:
        std::map<size_t> vector;
        size_t size;

        friend std::ostream & operator<<( std::ostream &, const Instance &);
    }

    inline Instance::Instance( void):size(0) {}
    inline Instance::~Instance( void){}

}

#endif // !INSTANCE_H