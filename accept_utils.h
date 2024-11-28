#ifndef ACCEPT_UTILS_H
#define ACCEPT_UTILS_H

#include <sys/socket.h>
#include <netinet/in.h>

int accept_connection(int server_fd, sockaddr_in& client_addr);

#endif
