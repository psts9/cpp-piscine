#ifndef ARRAY_H
# define ARRAY_H

template<typename T>
class Array
{
public:
    Array<T>(void) : elems_(nullptr), size_(0)
    {
        return;
    }

    Array<T>(unsigned int n) : size_(n)
    {
        elems_ = new T [size_];
    }

    Array<T>(Array<T> const& arr)
    {
        *this = arr;
    }

    ~Array<T>(void)
    {
        delete [] elems_;
    }

    T& operator[](int index)
    {
        if (index >= size_ || index < 0)
            throw (std::out_of_range("array subscript out of range"));

        return (elems_[index]);
    }

    Array<T>& operator=(Array<T>& arr)
    {
        delete [] elems_;

        elems_ = new T [arr.size()];

        size_ = arr.size();

        for (int i = 0; i < arr.size(); ++i)
            elems_[i] = arr[i];
        
        return (*this);
    }

    int    size(void) const
    {
        return (size_);
    }

private:

    T*  elems_;
    int size_;
};

#endif
