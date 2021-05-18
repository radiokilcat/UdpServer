#ifndef SERVER_H
#define SERVER_H

#include <boost/asio/ip/tcp.hpp>

//#include "concurrent.hpp"
//#include "utility/memory.hpp"
//#include "speed_counter.hpp"
//#include "utility/types.hpp"

class http_server_connection;

class http_server
{

public:

//    using handler_connection = std::function<void(boost::system::error_code, std::shared_ptr<http_server_connection>)>;

//    static std::shared_ptr<http_server> create(strand_ptr strand, handler_connection handle);

//    void start(const std::string& host, port_t port, handler_type handle);
//    void close();

//    bool remove_connection(uintptr_t id);

//    void speed(speed_callback handler) const;

private:

//    http_server(strand_ptr strand, handler_connection handle);

//    void async_accept();
//    void add_connection(const std::shared_ptr<http_server_connection>& server_connection);

//    boost::asio::ip::tcp::resolver resolver_;
//    boost::asio::ip::tcp::acceptor acceptor_;

//    handler_connection handle_connection_;

//    speed_counter speed_counter_;

//    strand_pool strand_pool_;

//    mutable std::mutex mutex_;
//    std::map<uintptr_t, std::shared_ptr<http_server_connection>> connection_map_;
};

#endif // SERVER_H
