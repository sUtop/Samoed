/*
 file : io.h
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
#include <fstream>

#include "server_types.h"

#ifndef IO_H
#define IO_H

namespace samoServer { 
  
  class io {
  // handler
    std::fstream handler;
  protected:
    int putLocation(location_type location, 
                    objectID_type objectID, 
                    time_date_type date);
    // TODO Make receive from db
    // DBMess& find(objectID_type objectID);
  public:
    // Open data base return 0 if O.K.
    int openDB(std::string filename);
    // close base return 0 if O.K.
    int close();
    io() = delete;
  };
  
}

#endif
