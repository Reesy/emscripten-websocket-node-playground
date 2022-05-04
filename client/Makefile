
all: hello_world.o 

hello_world.o: hello_world.cpp
	 emcc hello_world.cpp services/WebsocketService.cpp -lwebsocket.js -I include -o hello_world.js

.PHONY: clean
clean: 
	rm hello_world.js hello_world.wasm hello_world.o