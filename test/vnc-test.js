var des = require('des');
var fs = require('fs');
var assert = require('assert');

var challenge = fs.readFileSync(__dirname + '/challenge')
var response = fs.readFileSync(__dirname + '/response')

exports.challenge_response = function () {
    var encrypted = des.encrypt('browsers', challenge);
    
    console.log(encrypted);
    console.log(response);
};

if (__filename === process.argv[1]) {
    exports.challenge_response();
}
