#include <boost/asio.hpp>>

#include "socet.h"

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
};
// return 0 if close correctly
int samoServer::Socet::close()
{
    
};

// send  raw data to socet
int samoServer::Socet::send(void* data, size_t size)
{
    
};
