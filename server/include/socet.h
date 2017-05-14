/*
 file : socet.h
    Copyright (c) 2017 Gorban Igor Utop@inbox.ru

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/


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
