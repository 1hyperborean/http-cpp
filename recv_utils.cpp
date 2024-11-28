#include "recv_utils.h"
#include <iostream>
#include <unistd.h>

void receive_request(int client_fd, char* buffer, int buffer_size) {
    ssize_t bytes_read = read(client_fd, buffer, buffer_size);
    if (bytes_read < 0) {
        std::cerr << "Failed to read request.\n";
    } else {
        buffer[bytes_read] = '\0';
    }
}
