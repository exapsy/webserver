#include <stdio.h>

#include "./cmd/server.h"

int main() {
  Error *err = startWebserver(3000);
  if (err != NULL) {
    printFatal(err);
  }

  return 0;
}
