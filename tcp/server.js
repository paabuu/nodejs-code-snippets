const net = require('net');
const HOST = '127.0.0.1';
const PORT = 9696;

const server = net.createServer(socket => {
    socket.on('data', data => {
        console.log(data.toString());
        socket.write("Hello Client!");
    });
});

server.on('error', () => {
    server.close();
    server.listen(PORT, HOST);
});

server.listen(PORT, HOST);
