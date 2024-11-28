#include "close_utils.h"
#include <unistd.h>

void close_connection(int client_fd) {
    close(client_fd);
}
