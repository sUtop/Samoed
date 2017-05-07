#include "messagelist.h"
#inlcude "socet.h"

#ifndef TELEMETRYMESSAGELIST_H telemetrymessagelist.h 
#define TELEMETRYMESSAGELIST_H

namespace samoServer {

  template <class T>
  class TelemetryMessageList : 
          public Socet, 
          public MessageList<TMessIn>, 
          public MessageList<TMessOut> {
    
    TMessIn& recieve() override
    {
#ifdef DEBUG
      std::cerr << "TelemetryMessageList call TMessIn recieve\n";
#endif 
    }
    TMessOut& recieve() override
    {
#ifdef DEBUG
      std::cerr << "TelemetryMessageList call TMessOut recieve\n";
#endif 
    }
    void send(TMessIn& ) override
    {
    }
    void send(TMessOut& ) override
    {
    }
  }

}
#endif
