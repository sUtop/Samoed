#include "meslist.h"
#include "socet.h"

#ifndef WEBMESLIST_H
#define WEBMESLIST_H

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
