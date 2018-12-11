const fs = require('fs');

const readable = fs.createReadStream('../chmod.js');
const writeable = fs.createWriteStream('copy.js');

readable.on('data', chunk => {
    console.log(chunk.toString());
});

readable.on('end', () => {
    console.log('end');
});

readable.pipe(writeable);