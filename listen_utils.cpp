#include "listen_utils.h"
#include <iostream>

int start_listening(int server_fd) {
    if (listen(server_fd, 5) < 0) {
        std::cerr << "Listen failed.\n";
        return -1;
    }
    return 0;
}
