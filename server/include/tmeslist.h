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


#include "meslist.h"
#include "socet.h"

#ifndef TMESLIST_H 
#define TMESLIST_H

namespace samoServer {

  class TelemetryMessageList : 
          public Socet, 
          public MessageList<TMessIn>, 
          public MessageList<TMessOut> {
    
    int recieve(TMessIn& in) override
    {
#ifdef DEBUG
      std::cerr << "TelemetryMessageList call TMessIn recieve\n";
#endif
    return 0; 
    }
    int recieve(TMessOut& out) override
    {
#ifdef DEBUG
      std::cerr << "TelemetryMessageList call TMessOut recieve\n";
#endif
    return 0; 
    }
    int send(TMessIn& ) override
    {
      return 0;
    }
    int send(TMessOut& ) override
    {
       return 0;
    }
  };

}
#endif
