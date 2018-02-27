//
// Created by subigya on 2/27/18.
//

#include "CurlRequest.h"

using namespace std;

static size_t data_write(void* buf, size_t size, size_t nmemb, void* userp)
{
    if(userp)
    {
        std::ostream& os = *static_cast<std::ostream*>(userp);
        std::streamsize len = size * nmemb;
        if(os.write(static_cast<char*>(buf), len))
            return len;
    }

    return 0;
}

/**
* timeout is in seconds
**/
CURLcode curl_read(const std::string& url, std::ostream& os, long timeout = 30)
{
    CURLcode code(CURLE_FAILED_INIT);
    CURL* curl = curl_easy_init();

    if(curl)
    {
        if(CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &data_write))
           && CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L))
           && CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L))
           && CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_FILE, &os))
           && CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout))
           && CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_URL, url.c_str())))
        {
            code = curl_easy_perform(curl);
        }
        curl_easy_cleanup(curl);
    }
    return code;
}

CURLcode curl_post(const std::string& url, std::string postdata)
{
    CURL *curl;
    curl = curl_easy_init();
    CURLcode res(CURLE_FAILED_INIT); // start by fail.


    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
//        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postdata.c_str()); //"name=Bjarne&comment=example"
        res = curl_easy_perform(curl);

        if (res == CURLE_OK){
            cout << "Posted: "<<postdata<<endl;
        }
        else {
            cout<<"Post to server Failed, Response Code: "<<res<<endl;
            cout<< curl_easy_strerror(res)<< endl;
        }

        curl_easy_cleanup(curl);
    }
    return res;
}