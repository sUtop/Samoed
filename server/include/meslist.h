/*
 file : meslist.h
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

#ifndef MESLIST_H
#define MESLIST_H

#include <iostream>
#include <chrono>
#include <thread>
#include <cassert>
#include <queue>
#include <mutex>

#include "server_types.h"

namespace samoServer {

    template <class T>
    struct List {

        void put(T& t) {
            mut.lock();
            list.push(t);
            mut.unlock();
        }

        int get(T& t) {
            if (!list.empty()) {
                mut.lock();
                list.pop(t);
                mut.unlock();
                return 0;
            }
            return 1;
        }

    private:
        std::vector<T> list;
        std::mutex mut;
    };

    /* *\brief Класс-шаблон для отправки и получения сообщений
     */
    template <class T>
    class MessageList {
    protected:
        List<T> list;

    public:

        virtual int execute() = delete;
        
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
    };

}

#endif
