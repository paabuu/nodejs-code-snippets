const addon = require('./build/Release/addon');
const t = require('./build/Release/template');
const o = require('./build/Release/object');
const accessor = require('./build/Release/accessor');
const internal = require('./build/Release/internal_field');

// console.log(addon.hello());
// addon.call((message) => {
//     console.log(message);
// });

// const a = new t.TestClass();
// console.log(a.value);
// a.set();
// console.log(a.value);
// console.log(o.obj());
// console.log(o.obj);

// console.log(accessor.var1);
// accessor.var1 = 10;
// console.log(accessor.var1);

console.log(internal);
console.log(internal.getInfo(1));