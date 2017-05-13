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

  const int WEB_NAME_SIZE = 16;
  typedef std::pair<pos_type,pos_type>  location_type;

  // One message from/to web
  struct WebMess {
    time_date_type timeDate;
    data_type      data[4];
    char_type      sender[WEB_NAME_SIZE];
    char_type      reciever[WEB_NAME_SIZE];
    flag_type      flags; 
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
    objectID_type  objectID; // < id of bus
    data_type      data;     // < payload (some useful data)
    location_type  location; // < current location of bus
    data_type      type;     // < type of message 
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
    data_type     data;
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
