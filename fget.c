/*
 * client.c -- TCP Socket Client
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
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int socket_desc;
  struct sockaddr_in server_addr;
  char server_message[2000], client_message[2000];
  int file_fd, bytes_received;


  //validate command
  if (argc != 4){
    printf("Usasge: %s fget GET <source_file> <destination_file>\n ", argv[0]);
    exit(0);
  }
  
  // Clean buffers:
  memset(server_message,'\0',sizeof(server_message));
  memset(client_message,'\0',sizeof(client_message));
  
  // Create socket:
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  
  if(socket_desc < 0){
    printf("Unable to create socket\n");
    return -1;
  }
  
  printf("Socket created successfully\n");
  
  // Set port and IP the same as server-side:
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(2000);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  
  // Send connection request to server:
  if(connect(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
    printf("Unable to connect\n");
    return -1;
  }
  printf("Connected with server successfully\n");

  // Get input from the user:
  if (strcmp(argv[1], "GET") == 0) {
    sprintf(client_message, "GET %s", argv[2]);
    printf("Msg in client: %s\n", client_message);
  } else {
    printf("Error: Unknown command\n");
    return 1;
  }
  
  // Get input from the user:
  // printf("Enter message: ");
  // gets(client_message);
  
  // Send the message to server:
  if(send(socket_desc, client_message, strlen(client_message), 0) < 0){
    printf("Unable to send message\n");
    return -1;
  }
  
  // Receive the server's response:
  if(recv(socket_desc, server_message, sizeof(server_message), 0) < 0){
    printf("Error while receiving server's msg\n");
    return -1;
  }
  
  // Open the local file for writing:
  printf("local_path: %s\n",argv[3]);
  FILE *file =fopen(argv[3],"w");
  if (file == NULL){
    printf("Unable to open file\n");
    return -1;
  }
  fprintf(file, "%s",server_message);
  printf("Server's response saved to %s\n", argv[3]);
  printf("server message:%s\n",server_message);
  // Close the file and the socket:
  fclose(file);
  close(socket_desc);

  return 0;
}
