#ifndef BIND_UTILS_H
#define BIND_UTILS_H

#include <netinet/in.h>

int bind_socket(int server_fd, const sockaddr_in& server_addr);

#endif
