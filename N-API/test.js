const addon = require('./build/Release/pet');

const pet = new addon.pet();
console.log(pet);
pet.setName("cat");
console.log(pet);
console.log(pet.summary());