#include <boost/algorithm/string/case_conv.hpp>
#include "server.h"

std::string make_daytime_string()
{
  using namespace std; // For time_t, time and ctime;
  time_t now = time(0);
  return ctime(&now);
}


//udp_server::udp_server(boost::asio::io_context& io_context)
//    : socket_(io_context, udp::endpoint(udp::v4(), 8001))
//{
//    start_receive();
//}

//void udp_server::start_receive()
//{
//    socket_.async_receive_from(
//                boost::asio::buffer(recv_buffer_), remote_endpoint_,
//                boost::bind(&udp_server::handle_receive, this,
//                            boost::asio::placeholders::error,
//                            boost::asio::placeholders::bytes_transferred));
//}

//void udp_server::handle_receive(const boost::system::error_code &error, std::size_t)
//{
//    if (!error || error == boost::asio::error::message_size)
//    {
//        boost::shared_ptr<std::string> message(
//                    new std::string(make_daytime_string()));

//        socket_.async_send_to(boost::asio::buffer(*message), remote_endpoint_,
//                              boost::bind(&udp_server::handle_send, this, message,
//                                          boost::asio::placeholders::error,
//                                          boost::asio::placeholders::bytes_transferred));

//        start_receive();
//    }
//}

//void udp_server::handle_send(boost::shared_ptr<std::string>, const boost::system::error_code &, std::size_t)
//{
//    udp::socket socket_;
//    udp::endpoint remote_endpoint_;
//    boost::array<char, 1> recv_buffer_;
//}

//void udp_server::handle(udp::socket &socket)
//{
//    boost::system::error_code ec;
//    std::string message;
//    do {
//        boost::asio::read_until(socket, boost::asio::dynamic_buffer(message), "\n");
//        boost::algorithm::to_upper(message);
//        boost::asio::write(socket, boost::asio::buffer(message), ec);
//        if (message == "/n") return;
//        message.clear();
//    } while(!ec);
//}
