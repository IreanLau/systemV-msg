#ifndef _COMM_
#define _COMM_

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<errno.h>
#include<string.h>

#define _PATH_ "/tmp/.msg"
#define _PROJ_ID_ 0x6666

#define G_SIZE 128
#define DATA_TYPE_SER 1
#define DATA_TYPE_CLI 2
typedef struct {
	long mtype;
	char mtext[G_SIZE];
}msgbuf_t;

int msg_create();//ser
int msg_get();//cli
int msg_send(int ,char *,long);
int msg_recv(int ,char*,int,long);
int msg_destroy(int);



#endif
