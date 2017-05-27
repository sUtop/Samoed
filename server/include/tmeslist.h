/*
 file : tmeslist.h
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

#ifndef TMESLIST_H 
#define TMESLIST_H

#include "meslist.h"
#include "socket.h"

namespace samoServer {

    class TelemetryMessageList :
    public Socket,
    public MessageList<TMessIn>,
    public MessageList<TMessOut> {
    public:
        TelemetryMessageList();
        void connect() override;
        void execute() override
        {
#ifdef DEBUG
            std::cerr << "execute Telemetry list\n";
#endif
            while(1)
            {
                std::this_thread::sleep_for(std::chrono::seconds(2));                
            }
            
        };
    protected:
        int recieve(TMessIn& in) override ;
        int recieve(TMessOut& out) override ;
        int send(TMessIn&) override ;
        int send(TMessOut&) override ;

    };

}
#endif
