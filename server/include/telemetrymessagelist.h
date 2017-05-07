#include "messagelist.h"
#include "socet.h"

#ifndef TELEMETRYMESSAGELIST_H 
#define TELEMETRYMESSAGELIST_H

namespace samoServer {

  // !!! functions that differ only in their return type cannot be overloaded 


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
    }
    int send(TMessOut& ) override
    {
    }
  };

}
#endif
