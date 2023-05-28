// Client side C/C++ program to demonstrate Socket
// programming
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 12345

int main(int argc, char const *argv[]) {
  const char *host = "127.0.0.1";
  int port = PORT;

  // assume first arg = host, second arg = port
  if (argc > 1) {
    host = argv[1];
  }

  if (argc > 2) {
    port = atoi(argv[2]);
  }

  printf("... connecting to %s:%d ...\n", host, port);
  int sock = 0, valread, client_fd;
  struct sockaddr_in serv_addr;
  // char* hello = "Hello from client";
  char buffer[1024] = {0};
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("\n Socket creation error \n");
    return -1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);

  // Convert IPv4 and IPv6 addresses from text to binary
  if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
    printf("\nInvalid address/ Address not supported \n");
    return -1;
  }

  if ((client_fd = connect(sock, (struct sockaddr *)&serv_addr,
                           sizeof(serv_addr))) < 0) {
    printf("\nConnection Failed \n");
    return -1;
  }

  for (uint8_t i = 0; i < 5; ++i) {
    uint8_t bb = i + 3;
    send(sock, &bb, sizeof(bb), 0);
    printf("byte message sent\n");
    // valread = read(sock, buffer, 1024);
    // printf("%s\n", buffer);
    // sleep(1);
  }

  // closing the connected socket
  close(client_fd);
  return 0;
}
