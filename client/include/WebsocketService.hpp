#pragma once
#include <iostream> 
#include <emscripten/emscripten.h>
#include <emscripten/websocket.h>

class WebsocketService
{

    public:
        WebsocketService();
        ~WebsocketService();
        void init();
        void test(const char* message);

        void register_onopen_callback(std::function<void(int, void*)> callback);
        void register_onerror_callback(std::function<void(int, void*)> callback);
        void register_onclose_callback(std::function<void(int, void*)> callback);
        void register_onmessage_callback(std::function<void(int, void*)> callback);

        void send_utf8_text(const char* message);
        void send_binary(const char* message, int length);
        void close(int code, const char* reason);
        
    private:
        static EM_BOOL onerror(int eventType, const EmscriptenWebSocketErrorEvent *websocketEvent, void *userData);
        static EM_BOOL onopen(int eventType, const EmscriptenWebSocketOpenEvent *websocketEvent, void *userData);
        static EM_BOOL onclose(int eventType, const EmscriptenWebSocketCloseEvent *websocketEvent, void *userData);
        static EM_BOOL onmessage(int eventType, const EmscriptenWebSocketMessageEvent *websocketEvent, void *userData);
        void setupws();

};