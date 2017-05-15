/*
 file : server_types.h
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

#ifndef SERVER_TYPES_H
#define SERVER_TYPES_H

#include <cstdint>
#include <ctime>

namespace samoServer {

    typedef std::uint64_t time_date_type;
    typedef std::uint64_t flag_type;
    typedef std::uint16_t char_type;
    typedef std::uint64_t data_type;
    typedef std::uint64_t objectID_type;
    typedef double pos_type;

    const int WEB_NAME_SIZE = 16;
    typedef std::pair<pos_type, pos_type> location_type;

    // One message from/to web

    struct WebMess {
        time_date_type timeDate;
        data_type data[4];
        char_type sender[WEB_NAME_SIZE];
        char_type reciever[WEB_NAME_SIZE];
        flag_type flags;
    };

    // One message from object

    struct TMessIn {

        enum {
            CHANGE_COUNT = 1,
            POSITION,
            SOS,
            ILLEGAL_MESSAGE
        } TMessIn_type;
        time_date_type timeDate; // < date of send message
        objectID_type objectID; // < id of bus
        data_type data; // < payload (some useful data)
        location_type location; // < current location of bus
        data_type type; // < type of message 
    };

    // One message to object 

    struct TMessOut {

        enum {
            ASK_LOCATION = 1,
            BUY_A_TICKET,
            DELETE_A_TICKET,
            ILLEGAL_MESSAGE
        } TMessOut_type;
        objectID_type objectID;
        data_type data;
        data_type type;
    };

    // One Data Base line for file

    struct DBLine {
        std::time_t time;
        objectID_type id;
        data_type data[6];
    };

    // Header for db file
    // TODO fill header

    struct DBHeader {
    };
}

#endif
