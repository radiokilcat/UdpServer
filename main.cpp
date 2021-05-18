#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;

int main()
{
    io_service service;
    ip::udp::socket sock(service);
    sock.open(ip::udp::v4());
    ip::udp::endpoint receiver_ep(ip::address::from_string("127.0.0.1"), 80);
    sock.send_to(buffer("testing\n"), receiver_ep);
    char buff[512];
    ip::udp::endpoint sender_ep;
    sock.receive_from(buffer(buff), sender_ep);
    return 0;
}
