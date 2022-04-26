
#ifndef LAB3_ALGORITHMS_H
#define LAB3_ALGORITHMS_H

template<class iterator, class predicate>
bool all_of(iterator first, iterator last, predicate pred)
{
    while (first != last)
    {
        if (!pred(*first))
            return false;
        ++first;
    }
    return true;
}

template<class iterator, class predicate>
bool any_of(iterator first, iterator last, predicate pred)
{
    while (first != last)
    {
        if (pred(*first))
            return true;
        ++first;
    }
    return false;
}

template<class iterator, class predicate>
bool none_of(iterator first, iterator last, predicate pred)
{
    while (first != last)
    {
        if (pred(*first))
            return false;
        ++first;
    }
    return true;
}

template<class iterator, class predicate>
bool one_of(iterator first, iterator last, predicate pred)
{
    int k = 0;
    while (first != last)
    {
        if (pred(*first))
        {
            k++;
        }
        ++first;
    }
    if (k == 1)
        return true;
    return false;
}

template<class iterator, class sort_cmp>
bool is_sorted(iterator first, iterator last, sort_cmp cmp)
{
    if (first == last)
        return true;
    iterator next = first;
    while (++next != last)
    {
        if (!cmp(next, first))
        {
            return false;
        }
        ++first;
    }
    return true;
}

template<class iterator, class predicate>
bool is_partioned(iterator first, iterator last, predicate pred)
{
    while (first != last && pred(*first))
    {
        ++first;
    }
    while (first != last)
    {
        if (pred(*first))
            return false;
        ++first;
    }
    return true;
}

template<class iterator, typename T>
iterator find_not(iterator first, iterator last, T value)
{
    while (first != last)
    {
        if (*first != value)
            return first;
        ++first;
    }
    return last;
}

template<class iterator, typename T>
iterator find_backward(iterator first, iterator last, T value)
{
    iterator next = last;
    --next;
    while (next != first)
    {
        if (*next == value)
            return next;
        --next;
    }
    if (*next == value)
        return next;
    return last;
}

template<class iterator, class predicate>
bool is_palindrome(iterator first, iterator last, predicate pred)
{
    iterator next = last;
    --next;
    while (next != first)
    {
        if (!pred(*first, *next))
            return false;
        ++first;
        --next;
    }
    return true;
}


#endif
