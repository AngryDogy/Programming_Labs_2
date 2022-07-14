
#ifndef TEST_20_POLYNOM_H
#define TEST_20_POLYNOM_H
template<size_t power>
class Polynom
{
public:
    constexpr Polynom() {}
    constexpr Polynom(const int* array, const size_t size)
    {
        add(array, size - 1);
    }
    constexpr int operator[](const size_t position) const
    {
        return coeff[position];
    }
    constexpr int value(const int point) const
    {
        constexpr int point_degree = 1;
        constexpr int position = 0;
        return calculating_value(point, point_degree * point, position + 1) + coeff[0];
    }
    friend std::ostream &operator<<(std::ostream &out, const Polynom &polynom)
    {
        int val_out;
        for (int i = 0; i < power; i++)
        {
            val_out = polynom.coeff[i];
            if (i != 0)
            {
                if (val_out < 0)
                {
                    out << '-' << ' ';
                    val_out = -val_out;
                }
                else
                {
                    out << '+' << ' ';
                }
            }
            out << val_out << ' ' << '*' << ' ' << "x^" << i << ' ';
        }
        return out;
    }
private:
    constexpr void add(const int* array, const size_t position)
    {
        if (position == 0)
        {
            coeff[position] = array[0];
        }
        else
        {
            coeff[position] = array[position];
            add(array, position - 1);
        }
    }
    constexpr int calculating_value(const int point, const int point_degree, const int position) const
     {
         if (position == power - 1)
             return point_degree * coeff[position];
         return calculating_value(point, point * point_degree, position + 1) + point_degree * coeff[position];
     }
    int coeff[power];
};
#endif
