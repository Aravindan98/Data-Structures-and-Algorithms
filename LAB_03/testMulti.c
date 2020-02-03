#include "multiQ.h"
#include<sys/time.h>
MultiQ loadData(FILE* fptr)
{
	Task t;
	MultiQ mq=NULL;
	if(fptr==NULL)
	{
		printf("\n________File could not be opened!_______\n");
		exit(1);
	}
	else
	{
		printf("\n*****************File opened successfully!**********\n");
		mq=createMQ(10);
		printf("\n\n++++++++++ MultiQ created! ++++++++++\n               ========== READING =========\n");

	while(1)
	{
		if(feof(fptr))
		{
			break;
		}
		t=(Task)malloc(sizeof(struct task));
		fscanf(fptr,"%d%*c%d",&(t->tid),&(t->p));
		// printf("\n_________ Taskid:%d ___________ Priority:%d _______\n",t->tid,t->p);
		mq=addMQ(mq,t);
		// printf(" sizeMQ %d\n",sizeMQ(mq));
	}
	printf("%s\n =============== LOADED DATA ===============\n", "___________Successfully loaded data!____________");
	for(int i=0;i<10;i++)
	{
			printf("\n  mq[%d] :::: length:%d :::: priority:%d  \n",i,lengthQ(mq[i]),mq[i]->p);
	}
	fclose(fptr);
return mq;
}
};

MultiQ testDel(MultiQ mq,int num) // – performs num of delNextMQ operations.
{
		for(int i=0;i<num;i++)
			{
				mq=delNextMQ(mq);
			}
return mq;
};

int main(int argc,char* argv[])
{
	struct timeval t1_load,t2_load,t1_del,t2_del;
	double elapsed_time;
	if(argc < 2)
	{
	printf("\n Enter filename and number of deletions on command line!\n");
	return -1;
	}
	FILE* fptr=fopen(argv[1],"r");

	gettimeofday(&t1_load,NULL);
	MultiQ mq=loadData(fptr);
	gettimeofday(&t2_load,NULL);
	elapsed_time=(t2_load.tv_sec-t1_load.tv_sec)*1000.0;
	elapsed_time+=(t2_load.tv_usec-t1_load.tv_usec)/1000.0;
	printf("\n------------------------------------\n");
	printf("     Time for Loading:%f ms\n",elapsed_time);
	printf("\n\n");

	elapsed_time=0.0;
	// printf("\n======== sizeMQ returns :%d ============",sizeMQ(mq));
	// printf("\n======== sizeMQbyPriority(10): %d ===========\n",sizeMQbyPriority(mq,10));

	gettimeofday(&t1_del,NULL);
	mq=testDel(mq,atoi(argv[2]));
	gettimeofday(&t2_del,NULL);
	elapsed_time=(t2_del.tv_sec-t1_del.tv_sec)*1000.0;
	elapsed_time+=(t2_del.tv_usec-t1_del.tv_usec)/1000.0;
	printf("\n------------------------------------\n");
	printf("     Time for Deleting: %f ms\n",elapsed_time);
	printf("\n\n");

	printf("\n%s\n","######### MultiQ post deletions ############" );
	for(int i=0;i<10;i++)
	{
			if(mq[i]->p==-1)
				continue;
			printf("\n  mq[%d] :::: length:%d :::: priority:%d  \n",i,lengthQ(mq[i]),mq[i]->p);
	}
	// printf("\n======== sizeMQ returns :%d ============\n",sizeMQ(mq));
	// printf("\n======== sizeMQbyPriority(10): %d ===========\n",sizeMQbyPriority(mq,10));
}//end of main
