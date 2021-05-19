#include <boost/asio.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <iostream>
#include <string>
#include <boost/array.hpp>

#include "server.h"

int main()
{
  try
  {
    io_context io_context;

    ip::udp::endpoint ep(ip::udp::v4(), 8001);
    ip::udp::socket sock(io_context, ep);
    udp_server server(std::move(sock));
    io_context.run();
  }
  catch (std::exception& e)
  {
      std::cerr << e.what() << std::endl;
  }

  return 0;
}
