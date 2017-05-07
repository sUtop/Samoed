#include <cstdint>
#include <ctime>
#include <vector>

#ifndef MESSAGE_TYPES_H
#define MESSAGE_TYPES_H

namespace samoServer {

  typedef std::uint64_t time_date_type;
  typedef std::uint64_t flag_type;
  typedef std::uint16_t char_type;
  typedef std::uint64_t data_type;
  typedef std::uint64_t objectID_type;
  typedef double        pos_type;

  typedef std::pair<pos_type,pos_type>  location_type;

  struct WebMess {
    time_date_type timeDate;
    data_type      data[4];
    char_type      sender[16];
    char_type      reciever[16];
    flag_type      flags; 
  };

  struct TMessIn {
    enum {
      CHANGE_COUNT = 1,
      POSITION,
      SOS,
      ILLEGAL_MESSAGE
    } TMessIn_type;
    time_date_type timeDate; // < date of send message
    objectID_type  objectID; // < id of bus
    data_type      data;     // < payload (some useful data)
    location_type  location; // < current location of bus
    data_type      type;     // < type of message 
  };

  struct TMessOut {
    enum {
      ASK_LOCATION = 1,
      BUY_A_TICKET,
      DELETE_A_TICKET,
      ILLEGAL_MESSAGE
    } TMessOut_type;
    objectID_type objectID;
    data_type     data;
    data_type type;
  };

  struct DBMess {
    std::vector<WebMess> data; // < messages from data base may be variable size
  };
}

#endif
