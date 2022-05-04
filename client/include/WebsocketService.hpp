#pragma once
#include <iostream> 

class WebsocketService
{

    public:
        WebsocketService();
        ~WebsocketService();
        void init();

        void register_onopen_callback(std::function<void(int, void*)> callback);
        void register_onerror_callback(std::function<void(int, void*)> callback);
        void register_onclose_callback(std::function<void(int, void*)> callback);
        void register_onmessage_callback(std::function<void(int, void*)> callback);

        void send_utf8_text(const char* message);
        void send_binary(const char* message, int length);
        void close(int code, const char* reason);
};