#include <stdio.h>

#include "./cmd/server.h"

int main() {
  Error *err = start_webserver(3000);
  if (err != NULL) {
    err_print_fatal(err);
  }

  return 0;
}
