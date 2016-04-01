/*************************************************************************
	> File Name: echo_server.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  3/23 20:45:36 2016
 ************************************************************************/
#include "head.h"

int main(int argc, char* argv[])
{
  //socket fd
  int serv_sock;
  int clnt_sock;
  
  //address
  struct sockaddr_in serv_adr;
  struct sockaddr_in clnt_adr;  
  socklen_t clnt_adr_sz;  
  //other
  char message[BUF_SIZE];
  int str_len; 
  
  if(argc != 2)
  {
    printf("Usage: %s<port>\n",argv[0]);
    exit(1);
  }
  
  serv_sock = socket(PF_INET, SOCK_STREAM, 0);

  if(serv_sock == -1)
  {
    error_handling("socket error");
  }
  
  memset(&serv_adr, 0, sizeof(serv_adr));
  serv_adr.sin_family = AF_INET;
  serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_adr.sin_port = htons(atoi(argv[1]));
  //bind 
  if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
  {
    error_handling("bind error");     
  }
  //listen
  if (listen(serv_sock,5) == -1)
  {
    error_handling("listen error");
  }
  
  clnt_adr_sz = sizeof(clnt_adr);
  
  for(int i = 0; i < 5; i++)
  {
   //accpet  
   clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &clnt_adr_sz); 
    
    if(clnt_sock == -1)
    {
      error_handling("accept error");
    }
    else
    {
     
      printf("Connected client : %d\n", i+1);
    }
    while((str_len = read(clnt_sock, message, BUF_SIZE)) != 0)
    {
      write(clnt_sock, message, str_len);
    }
    close(clnt_sock);
  }
    
 close(serv_sock);
 return 0;
}
