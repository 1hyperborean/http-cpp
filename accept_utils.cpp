#include "accept_utils.h"
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>

int accept_connection(int server_fd, sockaddr_in& client_addr) {
    socklen_t client_len = sizeof(client_addr);
    int client_fd = accept(server_fd, (sockaddr*)&client_addr, &client_len);
    if (client_fd < 0) {
        std::cerr << "Failed to accept connection.\n";
        return -1;
    }
    return client_fd;
}
