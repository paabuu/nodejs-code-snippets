const addon = require('./build/Release/addon');

console.log(addon.hello());
addon.call((message) => {
    console.log(message);
});