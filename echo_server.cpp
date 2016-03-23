/*************************************************************************
	> File Name: echo_server.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  3/23 20:45:36 2016
 ************************************************************************/

#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/un.h>
#include <cstring>
#include <arpa/inet.h>

void error_handling(const char* str)
{
  printf(str);
}


bool  Serve( int client_socket  )
{
  while(true)
  {
    int length;
    char* msg;
    if(read(client_socket, &length, sizeof(length))==0) 
    {
      return true;
    }
    msg = new char [length];

    read(client_socket, msg, length);
    
  }

}


int mian(int argc,char* argv[])
{
  if(argc != 2)
  {
    printf("Usage: %s<port>\n",argv[0]);
    exit(0);
  }
  char message[1024];
  int str_len,i;

  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));  
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htonl(atoi(argv[1]));
  int socket_fd = socket(PF_INET, SOCK_STREAM,0);
 
  if(bind(socket_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1)
  {
    error_handling("bind error");     
  }
  listen(socket_fd, 5);


}
