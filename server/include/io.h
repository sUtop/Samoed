#include <iostream>
#include <fstream>

#include "messageTypes.h"

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
    DBMess& find(objectID_type objectID);
  public:
    // Open data base return 0 if O.K.
    int openDB(std::string filename);
    // close base return 0 if O.K.
    int close();
    io() = delete;
  };
  
}

#endif
