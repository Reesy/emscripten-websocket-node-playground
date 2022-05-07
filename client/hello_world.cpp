#include <emscripten/emscripten.h>
#include <emscripten/websocket.h>
#include <WebsocketService.hpp>
#include <stdio.h>

using namespace std;

int main()
{

    if (!emscripten_websocket_is_supported())
    {
        return 0;
    };

    WebsocketService * websocketService = new WebsocketService();



    websocketService->init();


    // I want the next line to be called only after the websocket is connected
    // this line could be wrapped into the onopen callbacks 
    //websocketService->send_utf8_text("Hello World class call from C++");
}