/*
 file : server.cpp
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


#include <iostream>
#include <thread>
#include <ctime>

#include "server_types.h"
#include "tmeslist.h"

#include "telbdshed.h"

const std::chrono::nanoseconds sleep_time(10);

using namespace samoServer;


int main() {
    
    TelDBShed telBD;
    std::thread tb_thread ( [&telBD] {telBD.run();});
    tb_thread.detach();
    
#if 0
    std::cout << " Size of TMessIn  " << sizeof (TMessIn) << "\n";
    std::cout << " Size of WebMess  " << sizeof (WebMess) << "\n";
    std::cout << " Size of TMessOut " << sizeof (TMessOut) << "\n";
    std::cout << " Size of location_type " << sizeof (location_type) << " = 2 * " << sizeof (pos_type) << "\n";
    std::cout << " Size of time_t " << sizeof (std::time_t) << "\n";
    std::cout << " Size of IDObject " << sizeof ( objectID_type) << "\n";
    std::cout << " Size of DBLine " << sizeof ( DBLine) << "\n";
#endif
    
    while(1)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    
    return 0;
}

