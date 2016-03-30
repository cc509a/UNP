/*************************************************************************
	> File Name: echo_server.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  3/23 20:45:36 2016
 ************************************************************************/

#include "head.h"

/*
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
    std::cout << msg << std::endl;
    if (!strcmp( msg, "quit" )) 
    {
      delete msg, msg = nullptr; 
      return false;
    }
    else
    {
      delete [] msg, msg =nullptr;
    }
  }

}
*/

int main(int argc,char* argv[])
{
  if(argc != 2)
  {
    printf("Usage: %s<port>\n",argv[0]);
    exit(1);
  }
  char message[BUF_SIZE];
  int str_len;
  int serv_sock,clnt_sock;
  struct sockaddr_in serv_adr, clnt_adr;
  
  serv_sock = socket(PF_INET, SOCK_STREAM, 0);
  if(serv_sock == -1)
  {
    error_handling("socket error");
  }
  std::cout<<"scokt"<<std::endl;
  memset(&serv_adr, 0, sizeof(serv_adr));  
  serv_adr.sin_family = AF_INET;
  serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_adr.sin_port = htonl(atoi(argv[1]));
 
  if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
  {
    error_handling("bind error");     
  }
  std::cout<<"bind"<<std::endl;
  if (listen(serv_sock,5) == -1)
  {
    error_handling("listen error");
  }
  std::cout<<"listen"<<std::endl;
  socklen_t clnt_adr_sz = sizeof(clnt_adr);

  std::cout<<"begin"<<std::endl;
  for(int i = 0; i < 5; ++i)
  {
    std::cout<<i<<std::endl;
   clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &clnt_adr_sz); 
    
    if(clnt_sock == -1)
    {
      error_handling("accept error");
    }
    else
    {
      std::cout<<"connected client" << i+1 <<std::endl;
    }
    while((str_len = read(clnt_sock, message, BUF_SIZE))!=0)
    {
      write(clnt_sock, message, str_len);
    }
    close(clnt_sock);
  }
close(serv_sock);
  return 0;

}
