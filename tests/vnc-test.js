var des = require('des');
var fs = require('fs');

var challenge = fs.readFileSync('challenge')
var response = fs.readFileSync('response')
var encrypted = des.encrypt("browsers", challenge);

console.log(encrypted);
console.log(response);

