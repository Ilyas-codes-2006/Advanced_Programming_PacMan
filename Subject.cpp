//
// Created by Youssef on 13/11/2025.
//
#include "Subject.h"
void Subject::attach(Observer *observer) {
    observers.push_back(observer);
}
void Subject::detach(Observer *observer) {
    observers.erase(std::remove(observers.begin(),observers.end(),observer),observers.end());
}
void Subject::notify(const Event& event) {
    for (auto observer: observers) {
        observer->update(event);
    }
}


