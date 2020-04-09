typedef enum bool {
  false,
  true,
} bool;

typedef char *string;

bool str_ends_with(const string str, char c);
char str_last_char(const string str);
string str_append(const string str, const string adder);
string str_new(size_t size);
