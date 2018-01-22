#include <iostream>
#include <sstream>
#include <fstream>
#include <curl/curl.h>

using namespace std;

const string BASEURL = "http://sjpGT683R.desktops.cs.ait.ac.th:5000/";
const string STARTURL = BASEURL + "start-recommendation";

// callback function writes data to a std::ostream
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

CURLcode curl_post(CURL* curl, const std::string& url, string postdata)
{
    curl = curl_easy_init();
    CURLcode res(CURLE_FAILED_INIT); // start by fail.


    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
//        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postdata.c_str()); //"name=Bjarne&comment=example"
        res = curl_easy_perform(curl);

        if (res == CURLE_OK){
            cout << "Posted: "<<postdata;
        }
        else {
            cout<<"Post to server Failed, Response Code: "<<res<<endl;
            cout<< curl_easy_strerror(res)<< endl;
        }

        curl_easy_cleanup(curl);
    }
    return res;
}

// will get method not allowed if we send GET request
// when server accepts POST and vice versa
int main() {
    CURL *curl;
    CURLcode response_code;

    curl_global_init(CURL_GLOBAL_ALL);

    // Posting data
    string postdata = "name=Subigya&comment=test";
    response_code = curl_post(curl, STARTURL, postdata);


    curl_global_cleanup();
//    curl_easy_setopt(curl, CURLOPT_URL, "http://sjpGT683R.desktops.cs.ait.ac.th:5000/");
//    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writecallback);
    return 0;
}