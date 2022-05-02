
#ifndef LAB3_ALGORITHMS_H
#define LAB3_ALGORITHMS_H

template<class iterator, class predicate>
bool All_of(iterator first, iterator last, predicate pred)
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
bool Any_of(iterator first, iterator last, predicate pred)
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
bool None_of(iterator first, iterator last, predicate pred)
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
bool One_of(iterator first, iterator last, predicate pred)
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
bool is_Sorted(iterator first, iterator last, sort_cmp cmp)
{
    if (first == last)
        return true;
    iterator next = first;
    while (++next != last)
    {
        if (!cmp(*first, *next))
        {
            return false;
        }
        ++first;
    }
    return true;
}

template<class iterator, class predicate>
bool is_Partioned(iterator first, iterator last, predicate pred)
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
iterator Find_not(iterator first, iterator last, T value)
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
iterator Find_backward(iterator first, iterator last, T value)
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
bool is_Palindrome(iterator first, iterator last, predicate pred)
{
    iterator next = last;
    --next;
    while (next != first && next > first)
    {
        if (!pred(*first, *next))
            return false;
        ++first;
        --next;
    }
    return true;
}


#endif
