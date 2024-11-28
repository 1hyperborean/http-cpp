#include "send_utils.h"
#include <iostream>
#include <sys/socket.h>

void send_response(int client_fd, const std::string& response) {
    ssize_t bytes_sent = send(client_fd, response.c_str(), response.size(), 0);
    if (bytes_sent < 0) {
        std::cerr << "Failed to send response.\n";
    }
}
