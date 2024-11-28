#include "bind_utils.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

int bind_socket(int server_fd, const sockaddr_in& server_addr) {
    if (bind(server_fd, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Bind failed.\n";
        return -1;
    }
    return 0;
}
