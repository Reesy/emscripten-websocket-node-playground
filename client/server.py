import SimpleHTTPServer
import SocketServer

PORT = 7000

Handler = SimpleHTTPServer.SimpleHTTPRequestHandler

httpd = SocketServer.TCPServer(("", PORT), Handler)

print "serving at port", PORT

while True:
    httpd.handle_request()
