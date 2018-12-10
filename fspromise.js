const fs = require('fs');
const fsPromise = fs.promises;

fsPromise.open('./progress.js', 'r').then(h => {
    h.readFile({
        encoding: 'utf-8',
        flag: 'r'
    }).then(data => console.log(data));
}).catch(err => console.log(err));

fsPromise.open('1.txt', 'a').then(h => {
    h.appendFile('hahax');
});