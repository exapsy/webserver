#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include "./server.h"

#define BUFFER_LENGTH 1024

Error *start_webserver(uint port) {
  /* Create the socket */
  int sockfd = socket(PF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    return err_new("Couldn't create new socket", 1);
  }

  /* Attach port to socket */
  int opt = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                 sizeof(opt))) {
    return err_new("Couldn't set socket opt", 2);
  }
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);

  if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    return err_new("Couldn't bind socket", 3);
  }
  if (listen(sockfd, 3) < 0) {
    return err_new("Couldn't listen", 4);
  }

  printf("Listening on port %d ...\n", port);

  /* Accepting connections */
  while (1) {
    int new_socket;
    if ((new_socket = accept(sockfd, (struct sockaddr *)&address,
                             (socklen_t *)&addrlen)) < 0) {
      return err_new("Couldn't accept", 5);
    }

    const size_t buffLen = 1024;
    char buffer[BUFFER_LENGTH] = {0};
    int valread = read(new_socket, buffer, BUFFER_LENGTH);
    printf("%s\n", buffer);

    string httpResponse = "HTTP/1.1 200 OK\n\n\
    Hello World!";
    send(new_socket, httpResponse, strlen(httpResponse), 0);
    printf("Hello message sent\n");
    close(new_socket);
  }

  return NULL;
}
