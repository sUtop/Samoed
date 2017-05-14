/*
 file : socket.h
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

#ifndef SOCKET_H
#define SOCKET_H

#include <string>
#include <atomic>
#include "server_types.h"

// Use boost library 
// Copyright (c) 2003-2017 Christopher M. Kohlhoff (chris at kohlhoff dot com)
#include <boost/asio.hpp>
using boost::asio::ip::tcp;

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
    std::atomic_int m_lock;
    boost::asio::io_service m_io_service;
    tcp::endpoint m_endpoint;
    tcp::acceptor m_acceptor;
    tcp::socket m_socket;
  protected:
    // return 0 if open correctly
    int open(data_type socet_type, std::string address);
    // send  raw data to socet
    int send(void* data, std::size_t size);
    int receive(void* data, std::size_t &size);
  public:
     typedef void (*call_funct)(boost::system::error_code ec);
    // Start send/reciev data to server
     void run(call_funct);
  };
}

#endif
