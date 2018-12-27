const addon = require('./build/Release/sleep');

const ret = addon.sort([3, 2, 1, 4]);
console.log(ret);