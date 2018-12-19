const addon = require('./build/Release/addon');
const t = require('./build/Release/template');
const o = require('./build/Release/object');
const accessor = require('./build/Release/accessor');
const internal = require('./build/Release/internal_field');
const add = require('./build/Release/add');
const addon2 = require('./build/Release/myobject');

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

// console.log(internal);
// console.log(internal.getInfo(1));

// console.log(add(100, 200));

const obj = addon2.MyObject(10);
console.log(obj);
console.log(obj.plusOne());