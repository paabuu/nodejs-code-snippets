const net = require('net');
const HOST = '127.0.0.1';
const PORT = 9696;
let i = 0;

const client = net.connect(PORT, HOST, () => {
    console.log('client start');
    client.write('client write: Hello Server!');
});

client.on('data', (data) => {
    console.log(data.toString(), 'receive from server');
});

client.on('error', (e) => {
    console.log(e);
    client.destroy();
    // client.connect(HOST, PORT, () => {
    //     setInterval(() => {
    //         client.write(String(i++));
    //     }, 1000)
    // });
});

