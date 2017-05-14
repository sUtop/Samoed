/*
 file : webmeslist.h
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

#ifndef WEBMESLIST_H
#define WEBMESLIST_H

#include "meslist.h"
#include "socket.h"

namespace samoServer {

  class WebMessageList : public Socet, public MessageList<WebMess> {
    
    int recieve(WebMess& in) override
    {
#ifdef DEBUG
      std::cerr << "TelemetryMessageList call TMessIn recieve\n";
#endif
      return 0; 
    }
    int send(WebMess& ) override
    {
      return 0;
    }
  };

};
#endif
