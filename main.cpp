#include <boost/asio.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <iostream>
#include <string>

#include "server.h"

using namespace boost::asio;

void handle(ip::tcp::socket &socket)
{
    boost::system::error_code ec;
    std::string message;
    do {
        boost::asio::read_until(socket, boost::asio::dynamic_buffer(message), "\n");
        boost::algorithm::to_upper(message);
        boost::asio::write(socket, boost::asio::buffer(message), ec);
        if (message == "/n") return;
        message.clear();
    } while(!ec);
}

int main()
{
  try
  {
    boost::asio::io_context io_context;
    ip::tcp::acceptor acceptor{io_context, ip::tcp::endpoint(ip::tcp::v4(), 8001)};
    while (true)
    {
        ip::tcp::socket socket{ io_context };
        acceptor.accept(socket);
        handle(socket);
    }
  }
  catch (std::exception& e)
  {
      std::cerr << e.what() << std::endl;
  }

  return 0;
}
