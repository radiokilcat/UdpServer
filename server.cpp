#include <boost/algorithm/string/case_conv.hpp>
#include "server.h"

std::string make_daytime_string()
{
  using namespace std; // For time_t, time and ctime;
  time_t now = time(0);
  return ctime(&now);
}


udp_server::udp_server(ip::udp::socket socket)
    : socket_(std::move(socket)),
      packet_writer_{ new Writer };
{
    async_read();
}

void udp_server::async_read()
{
    socket_.async_receive_from(buffer(data_, 1500),
                               remote_endpoint_,
                               [this](boost::system::error_code ec, std::size_t length)
                               {
                                   if (ec) return;

                                   data_[length] = '\0';

                                   if (strcmp(data_, "\n") == 0)
                                       return;

                                   boost::algorithm::to_upper(data_);
                                   this->async_write();
    });
}

void udp_server::async_write()
{
    socket_.async_send_to(buffer(data_, strlen(data_)),
                          remote_endpoint_,
                          [this](boost::system::error_code ec, std::size_t length)
                          {
                             if (ec) return;
                             data_[0] = '\0';
                             this->async_read();
                          });
}
