var des = require('des');
var fs = require('fs');
var assert = require('assert');

var challenge = fs.readFileSync(__dirname + '/challenge')
var response = fs.readFileSync(__dirname + '/response')

exports.challenge_response = function () {
    var encrypted = des.encrypt('browsers', challenge);
    assert.eql(encrypted, response);
};
