//
//  Reservation.cpp
//  seminarul3
//
//  Created by Alexandra Negru on 26/05/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#include "Reservation.hpp"
#include <sstream>
#include <iostream>

Reservation::Reservation() {
    days = 0;
    status = 0;
}

Reservation::Reservation(Kunde _client, Auto _car, int _days) {
    client = _client;
    car = _car;
    days = _days;
    status = 0;
}

Reservation::~Reservation() {

}

Kunde Reservation::getClient() {
    return client;
}

Auto Reservation::getCar() {
    return car;
}

int Reservation::getDays() {
    return days;
}

int Reservation::getStatus() const {
    return status;
}

void Reservation::setClient(Kunde _client) {
    client = _client;
}

void Reservation::setCar(Auto _car) {
    car = _car;
}

void Reservation::setDays(int _days) {
    days = _days;
}

void Reservation::setStatus(int _status) {
    status = _status;
}

bool operator == (const Reservation& r1, const Reservation& r2) {
    return ((r1.client == r2.client) && (r1.car == r2.car) && (r1.days == r2.days));
}
bool operator != (const Reservation& r1, const Reservation& r2) {
    return !(r1 == r2);
}


std::string Reservation::toString() const {
    std::stringstream out;
    out << "Reservierung \n\tKunde: " << client.toString() << "\tAuto: " << car.toString() << "\tDays: " << days << "\n\n\tStatus: " << status << std::endl << std::endl;
    return out.str();
}
