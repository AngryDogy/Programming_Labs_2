
#ifndef LAB3_CIRCULAR_BUFFER_H
#define LAB3_CIRCULAR_BUFFER_H

template<typename T>
class circular_buffer
{
public:
    class iterator : public std::iterator<std::random_access_iterator_tag, T>
    {
        friend class circular_buffer;

    public:
        iterator()
        {}

        iterator(T *it_)
                : it(it_)
        {}

        T &operator*()
        {
            return *it;
        }

        int operator-(iterator other)
        {
            return it - other.it;
        }

        iterator operator+(const int n)
        {
            it = it + n;
            return *this;
        }

        iterator operator-(const int n)
        {
            it = it - n;
            return *this;
        }

        iterator operator+=(const int n)
        {
            it = it + n;
            return *this;
        }

        iterator operator-=(const int n)
        {
            it = it - n;
            return *this;
        }

        iterator operator++()
        {
            ++it;
            return *this;
        }

        iterator operator--()
        {
            --it;
            return *this;
        }

        bool operator!=(circular_buffer<T>::iterator other)
        {
            return it != other.it;
        }

        bool operator==(circular_buffer<T>::iterator other)
        {
            return it == other.it;
        }

        bool operator<(circular_buffer<T>::iterator other)
        {
            return it < other.it;
        }

        bool operator>(circular_buffer<T>::iterator other)
        {
            return it > other.it;
        }

        bool operator<=(circular_buffer<T>::iterator other)
        {
            return it <= other.it;
        }

        bool operator>=(circular_buffer<T>::iterator other)
        {
            return it >= other.it;
        }

        T operator[](const int n)
        {
            return *(it + n);
        }

        friend iterator operator+(const int n, iterator &it_)
        {
            return iterator(it_ + n);
        }

    private:
        T *it;
    };

    circular_buffer()
    {}

    circular_buffer(size_t n)
    {
        Begin = (T *) malloc(sizeof(T) * (n + 1));
        End = Begin;
        Border = Begin + n;
        Capacity = n;
    }

    circular_buffer(const circular_buffer &other)
    {
        Begin = (T *) malloc(sizeof(T) * (other.capacity() + 1));
        T *pointer = Begin;
        End = Begin;
        for (size_t i = 0; i < other.size(); i++)
        {
            *pointer = other[i];
            ++pointer;
            ++End;
        }
        Capacity = other.Capacity;
        Size = other.size();
        Border = Begin + Capacity;
    }

    int size() const
    {
        return Size;
    }

    int capacity() const
    {
        return Capacity;
    }

    void resize(size_t n)
    {
        T *new_begin = (T *) malloc(sizeof(T) * (n + 1));
        T *new_end = new_begin;
        T *pointer = new_begin;
        size_t k = 0;
        for (size_t i = 0; i < this->size(); i++)
        {
            if (k == n)
                break;
            *pointer = (*this)[i];
            ++pointer;
            ++new_end;
            k++;
        }
        free(Begin);
        Begin = new_begin;
        End = new_end;
        Capacity = n;
        Size = k;
        Border = Begin + n;

    }

    void push_back(T value)
    {
        if (End == Border)
        {
            erase_front();
        }
        *End = value;
        End++;
        Size++;
    }

    void push_front(T value)
    {
        if (Size == 0)
        {
            this->push_back(value);
            return;
        }
        T *pointer = End;
        while (pointer != Begin)
        {
            T *value = pointer;
            --value;
            *pointer = *value;
            --pointer;
        }
        *pointer = value;
        if (End != Border)
        {
            End++;
            Size++;
        }

    }

    void erase_back()
    {
        if (Begin != End)
        {
            --End;
            Size--;
        }
    }

    void erase_front()
    {
        if (Begin == End)
            return;
        T *pointer = Begin;
        T *end = End;
        --end;
        while (pointer != end)
        {
            T *value = pointer;
            ++value;
            *pointer = *value;
            ++pointer;
        }
        End--;
        Size--;
    }

    T front() const
    {
        return *Begin;
    }

    T back() const
    {
        T *pointer = End;
        --pointer;
        return *pointer;
    }

    void print() const
    {
        for (size_t i = 0; i < this->size(); i++)
        {
            std::cout << (*this)[i] << ' ';
        }
        std::cout << std::endl;
    }

    ~circular_buffer()
    {
        free(Begin);
    }

    circular_buffer &operator=(const circular_buffer &buffer) = delete;

    T operator[](size_t n) const
    {
        T *pointer = Begin;
        pointer = pointer + n;
        return *pointer;
    }

    iterator begin() const
    {
        return iterator(Begin);
    }

    iterator end() const
    {
        return iterator(End);
    }

private:
    size_t Size = 0;
    size_t Capacity = 0;
    T *Begin;
    T *End;
    T *Border;
};

#endif
