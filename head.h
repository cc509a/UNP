/*************************************************************************
	> File Name: echo_client.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  3/30 22:51:49 2016
 ************************************************************************/
#ifndef my_head
#define my_head

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>


static const int BUF_SIZE = 1024;

void error_handling(char* message)
{
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}

#endif
