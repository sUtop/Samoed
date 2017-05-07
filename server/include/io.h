#inlcude <iostream>
#include <fstream>

#include "messageTypes.h"

#ifndef IO_H
#define IO_H

namespace samoServer { 
  
  class io {
  // handler
  std::fstream handler;
  protected:
    template<T>
    putLocation(T&, objectID, date);
    DBMess& find(objectID);
  public:
    // Open data base return 0 if O.K.
    int openDB(std::string filename);
    // close base return 0 if O.K.
    int close();
  }
  
}

#endif
