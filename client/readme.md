
# Notes

The include/emscripten folder only exists for intellisense purposes, used libraries are already discovered by the emcc compiler.

## Compiling 

``` emmake make ```

## Compiling manually 

``` emcc hello_world.cpp services/WebsocketService.cpp -lwebsocket.js -I include -o hello_world.js```

## Running

``` python server.py ```

## Cleaning 

``` emmake make clean ```