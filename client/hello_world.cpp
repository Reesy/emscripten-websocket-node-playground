#include <emscripten/emscripten.h>
#include <emscripten/websocket.h>
#include <WebsocketService.hpp>
#include <stdio.h>



int main()
{

    if (!emscripten_websocket_is_supported())
    {

        return 0;
    };

    WebsocketService * websocketService = new WebsocketService();

    websocketService->init();
}