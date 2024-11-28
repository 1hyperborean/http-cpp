#ifndef SEND_UTILS_H
#define SEND_UTILS_H

#include <sys/socket.h>
#include <string>

void send_response(int client_fd, const std::string& response);

#endif
