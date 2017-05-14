#include "meslist.h"
#include "io.h"

#ifndef TELBDSHED_H
#define TELBDSHED_H

namespace samoServer {
  class DataBaseMessageList : public io, public MessageList<DBLine> {
    int recieve(DBLine& in) {
#ifdef DEBUG
      std::cerr << "DataBaseMessageList call recieve\n";
#endif
    return 0;
    };
    int send(DBLine& out) {
#ifdef DEBUG
      std::cerr << "DataBaseMessageList call send\n";
#endif
    return 0;
    };
  }; 
  
}
#endif