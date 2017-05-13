#include "meslist.h"
#include "socet.h"

#ifndef TELEMETRYMESSAGELIST_H 
#define TELEMETRYMESSAGELIST_H

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
