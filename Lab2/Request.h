
#ifndef LAB2_REQUEST_H
#define LAB2_REQUEST_H

#include "curl-7.82.0/include/curl/curl.h"

class Request
{
public:
    Request(){}

    Request(size_t (*f)(char *ptr, size_t size, size_t nmemb, std::string *data), std::string *data)
    {
        curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.cbr-xml-daily.ru/daily_json.js");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, f);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, data);
    }

    Request(Request const &) = delete;

    Request &operator=(Request const &) = delete;

    bool get_data() const
    {
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            return false;
        else
            return true;
    }

    ~Request()
    {
        curl_easy_cleanup(curl);
    }

private:
    CURL *curl;
};

#endif
