/*
 * server.c -- TCP Socket Server
 * 
 * adapted from: 
 *   https://www.educative.io/answers/how-to-implement-tcp-sockets-in-c
 */

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
  int socket_desc, client_sock;
  socklen_t client_size;
  struct sockaddr_in server_addr, client_addr;
  char server_message[8196], client_message[8196],file_path[8196],file_contents[8196];
  int fd, nread;
  
  // Clean buffers:
  memset(server_message, '\0', sizeof(server_message));
  memset(client_message, '\0', sizeof(client_message));
  memset(file_path, '\0', sizeof(file_path));
  memset(file_contents, '\0', sizeof(file_contents));
  
  // Create socket:
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  
  if(socket_desc < 0){
    printf("Error while creating socket\n");
    return -1;
  }
  printf("Socket created successfully\n");
  
  // Set port and IP:
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(2000);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  
  // Bind to the set port and IP:
  if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr))<0){
    printf("Couldn't bind to the port\n");
    return -1;
  }
  printf("Done with binding\n");
  
  // Listen for clients:
  if(listen(socket_desc, 1) < 0){
    printf("Error while listening\n");
    return -1;
  }
  printf("\nListening for incoming connections.....\n");
  
  // Accept an incoming connection:
  client_size = sizeof(client_addr);
  client_sock = accept(socket_desc, (struct sockaddr*)&client_addr, &client_size);
  
  if (client_sock < 0){
    printf("Can't accept\n");
    return -1;
  }
  printf("Client connected at IP: %s and port: %i\n", 
         inet_ntoa(client_addr.sin_addr), 
         ntohs(client_addr.sin_port));
  
  // Receive client's message:
  if (recv(client_sock, client_message, 
           sizeof(client_message), 0) < 0){
    printf("Couldn't receive\n");
    return -1;
  }
  printf("Msg from client: %s\n", client_message);
  
  // Extract file path from the client message:
  sscanf(client_message, "GET %[^\n]s", file_path);
  printf("file_path: %s\n", file_path);

  // Open the file and read its contents:
  fd = open(file_path, O_RDONLY);
  if (fd < 0) {
    printf("Can't open file\n");
    return -1;
  }

  
  nread = read(fd, file_contents, sizeof(file_contents));
  if (nread < 0) {
    printf("Can't read file\n");
    close(fd);
    return -1;
  }

  // Send file contents to the client:
  if (send(client_sock, file_contents, strlen(file_contents), 0) < 0){
    printf("Can't send\n");
    close(fd);
    return -1;
  }

  // Closing the socket:
  close(client_sock);
  close(socket_desc);

  return 0;
}