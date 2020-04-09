typedef char *string;

typedef struct Error {
  int code;
  string msg;
} Error;

Error *err_new(const string msg, int code);
void err_print(const Error *error);
void err_print_fatal(const Error *error);
