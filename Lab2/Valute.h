
#ifndef LAB2_VALUTE_H
#define LAB2_VALUTE_H

#include<map>
#include<set>
#include "json-develop/single_include//nlohmann/json.hpp"

class Valute
{
public:
    Valute(){}

    void add(nlohmann::json data)
    {
        for (auto it = data["Valute"].begin(); it != data["Valute"].end(); it++)
        {
            values[it.key()] = data["Valute"][it.key()]["Value"];
            save_values[it.key()].insert(values[it.key()]);
        }
    }

    float get_value(std::string valute)
    {
        return values[valute];
    }

    float get_average(std::string valute)
    {
        float sum = 0;
        for (auto it = save_values[valute].begin(); it != save_values[valute].end(); it++)
        {
            sum = sum + *it;
        }
        return sum / save_values[valute].size();
    }

    float get_mid(std::string valute)
    {
        int mid = save_values[valute].size() / 2, pos = 1;
        auto it = save_values[valute].begin();
        if (mid == 0)
            return *it;
        while (true)
        {
            if (pos == mid)
                return *it;
            pos++;
            it++;
        }
    }

private:
    std::map<std::string, float> values;
    std::map<std::string, std::multiset<float>> save_values;
};

#endif
