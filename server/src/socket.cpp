/*
 file : socket.cpp
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

#include <iostream>
#include "socket.h"

using namespace samoServer;

int samoServer::Socket::open(data_type socket_type) {
    m_lock = 0;
    m_endpoint = tcp::endpoint(tcp::v4(), 777);
    m_acceptor = tcp::acceptor(m_io_service, m_endpoint);
    m_socket = tcp::socket(m_io_service);
    return 0;
};

// send  raw data to socket

int samoServer::Socket::send(void* data, size_t size) {
    bool send = false;
    while (!send) {
        m_lock++;
        if (m_lock < 2) {
            // message = data
            // awaiting for callback
#ifdef DEBUG
            std::cout << " Sendet! " << data << "\n";
#endif
            send = true;
        }
        m_lock--;
    }
    return 0;
};

int samoServer::Socket::receive(void* data, std::size_t &size) {
    bool receive = false;
    while (!receive) {
        m_lock++;
        if (m_lock < 2) {
            // data = message
            // awaiting for callback
#ifdef DEBUG
            std::cout << " Received! " << data << "\n";
#endif
            receive = true;
        }
        m_lock--;
    }
    return 0;
};

void samoServer::Socket::run() {
    m_acceptor.async_accept(m_socket, [this](boost::system::error_code ec)
    {
        connect();
    });
    // detach and awaiting to connections :
    m_io_service.run();
};

void samoServer::Socket::connect()
{
#ifdef DEBUG
    std::cout << " connect base \n";
#endif
};
