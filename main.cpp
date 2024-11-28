#include "socket_utils.h"
#include "bind_utils.h"
#include "listen_utils.h"
#include "accept_utils.h"
#include "recv_utils.h"
#include "send_utils.h"
#include "close_utils.h"
#include <iostream>
#include <netinet/in.h>
#include <cstring>
#include <csignal>
#include <atomic>

const int PORT = 8080;
const int BUFFER_SIZE = 1024;

std::atomic<bool> server_running(true);

void signal_handler(int signum) {
    std::cout << "\nServer shutting down...\n";
    server_running.store(false);
}

int main() {
    signal(SIGINT, signal_handler);

    int server_fd = create_socket();
    if (server_fd == -1) return 1;

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind_socket(server_fd, server_addr) < 0) return 1;

    if (start_listening(server_fd) < 0) return 1;

    std::cout << "Server listening on port " << PORT << "...\n";

    while (server_running.load()) {
        sockaddr_in client_addr{};
        int client_fd = accept_connection(server_fd, client_addr);
        if (client_fd == -1) continue;

        char buffer[BUFFER_SIZE] = {0};
        receive_request(client_fd, buffer, BUFFER_SIZE);
        std::cout << "Request received:\n" << buffer << "\n";

        std::string response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: 13\r\n"
            "\r\n"
            "Hello, World!";
        send_response(client_fd, response);

        close_connection(client_fd);
    }

    close_connection(server_fd);
    return 0;
}
