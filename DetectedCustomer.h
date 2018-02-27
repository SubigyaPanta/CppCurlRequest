//
// Created by subigya on 2/27/18.
//

#ifndef HTTPREQUEST_DETECTEDCUSTOMER_H
#define HTTPREQUEST_DETECTEDCUSTOMER_H

#include <string>
#include <ctype.h>

class DetectedCustomer {
    long customerId;
    std::string gender;
    std::string age;
    std::string emotion;

public:
    DetectedCustomer(long id);
    DetectedCustomer(long id, std::string gender, std::string age, std::string emotion);

    void setGender(std::string gender);
    void setAge(std::string age);
    void setEmotion(std::string emotion);
    bool isAllSet();
};


#endif //HTTPREQUEST_DETECTEDCUSTOMER_H
