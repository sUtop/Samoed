/*
 file : tmeslist.cpp
    Copyright (c) 2017 Gorban Igor Utop@inbox.ru

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

 */



#include "tmeslist.h"


samoServer::TelemetryMessageList::TelemetryMessageList()
{
     Socket::open(DRIVER_SERVER);
};

int samoServer::TelemetryMessageList::recieve(TMessIn& in) {
#ifdef DEBUG
    std::cerr << "TelemetryMessageList call TMessIn recieve\n";
#endif
    return 0;
}

int samoServer::TelemetryMessageList::recieve(TMessOut& out) {
#ifdef DEBUG
    std::cerr << "TelemetryMessageList call TMessOut recieve\n";
#endif
    return 0;
}

int samoServer::TelemetryMessageList::send(TMessIn&) {
    return 0;
}

int samoServer::TelemetryMessageList::send(TMessOut&) {
    return 0;
}

void samoServer::TelemetryMessageList::connect()
{
#ifdef DEBUG
    std::cout << " connect telemetry \n" ;
#endif
    
};
  
