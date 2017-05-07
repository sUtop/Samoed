#include "messagelist.h"
#include "socet.h"

#ifdef  WEBMESSAGE_LIST_H
#define WEBMESSAGE_LIST_H

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

#endif
