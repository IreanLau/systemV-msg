
#include"comm.h"
int main()
{
	int msg_id = msg_get();//cli
	if(msg_id < 0)
		return 1;

	char buf[G_SIZE];
	while(1)
	{
		memset(buf,'\0',sizeof(buf));
		printf("Please Input\n: ");
		fflush(stdout);

		char *ar = fgets(buf,sizeof(buf)-1,stdin);
		if(strncasecmp(ar,"quit",4) == 0)
			break;
		msg_send(msg_id,buf,DATA_TYPE_CLI);

		int ret =msg_recv(msg_id,buf,\
 				sizeof(buf)-1,DATA_TYPE_SER);
		printf("ser:>%s\n",buf);
		fflush(stdout);

		memset(buf,'\0',sizeof(buf));
	}

//	sleep(10);
//	int ret =  msg_destroy(msg_id);
//	printf("destroy code is:> %d\n",ret);
	return 0;
}
