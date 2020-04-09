#include <stdio.h>

#include "./server.h"

Error *startWebserver(int port) {
  printf("Listening on port %d ...\n", port);

  return newError("haha", 1);

  while (1)
    ;

  return NULL;
}
