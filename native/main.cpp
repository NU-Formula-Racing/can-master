#include <iostream>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <httplib/httplib.h>

using namespace httplib;

const char *HOST = "localhost";
const int PORT = 1234;

int main(void) {
    Server svr;

    svr.Get("/hi", [](const Request & /*req*/, Response &res) {
        printf("Hello World!\n");
        res.set_content("Hello World!", "text/plain");
    });

    svr.listen(HOST, PORT);
}
