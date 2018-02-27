//
// Created by subigya on 2/27/18.
//

#ifndef HTTPREQUEST_DETECTEDCUSTOMER_H
#define HTTPREQUEST_DETECTEDCUSTOMER_H

#include <string>
#include <ctype.h>

class DetectedCustomer {
    long customerId;
    bool gender;
    bool age;
    bool emotion;
    bool detectionStatusNotified;

public:
    DetectedCustomer(long id);
    DetectedCustomer(long id, bool gender, bool age, bool emotion);

    void setGender(bool gender);
    void setAge(bool age);
    void setEmotion(bool emotion);
    void setNotificationStatus(bool notification);
    bool isGaeSet();
    bool isNotified();
};


#endif //HTTPREQUEST_DETECTEDCUSTOMER_H
