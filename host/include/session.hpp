#pragma once

#include <asio.hpp>
#include <js_ic.hpp>

using asio::ip::tcp;

class session : public std::enable_shared_from_this< session > {
public:
    session( tcp::socket _socket );

    void start( void );

private:
    void doRead( void );
    void doWrite( std::size_t _length );

private:
    tcp::socket socket_;
    const std::string fileName_ = "main.js";
    enum { MAX_LENGTH = 1024 };
    char data_[ MAX_LENGTH ];
};
