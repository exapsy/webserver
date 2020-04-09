#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../strings/string.h"
#include "./errors.h"

Error *newError(const string msg, int code) {
  Error *err = malloc(sizeof(Error));
  err->code = code;

  if (!str_ends_with(msg, '\n')) {
    err->msg = str_append(msg, "\n");
  } else {
    err->msg = msg;
  }

  return err;
}

void printError(const Error *error) { fprintf(stderr, error->msg); }
void printFatal(const Error *error) {
  fprintf(stderr, error->msg);
  exit(error->code);
}
