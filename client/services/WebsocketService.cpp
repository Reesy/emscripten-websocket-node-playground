#include <WebsocketService.hpp>
#include <emscripten/emscripten.h>
#include <emscripten/websocket.h>
#include <iostream>

using namespace std; 

WebsocketService::WebsocketService()
{
    cout << "WebsocketService::WebsocketService() unimplemented" << endl;
}

WebsocketService::~WebsocketService()
{
    cout << "WebsocketService::~WebsocketService() unimplemented" << endl;
}


void WebsocketService::init()
{
    setupws();
    cout << "WebsocketService::init() unimplemented" << endl;
}

void WebsocketService::register_onopen_callback(std::function<void(int, void*)> callback)
{
    cout << "WebsocketService::register_onopen_callback() unimplemented" << endl;
}

void WebsocketService::register_onerror_callback(std::function<void(int, void*)> callback)
{
    cout << "WebsocketService::register_onerror_callback() unimplemented" << endl;
}


void WebsocketService::register_onclose_callback(std::function<void(int, void*)> callback)
{
    cout << "WebsocketService::register_onclose_callback() unimplemented" << endl;
}

void WebsocketService::register_onmessage_callback(std::function<void(int, void*)> callback)
{
    cout << "WebsocketService::register_onmessage_callback() unimplemented" << endl;
}

void WebsocketService::send_utf8_text(const char* message)
{
    cout << "WebsocketService::send_utf8_text() unimplemented" << endl;
}

void WebsocketService::send_binary(const char* message, int length)
{
    cout << "WebsocketService::send_binary() unimplemented" << endl;
}

void WebsocketService::close(int code, const char* reason)
{
    cout << "WebsocketService::close() unimplemented" << endl;
}

void WebsocketService::test(const char* message)
{
    cout << "The test function was called, the test was a resounding success" << endl;
    cout << "wrapped message is" << message << " << " << endl;
}
EM_BOOL WebsocketService::onopen(int eventType, const EmscriptenWebSocketOpenEvent *websocketEvent, void *userData)
{

    puts("onopen");

    EMSCRIPTEN_RESULT result;
    result = emscripten_websocket_send_utf8_text(websocketEvent->socket, "hello world");
    if (result)
    {

        printf("Failed to emscripten_websocket_send_utf8_text(): %d\n", result);
    }
    return EM_TRUE;
}
EM_BOOL WebsocketService::onerror(int eventType, const EmscriptenWebSocketErrorEvent *websocketEvent, void *userData)
{

    puts("onerror");

    return EM_TRUE;
}
EM_BOOL WebsocketService::onclose(int eventType, const EmscriptenWebSocketCloseEvent *websocketEvent, void *userData)
{

    puts("onclose");

    return EM_TRUE;
}

EM_BOOL WebsocketService::onmessage(int eventType, 
                                    const EmscriptenWebSocketMessageEvent *websocketEvent, 
                                    void *userData)
{

    puts("onmessage");
    if (websocketEvent->isText)
    {

        // For only ascii chars.
        printf("message: %s\n", websocketEvent->data);
        //Convert from uint8_t to char 
        char *message = (char *)websocketEvent->data;


        ((WebsocketService*)userData)->test(message);
    }
    
    

    EMSCRIPTEN_RESULT result;
    result = emscripten_websocket_close(websocketEvent->socket, 1000, "no reason");
    if (result)
    {

        printf("Failed to emscripten_websocket_close(): %d\n", result);
    }
    return EM_TRUE;
}


void WebsocketService::setupws(){
    
    cout << "WebsocketService::setupws() unimplemented" << endl;
    EmscriptenWebSocketCreateAttributes ws_attrs = {
        "ws://localhost:7001",
        NULL,
        EM_TRUE
    };

    EMSCRIPTEN_WEBSOCKET_T ws = emscripten_websocket_new(&ws_attrs);
    
    void* blah = (void*)this;
    emscripten_websocket_set_onopen_callback(ws, NULL, this->onopen);
    emscripten_websocket_set_onerror_callback(ws, NULL, this->onerror);
    emscripten_websocket_set_onclose_callback(ws, NULL, this->onclose);
    emscripten_websocket_set_onmessage_callback(ws, blah, this->onmessage);
}

