#include"comm.h"
int main()
{
	//printf("this is msg_ser!\n");
	int msg_id = msg_create();//ser
	if(msg_id < 0)
		return 1;

	printf("ID:> %d\t\n\n",msg_id);

	char buf[G_SIZE];
	while(1)
	{
		buf[G_SIZE-1]='\0';
		int ret =msg_recv(msg_id,buf,\
				sizeof(buf)-1,DATA_TYPE_CLI);
		printf("cli:>%s\n",buf);
		fflush(stdout);

		memset(buf,'\0',sizeof(buf));

		printf("Please Input:\n ");
		char *ar = fgets(buf,sizeof(buf)-1,stdin);
		if(strncasecmp(ar,"quit",4) == 0)
			break;
		ret = msg_send(msg_id,buf,DATA_TYPE_SER);
	}

	 msg_destroy(msg_id);
//	sleep(10);
//	int ret =  msg_destroy(msg_id);
//	printf("destroy code is:> %d\n",ret);
	return 0;
}
