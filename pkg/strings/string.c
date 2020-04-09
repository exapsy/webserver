#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./string.h"

const size_t STR_SIZE = sizeof(string);

bool str_ends_with(const string str, char c) {
  size_t len = strlen(str);
  if (len <= 0) {
    return false;
  }

  char lastChar = str_last_char(str);

  return lastChar == c;
}

char str_last_char(const string str) {
  size_t len = strlen(str);
  if (len <= 0) {
    return 0;
  }
  return str[len - 1];
}

string str_append(const string str, const string adder) {
  string s = str_new(strlen(str) + strlen(adder));
  strcpy(s, str);
  return strcat(s, adder);
}

string str_new(size_t size) { return malloc(size * STR_SIZE); }
