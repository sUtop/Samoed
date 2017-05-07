#include <iostream>
#include <chrono>
#include <thread>
#include <cassert>
#include <queue>

#include "messageTypes.h"

#ifndef MESSAGE_LIST_H
#define MESSAGE_LIST_H

namespace samoServer {

  template <T> 
  class MessageList {
    std::priority_queue<T,std::vector<T>,T.less> list; 
  protected:
    virtual T& recieve() {
#ifdef DEBUG
      std::cerr << "interfase call recieve\n";
      assert(0);
#endif 
    };
    virtual void send(T&) {
#ifdef DEBUG
      std::cerr << "interfase call send\n";
      assert(0);
#endif 
    };
  public:
    MessageList() = delete;
  }

}

#endif
