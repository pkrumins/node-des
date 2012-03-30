#include <v8.h>
#include <node.h>
#include <node_buffer.h>
#include <cstring>
#include "d3des.h"

using namespace v8;
using namespace node;

Handle<Value>
ErrorException(const char *msg)
{
    HandleScope scope;
    return Exception::Error(String::New(msg));
}

Handle<Value>
VException(const char *msg)
{
    HandleScope scope;
    return ThrowException(ErrorException(msg));
}

Handle<Value>
encrypt(const Arguments &args)
{
    HandleScope scope;

    if (args.Length() != 2)
        return VException("Two arguments required - <encryption key> and <data>");
    if (!args[0]->IsString())
        return VException("<encryption key> must be a string.");
    if (!Buffer::HasInstance(args[1]))
        return VException("<data> must be a buffer.");

    String::AsciiValue key(args[0]->ToString());
    Local<Object> data_obj = args[1]->ToObject();
    size_t dlen = Buffer::Length(data_obj);

    if (dlen % 8 != 0)
        return VException("<data> length must be multiple of 8.");
 
    unsigned long keybuf[64] = {0};
    deskey((unsigned char *)*key, EN0, keybuf);

    Buffer *retbuf = Buffer::New(dlen);
    unsigned char *ptr = (unsigned char *) Buffer::Data(retbuf);
    memcpy(ptr, Buffer::Data(data_obj), dlen);
 
    for (int j = 0; j < dlen; j += 8)
        des(ptr + j, ptr + j, keybuf);

    return scope.Close(retbuf->handle_);
}

extern "C" void init (Handle<Object> target)
{
    HandleScope scope;
    target->Set(String::New("encrypt"), FunctionTemplate::New(encrypt)->GetFunction());
}

NODE_MODULE(des, init);
