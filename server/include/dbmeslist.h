/*
 file : dbmeslist.h
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

#ifndef DMESLIST_H
#define DMESLIST_H

#include "meslist.h"
#include "io.h"

namespace samoServer {

    class DataBaseMessageList : public io, public MessageList<DBLine> {

        int recieve(DBLine& in) {
#ifdef DEBUG
            std::cerr << "DataBaseMessageList call recieve\n";
#endif
            return 0;
        };

        int send(DBLine& out) {
#ifdef DEBUG
            std::cerr << "DataBaseMessageList call send\n";
#endif
            return 0;
        };
    };

}
#endif


