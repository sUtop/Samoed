/*
 file : telbdshed.h
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

#ifndef TELBDSHED_H
#define TELBDSHED_H

#include "meslist.h"
#include "io.h"
#include "dbmeslist.h"
#include "tmeslist.h"

namespace samoServer {

    class TelDBShed {
        // ! just receive messages - interface used just for receive mes :
        MessageList<TMessIn> * TelList;
        // 
        MessageList<DBLine> * BdList;

    public:

        TelDBShed() {
            TelList = new TelemetryMessageList();
            BdList = new DataBaseMessageList();
        }

        void run()
        {
            std::thread tel([&]{TelList->execute();});
            std::thread bd([&]{BdList->execute();});
            
            tel.detach();
            bd.detach();
            while (1)
            {
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
            
        }
        
    };

}
#endif