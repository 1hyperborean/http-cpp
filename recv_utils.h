#ifndef RECV_UTILS_H
#define RECV_UTILS_H

#include <sys/socket.h>

void receive_request(int client_fd, char* buffer, int buffer_size);

#endif
