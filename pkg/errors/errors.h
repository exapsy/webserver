typedef char *string;

typedef struct Error {
  int code;
  string msg;
} Error;

Error *newError(const string msg, int code);
void printError(const Error *error);
void printFatal(const Error *error);
