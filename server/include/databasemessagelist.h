#include "messagelist.h"
#include "io.h"

#ifndef DATABASENESSAGELIST_H
#define DATABASENESSAGELIST_H

namespace samoServer {
  class DataBaseMessageList : public io, public MessageList<DBMess> {
    int recieve(DBMess& in) {
#ifdef DEBUG
      std::cerr << "DataBaseMessageList call recieve\n";
#endif
    return 0;
    };
    int send(DBMess& out) {
#ifdef DEBUG
      std::cerr << "DataBaseMessageList call send\n";
#endif
    return 0;
    };
  }; 
  
}
#endif


