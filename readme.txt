This is a node.js module, written in C++, that DES encrypts given buffer
with the given key. And it actually works, compared to nonsense output that
node.js's crypto module produced.

It was written by Peteris Krumins (peter@catonmat.net).
His blog is at http://www.catonmat.net  --  good coders code, great reuse.

------------------------------------------------------------------------------

About
-----

I wrote this module so that I could add VNC Authentication in node-rfb module.
Don't use it for anything else cause DES is completely broken and can be
cracked in a day.


How to use it?
--------------

    var ecnrypted_data = require('des').encrypt(key, data_buffer);

Note: data_buffer's length must be a multiple of 8.


How to compile?
---------------

    node-waf configure build


------------------------------------------------------------------------------

Have fun encrypting. Not. (Don't use this module for encryption.)


Sincerely,
Peteris Krumins
http://www.catonmat.net

