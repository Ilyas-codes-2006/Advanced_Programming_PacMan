//
// Created by Youssef on 13/11/2025.
//
#include "Subject.h"
/**
 * @Functionality Add an observer.
 *
 * @Explanation We push an observer to the vector.
 */
void Subject::attach(Observer *observer) {
    observers.push_back(observer);
}
/**
 * @Functionality Delete an observer.
 *
 * @Explanation We delete an observer from the vector.
 */
void Subject::detach(Observer *observer) {
    observers.erase(std::remove(observers.begin(),observers.end(),observer),observers.end());
}
/**
 * @Functionality We notify what event happened.
 *
 * @Explanation The observer calls the right update based on the event given. This is because we implemented proper polymorphism.
 */
void Subject::notify(const Event& event) {
    for (auto observer: observers) {
        observer->update(event);
    }
}


