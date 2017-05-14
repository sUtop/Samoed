#include <iostream>
#include <chrono>
#include <thread>
#include <cassert>
#include <queue>

#include "server_types.h"

#ifndef MESLIST_H
#define MESLIST_H

namespace samoServer {

  /* *\brief Класс-шаблон для отправки и получения сообщений
   */
  template <class T> 
  class MessageList {
    std::priority_queue<T> list; 
  protected:
    /* *\brief Получение сообщения
     */
    virtual int recieve(T& in) {
#ifdef DEBUG
      std::cerr << "interfase call recieve\n";
      assert(0);
#endif
    return 0;
    };
    /* *\brief Отправка сообщений
     */
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
