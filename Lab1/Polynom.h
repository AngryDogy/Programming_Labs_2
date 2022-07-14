
#ifndef LAB1_POLYNOM_H
#define LAB1_POLYNOM_H

class Polynom
{
public:
    Polynom()
    {}

    Polynom(std::vector<double> coefficients)
    {
        coefficients_.resize(coefficients.size());
        for (int i = 0; i < coefficients.size(); i++)
        {
            coefficients_[i] = coefficients[i];
        }
    }

    Polynom(const Polynom &other)
    {
        coefficients_.resize(other.coefficients_.size());
        for (int i = 0; i < other.coefficients_.size(); i++)
        {
            coefficients_[i] = other.coefficients_[i];
        }
    }

    ~Polynom()
    {}

    Polynom &operator=(const Polynom &other)
    {
        if (&other == this)
            return *this;
        coefficients_.resize(other.coefficients_.size());
        for (int i = 0; i < other.coefficients_.size(); i++)
        {
            coefficients_[i] = other.coefficients_[i];
        }
    }

    bool operator==(const Polynom &other)
    {
        if (coefficients_.size() != other.coefficients_.size())
        {
            return false;
        }
        else
        {
            for (int i = 0; i < other.coefficients_.size(); i++)
            {
                if (coefficients_[i] != other.coefficients_[i])
                {
                    return false;
                }
            }
            return true;
        }
    }

    bool operator!=(const Polynom &other)
    {
        if (*this == other)
            return false;
        return true;
    }

    Polynom operator+(const Polynom &other)
    {
        int n = std::max(coefficients_.size(), other.coefficients_.size());
        std::vector<double> values;
        values.resize(n);
        double val1, val2;
        for (int i = 0; i < n; i++)
        {
            if (i < coefficients_.size())
            {
                val1 = coefficients_[i];
            }
            else
            {
                val1 = 0;
            }
            if (i < other.coefficients_.size())
            {
                val2 = other.coefficients_[i];
            }
            else
            {
                val2 = 0;
            }
            values[i] = val1 + val2;
        }
        return Polynom(values);
    }

    Polynom operator-(const Polynom &other)
    {
        int n = std::min(coefficients_.size(), other.coefficients_.size());
        std::vector<double> values;
        values.resize(n);
        double val1, val2;
        for (int i = 0; i < n; i++)
        {
            if (i < coefficients_.size())
            {
                val1 = coefficients_[i];
            }
            else
            {
                val1 = 0;
            }
            if (i < other.coefficients_.size())
            {
                val2 = other.coefficients_[i];
            }
            else
            {
                val2 = 0;
            }
            values[i] = val1 - val2;
        }
        return Polynom(values);
    }

    Polynom &operator+=(const Polynom &other)
    {
        int n = std::min(coefficients_.size(), other.coefficients_.size());
        for (int i = 0; i < n; i++)
        {
            coefficients_[i] = coefficients_[i] + other.coefficients_[i];
        }
        return *this;
    }

    Polynom &operator-=(const Polynom &other)
    {
        int n = std::min(coefficients_.size(), other.coefficients_.size());
        for (int i = 0; i < n; i++)
        {
            coefficients_[i] = coefficients_[i] - other.coefficients_[i];
        }
        return *this;
    }

    Polynom operator*(double rhs)
    {
        std::vector<double> values;
        values.resize(coefficients_.size());
        for (int i = 0; i < coefficients_.size(); i++)
        {
            values[i] = coefficients_[i] * rhs;
        }
        return Polynom(values);
    }

    Polynom operator/(double rhs)
    {
        std::vector<double> values;
        values.resize(coefficients_.size());
        for (int i = 0; i < coefficients_.size(); i++)
        {
            values[i] = coefficients_[i] / rhs;
        }
        return Polynom(values);
    }

    Polynom &operator*=(double rhs)
    {
        for (int i = 0; i < coefficients_.size(); i++)
        {
            coefficients_[i] = coefficients_[i] * rhs;
        }
        return *this;
    }

    Polynom &operator/=(double rhs)
    {
        for (int i = 0; i < coefficients_.size(); i++)
        {
            coefficients_[i] = coefficients_[i] / rhs;
        }
        return *this;
    }

    double operator[](int index)
    {
        return coefficients_[index];
    }

    friend std::istream &operator>>(std::istream &stream, Polynom &polynom);

    friend std::ostream &operator<<(std::ostream &out, const Polynom &polynom);

    friend Polynom operator+(Polynom &a, Polynom &b);

    friend Polynom operator-(Polynom &a, Polynom &b);

    friend Polynom operator*(double lhs, Polynom &rhs);

private:
    std::vector<double> coefficients_;
};

Polynom operator*(double lhs, Polynom &rhs)
{
    std::vector<double> values;
    values.resize(rhs.coefficients_.size());
    for (int i = 0; i < rhs.coefficients_.size(); i++)
    {
        values[i] = lhs * rhs.coefficients_[i];
    }
    return Polynom(values);
}

Polynom operator+(Polynom &a, Polynom &b)
{
    int n = std::max(a.coefficients_.size(), b.coefficients_.size());
    std::vector<double> values;
    values.resize(n);
    double val1, val2;
    for (int i = 0; i < n; i++)
    {
        if (i < a.coefficients_.size())
        {
            val1 = a.coefficients_[i];
        }
        else
        {
            val1 = 0;
        }
        if (i < b.coefficients_.size())
        {
            val2 = b.coefficients_[i];
        }
        else
        {
            val2 = 0;
        }
        values[i] = val1 + val2;
    }
    return Polynom(values);
}

Polynom operator-(Polynom &a, Polynom &b)
{
    int n = std::max(a.coefficients_.size(), b.coefficients_.size());
    std::vector<double> values;
    values.resize(n);
    double val1, val2;
    for (int i = 0; i < n; i++)
    {
        if (i < a.coefficients_.size())
        {
            val1 = a.coefficients_[i];
        }
        else
        {
            val1 = 0;
        }
        if (i < b.coefficients_.size())
        {
            val2 = b.coefficients_[i];
        }
        else
        {
            val2 = 0;
        }
        values[i] = val1 - val2;
    }
    return Polynom(values);
}

std::istream &operator>>(std::istream &stream, Polynom &polynom)
{
    int i = 0;
    double val;
    char s = 0;
    std::vector<double> values;
    while (s != '\n')
    {
        if (s == '+' || s == '-' || s == 0)
        {
            std::cin >> val;
            if (s == '-')
                val = -val;
            values.resize(values.size() + 1);
            values[i] = val;
            i++;

        }
        s = getchar();
    }
    polynom = Polynom(values);
    return stream;


}

std::ostream &operator<<(std::ostream &out, const Polynom &polynom)
{

    double val_out;
    for (int i = 0; i < polynom.coefficients_.size(); i++)
    {
        val_out = polynom.coefficients_[i];
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

#endif
