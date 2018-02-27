//
// Created by subigya on 2/27/18.
//

#ifndef HTTPREQUEST_CURLREQUEST_H
#define HTTPREQUEST_CURLREQUEST_H

#include <curl/curl.h>
#include <iostream>

//using namespace std;

static size_t data_write(void* buf, size_t size, size_t nmemb, void* userp);
CURLcode curl_read(const std::string& url, std::ostream& os, long timeout);
CURLcode curl_post(const std::string& url, std::string postdata);

#endif //HTTPREQUEST_CURLREQUEST_H
