#include <iostream>
#include <curl/curl.h>
#include "CurlRequest.h"
#include "DetectedCustomer.cpp"
#include <future>
#include <vector>
#include <map>

using namespace std;

//const string BASEURL = "http://192.41.170.231:5000/";
const string BASEURL = "http://sjpGT683R.desktops.cs.ait.ac.th:5000/";
const string STARTURL = BASEURL;
//const string STARTURL = BASEURL + "start-recommendation";


// will get method not allowed if we send GET request
// when server accepts POST and vice versa
int main() {

    curl_global_init(CURL_GLOBAL_ALL);
    std::map<long, DetectedCustomer*> mapOfCustomers;
    // Posting data
    string postdata = "name=Subigya&comment=test";
    DetectedCustomer *detectedCustomer1 = new DetectedCustomer(1);
    detectedCustomer1->setAge("10 rs");
    detectedCustomer1->setGender("Male");
    detectedCustomer1->setEmotion("Positive");
    mapOfCustomers[1] = detectedCustomer1;

    DetectedCustomer * d2 = new DetectedCustomer(2, "Female", "20 years", "Happy");
    mapOfCustomers[2] = d2;
    cout << "Size of map: "<< mapOfCustomers.size() << endl;
    cout<< detectedCustomer1->isAllSet() << endl;
    auto f = async(launch::async, curl_post, STARTURL, postdata);
    cout<< "sleep started"<<endl;
    cout<< "pre join"<<endl;
    f = async(launch::async, curl_post, STARTURL, "mypostdata");
    cout<<"joined"<<endl;
    curl_global_cleanup();
//    curl_easy_setopt(curl, CURLOPT_URL, "http://sjpGT683R.desktops.cs.ait.ac.th:5000/");
//    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writecallback);
    return 0;
}