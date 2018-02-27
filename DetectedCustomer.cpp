//
// Created by subigya on 2/27/18.
//

#include "DetectedCustomer.h"

DetectedCustomer::DetectedCustomer(long id){
    customerId = id;
}
DetectedCustomer::DetectedCustomer(long id, std::string gender, std::string age, std::string emotion){
    customerId = id;
    this->gender = gender;
    this->age = age;
    this->emotion = emotion;
}

void DetectedCustomer::setGender(std::string gender){
    this->gender = gender;
}

void DetectedCustomer::setAge(std::string age){
    this->age = age;
}

void DetectedCustomer::setEmotion(std::string emotion){
    this->emotion = emotion;
}

bool DetectedCustomer::isAllSet(){
//    std::cout<< (customerId > 0) << !gender.empty() << !age.empty() << !emotion.empty() << std::endl;
    if( (customerId > 0) && !gender.empty() && !age.empty() && !emotion.empty() ){
        return true;
    }
    return false;
}