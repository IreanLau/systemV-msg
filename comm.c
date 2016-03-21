#include"comm.h"

static msg_create_and_get(int flag)//ser
{
	key_t _key=ftok(_PATH_,_PROJ_ID_);//全局唯一标识 消息队列资源

	if(_key < 0)
	{
		perror("ftok");
		return -1;
	}
	//if no c, else failed
	//int msg_id = msgget(key,IPC_CREAT | IPC_EXCL);
	int msg_id = msgget(_key,flag);
	if(msg_id<0)
	{
		perror("msgget");
		return -2;
	}
	return msg_id;
}

int msg_create()
{
	int flag=IPC_CREAT | IPC_EXCL ;//保证返回新的IPC资源
	return msg_create_and_get(flag | 0666);
}

int msg_get()//cli
{
	int flag=IPC_CREAT;
	return msg_create_and_get(flag);
}

int msg_send(int msg_id,char *msg/*,int len*/,long mtype)
{
   msgbuf_t msg_buf;
   msg_buf.mtype = mtype;
   memset(msg_buf.mtext,'\0',sizeof(msg_buf.mtext));
   strncpy(msg_buf.mtext,msg, \
		   strlen(msg)>G_SIZE ? G_SIZE-1 : strlen(msg) );

  return msgsnd(msg_id,&msg_buf,sizeof(msg_buf.mtext),0); 
}

int msg_recv(int msg_id,char* out_msg,int out_len,long mtype)
{
   msgbuf_t msg_buf;
   memset(msg_buf.mtext,'\0',sizeof(msg_buf.mtext));

   int ret = msgrcv(msg_id,&msg_buf,\
		   sizeof(msg_buf.mtext),mtype,0);//0 表示默认阻塞方式

   if(ret > 0)//success
   {
	   strncpy(out_msg,msg_buf.mtext,\
			   strlen(msg_buf.mtext) > out_len ? out_len-1 : strlen(msg_buf.mtext));
   }
	return 0;
}

int msg_destroy(int msg_id)
{
	int ret = msgctl(msg_id,IPC_RMID,NULL);
	if(ret < 0 )
	{
		perror("msgctl");
	}
	return ret;
}
