//
// Created by subigya on 2/27/18.
//

#include "DetectedCustomer.h"
#include <map>

DetectedCustomer::DetectedCustomer(long id){
    customerId = id;
    this->gender = false;
    this->age = false;
    this->emotion = false;
    this->detectionStatusNotified = false;
}
DetectedCustomer::DetectedCustomer(long id, bool gender, bool age, bool emotion){
    customerId = id;
    this->gender = gender;
    this->age = age;
    this->emotion = emotion;
    this->detectionStatusNotified = false;
}

void DetectedCustomer::setGender(bool gender){
    this->gender = gender;
}

void DetectedCustomer::setAge(bool age){
    this->age = age;
}

void DetectedCustomer::setEmotion(bool emotion){
    this->emotion = emotion;
}

void DetectedCustomer::setNotificationStatus(bool notification) {
    this->detectionStatusNotified = notification;
}

bool DetectedCustomer::isGaeSet(){
//    std::cout<< (customerId > 0) << !gender.empty() << !age.empty() << !emotion.empty() << std::endl;
    if( (customerId > 0) && gender && age && emotion ){
        return true;
    }
    return false;
}

bool DetectedCustomer::isNotified() {
    return this->detectionStatusNotified;
}

bool customerExists(std::map<int, DetectedCustomer*> custMap, int key){
//    if(custMap.find(key) != custMap.end()){
//        return true;
//    }
    return custMap.find(key) != custMap.end();
}