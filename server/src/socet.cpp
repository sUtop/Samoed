/*
 file : socet.cpp
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

#include "socet.h"

// Use boost library 
// Copyright (c) 2003-2017 Christopher M. Kohlhoff (chris at kohlhoff dot com)
#include <boost/asio.hpp>
using boost::asio;

// List of types to connect
//enum {
//  WEB_CLIENT = 1,
//  WEB_SERWER,
//  DRIVER,      // Bus driver, not os-driver.
//  INCORRECT_TYPE
//} socet_type;
    
//enum {
//  READY = 0,
//  READ
//} socet_status;

// Atomic flag for using socets in different treds
//    std::atomic_flag lock = ATOMIC_FLAG_INIT;

// return 0 if open correctly
int samoServer::Socet::open(data_type socet_type, std::string address)
{
    using boost::asio;
    io_service service;
    ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 2001);
    ip::tcp::socket sock(service);
    sock.connect(ep);
    
    //Here is a simple synchronous server:using boost::asio;
    typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;
    io_service service;
    ip::tcp::endpoint ep( ip::tcp::v4(), 2001)); // listen on 2001
    ip::tcp::acceptor acc(service, ep);
    while ( true) 
    {
        socket_ptr sock(new ip::tcp::socket(service));
        acc.accept(*sock);
        boost::thread( boost::bind(client_session, sock));
    }
    
};


void client_session(socket_ptr sock)
 {
    while ( true)
     {
        char data[512];
        size_t len = sock->read_some(buffer(data));
        if ( len > 0) 
        write(*sock, buffer("ok", 2));
    }
}    


// return 0 if close correctly
int samoServer::Socet::close()
{
    
};

// send  raw data to socet
int samoServer::Socet::send(void* data, size_t size)
{
    
};
