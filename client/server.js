// A simple node server that uses express to server a static file
// and a simple web page.


var express = require('express');
var app = express();

app.use(express.static(__dirname));
//app.use(express.static(__dirname + '/hello_world.js'));

app.get('/', function(req, res) {
  res.sendFile(__dirname + '/index.html');
});

app.listen(7000);

console.log('Listening on port 7000');
