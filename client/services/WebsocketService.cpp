#include <WebsocketService.hpp>
#include <iostream>


using namespace std; 

WebsocketService::WebsocketService()
{
    cout << "WebsocketService::WebsocketService() unimplemented" << endl;
};

WebsocketService::~WebsocketService()
{
    cout << "WebsocketService::~WebsocketService() unimplemented" << endl;
};

void WebsocketService::init()
{
    cout << "WebsocketService::init() unimplemented" << endl;
};

void WebsocketService::register_onopen_callback(std::function<void(int, void*)> callback)
{
    cout << "WebsocketService::register_onopen_callback() unimplemented" << endl;
};

void WebsocketService::register_onerror_callback(std::function<void(int, void*)> callback)
{
    cout << "WebsocketService::register_onerror_callback() unimplemented" << endl;
};


void WebsocketService::register_onclose_callback(std::function<void(int, void*)> callback)
{
    cout << "WebsocketService::register_onclose_callback() unimplemented" << endl;
};

void WebsocketService::register_onmessage_callback(std::function<void(int, void*)> callback)
{
    cout << "WebsocketService::register_onmessage_callback() unimplemented" << endl;
};

void WebsocketService::send_utf8_text(const char* message)
{
    cout << "WebsocketService::send_utf8_text() unimplemented" << endl;
};

void WebsocketService::send_binary(const char* message, int length)
{
    cout << "WebsocketService::send_binary() unimplemented" << endl;
};

void WebsocketService::close(int code, const char* reason)
{
    cout << "WebsocketService::close() unimplemented" << endl;
};