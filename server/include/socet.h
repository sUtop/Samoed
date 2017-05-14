#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <atomic>

#include "server_types.h"

#ifndef SOCET_H
#define SOCET_H

namespace samoServer {
  // List of types to connect
  enum {
    WEB_CLIENT = 1,
    WEB_SERWER,
    DRIVER,      // Bus driver, not os-driver.
    INCORRECT_TYPE
  } socet_type;

  enum {
    READY = 0,
    READ
  } socet_status;

  class Socet {
    // Atomic flag for using socets in different treds
    std::atomic_flag lock = ATOMIC_FLAG_INIT;
  public:
    // return 0 if open correctly
    int open(data_type socet_type, std::string address);
    // return 0 if close correctly
    int close();
  protected:
    // send  raw data to socet
    int send(void* data, size_t size);
  };
}

#endif
