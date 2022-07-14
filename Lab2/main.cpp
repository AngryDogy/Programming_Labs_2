#include<iostream>
#include<ctime>
#include<conio.h>
#include "curl-7.82.0/include/curl/curl.h"
#include "json-develop/single_include//nlohmann/json.hpp"
#include "Valute.h"
#include "Request.h"

size_t write_data(char *ptr, size_t size, size_t nmemb, std::string *data)
{
    if (data)
    {
        data->append(ptr, size * nmemb);
        return size * nmemb;
    }
    else
        return 0;
}

int main()
{
    std::string data, names[35];
    size_t(*f)(char * ptr, size_t
    size, size_t
    nmemb, std::string * data) = write_data;
    Request request(f, &data);
    Valute valutes;
    nlohmann::json json_data;
    while (!kbhit())
    {
        request.get_data();
        json_data = nlohmann::json::parse(data);
        valutes.add(json_data);
        data.clear();
        for (auto it = json_data["Valute"].begin(); it != json_data["Valute"].end(); it++)
        {
            std::cout << it.key() << " : " << valutes.get_value(it.key()) << '\n';
        }
        Sleep(10000);
    }
    for (auto it = json_data["Valute"].begin(); it != json_data["Valute"].end(); it++)
    {
        std::cout << it.key() << " " << "Average : " << valutes.get_average(it.key()) << " Mid: " << valutes.get_mid(it.key()) << '\n';
    }
    return 0;
}