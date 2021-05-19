#ifndef SERVER_H
#define SERVER_H

#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>

#include "writer.h"

using namespace boost::asio;

class udp_server
{
public:
  udp_server(ip::udp::socket socket);

private:
  void async_read();
  void async_write();
  ip::udp::socket socket_;
  ip::udp::endpoint remote_endpoint_;
  char data_[1500 + 1];
  Writer packet_writer_;
};

#endif // SERVER_H

