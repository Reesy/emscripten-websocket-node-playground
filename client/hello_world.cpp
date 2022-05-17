#include <emscripten/emscripten.h>
#include <emscripten/websocket.h>
#include <WebsocketService.hpp>
#include <stdio.h>

using namespace std;

void handle_incoming_message(const char *message)
{
    printf("Received message: %s\n", message);
}

int main()
{

    if (!emscripten_websocket_is_supported())
    {
        return 0;
    };
    
    WebsocketService * websocketService = new WebsocketService((char *)"ws://localhost:7001");


    websocketService->register_onopen_callback([websocketService]() 
    {
        cout << "Registered onopen callback being called. " << endl;
        websocketService->send_utf8_text("Konnichiwa!");
    });
    
    websocketService->init();
}