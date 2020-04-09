#include <stdio.h>
#include <stdlib.h>

#include "./cmd/server.h"

int main(int argc, char **argv) {
  int port;
  if (argc == 1) {
    port = 3000;
  } else if (argc >= 2) {
    string port_str = argv[1];
    port = atoi(port_str);
  }
  Error *err = start_webserver(port);
  if (err != NULL) {
    err_print_fatal(err);
  }

  return 0;
}
