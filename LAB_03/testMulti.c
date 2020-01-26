#include "multiQ.h"
// #include<stdio.h>
// #include<stdlib.h>
//MultiQ loadData(File f) - reads from f a list of pairs (task_id, priority) and adds each
// item to a MultiQ appropriately.

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
	printf("%s\n", "___________Successfully loaded data!____________");
	for(int i=0;i<10;i++)
	{
			printf("  mq[%d] :::: length:%d :::: priority:%d  \n",i,lengthQ(mq[i]),mq[i]->p);
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
	if(argc < 2)
	{
		printf("\nenter filename and number of deletions!\n");
	return -1;
	}
	FILE* fptr=fopen(argv[1],"r");
	MultiQ mq=loadData(fptr);
	printf("\n======== sizeMQ returns :%d ============",sizeMQ(mq));
	// printf("\n======== sizeMQbyPriority(10): %d ===========\n",sizeMQbyPriority(mq,10));

	mq=testDel(mq,atoi(argv[2]));

	for(int i=0;i<10;i++)
	{
			if(mq[i]->p==-1)
			continue;
			printf("  mq[%d] :::: length:%d :::: priority:%d  \n",i,lengthQ(mq[i]),mq[i]->p);
	}
	printf("\n======== sizeMQ returns :%d ============\n",sizeMQ(mq));
	// printf("\n======== sizeMQbyPriority(10): %d ===========\n",sizeMQbyPriority(mq,10));
}//end of main
