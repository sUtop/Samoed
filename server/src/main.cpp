#include <iostream>
#include <thread>
#include <ctime>

#include "server_types.h"
const std::chrono::nanoseconds sleep_time(10);

using namespace samoServer;

int main()
{
  std::cout << " Size of TMessIn  " << sizeof(TMessIn) << "\n"; 
  std::cout << " Size of WebMess  " << sizeof(WebMess) << "\n"; 
  std::cout << " Size of TMessOut " << sizeof(TMessOut) << "\n"; 
  std::cout << " Size of location_type " << sizeof(location_type) << " = 2 * " << sizeof(pos_type) << "\n"; 
  std::cout << " Size of time_t " << sizeof(std::time_t) << "\n";
  std::cout << " Size of IDObject " << sizeof( objectID_type) << "\n";
  std::cout << " Size of DBLine " << sizeof( DBLine) << "\n"; 
  return 0;
}

