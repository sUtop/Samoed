#include <iostream>
#include <chrono>
#include <thread>
#include <cassert>
#include <queue>

#include "messageTypes.h"

#ifndef MESSAGE_LIST_H
#define MESSAGE_LIST_H

namespace samoServer {

  template <class T> 
  class MessageList {
    std::priority_queue<T> list; 
  protected:
    virtual int recieve(T& in) {
#ifdef DEBUG
      std::cerr << "interfase call recieve\n";
      assert(0);
#endif
    return 0;
    };
    virtual int send(T& out) {
#ifdef DEBUG
      std::cerr << "interfase call send\n";
      assert(0);
#endif
    return 0;
    };
  public:
    MessageList() = delete;
  };

}

#endif
