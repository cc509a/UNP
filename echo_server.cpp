/*************************************************************************
	> File Name: echo_server.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  3/23 20:45:36 2016
 ************************************************************************/

#include <iostream>
#include <sys/socket.h>
#include <cstdio.h>
#include <cstdlib.h>



int mian(int argc,char* argv[])
{
  if(argc != 2)
  {
    printf("Usage: %s<port>\n",argv[0]);
    exit(0);
  }
  int serv_sock,clnt_sock;
  char message[1024];
  int str_len,i;
}
