#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct {
	int hour; //user input hour for event
	int min; //user input minute
	char name[100]; //name of event
}event;
//where to print menu
bool check (const event *e){
	return e==NULL;
} //check if event is NULL
event *UIEvent(){
	event *e = (event*) malloc(sizeof(event));
	e->hour=0;
	e->min=0;
	strcpy(e->name,"");
	return e;
} //defining event
//add selection (range)
int range1(const int minimum, const int maximum){
	int input=0;
	int test=0;
	char temp[15];
labelh:scanf("%2d",&input);
       if(input>=minimum||input<=maximum){
       }else{
	       printf("Incorrect input, please try again: ");
	       goto labelh;
       }
       return input;
}
int range2(const int minimum, const int maximum){
	int input=0;
	int test=0;
	char temp[15];
labelm:scanf("%2d",&input);
       if(input>=minimum||input<=maximum){
       }else{
	       printf("Incorrect input, please try again: ");
	       goto labelm;
       }
       return input;
}
event *NewEvent(event *e){
	if(check(e)){
		e=UIEvent();
	}
	system("setterm -bold on");
	printf("\n \n  New  Event  Selected  \n \n");
	system("setterm -bold off");
	printf("Enter hour (0-23): ");
	e->hour=range1(0,23);
	printf("Enter minute (0-59): ");
	e->min=range2(0,59);
	puts("\n     EVENT NAME     \n");
	printf("Please include event name or description: ");
	fgets(e->name,100,stdin);
	fgets(e->name,100,stdin);
	puts(" ----------------------------------");
	system("setterm -bold on");
	puts(" \nEvent Added.");
	system("setterm -bold off");
	return e;
} //initializing event
void AddEvent(event list[],const event e, const int x){
	if(check(&e)){
		return;
	}
	list[x].hour=e.hour;
	list[x].min=e.min;
	strcpy(list[x].name,e.name);
}//adding events to a list
//sorting the order of time of the events in a day
void sort (event list[],const int size){
	int x,y,storeh2,storem2;//store h for hour, m for min, 1 and 2, depend on arr
	char name2[100];
	for (x=1;x<size;x++){
		for(y=x;y>0&&(list[y-1].hour>list[y].hour)||
				(list[y-1].hour==list[y].hour)&&(list[y-1].min>list[y].min);y--){
			storeh2=list[y-1].hour;
			storem2=list[y-1].min;
			strcpy(name2,list[y-1].name);
			//event 2 ^
			list[y-1].hour=list[y].hour;
			list[y-1].min=list[y].min;
			strcpy(list[y-1].name,list[y].name);
			//switch the two around using the temporary storage
			list[y].hour=storeh2;
			list[y].min=storem2;
			strcpy(list[y].name,name2);
		}
	}
}
void CorrectSort (event list[], int *size, event e){
	AddEvent(list,e,*size);
	(*size)++;
	sort(list,*size);
}
void printEvent(const event e){ //<---printevent sourced by: stackexchange.com
	char hour1 = {(e.hour/10)+ '0'};//first digit
	char hour2 = {(e.hour-(e.hour/10)*10)+'0'};
	char min1 = {(e.min/10)+'0'};
	char min2 = {(e.min-(e.min/10)*10)+'0'};
	printf("%c%c:%c%c  ~%s\n",hour1,hour2,min1,min2,e.name);
}
void printList(const event list[],const int size){
	if(size==0){
		puts("\n You have no events scheduled. \n");
	}
	system("setterm -bold on");
	printf("\n Schedule: \n");
	system("setterm -bold off");
	for(int x=0;x<size;x++){
		printf(" [%d]  ",x);
		printEvent(list[x]);
	}
}
void deleteEvent(event list[],int *size){
	int x;
	if(*size==0){
		puts("\n You have no events to delete. \n");
		return;
	}
	char temp[100];
	int locate;
	system("setterm -bold on");
	printf("\n    DELETE EVENT   \n");
	system("setterm -bold off");
	printf("\n Enter event number you want to delete: ");
	fgets(temp,100,stdin);
	fgets(temp,100,stdin);
	strtok(temp,"\n");
	locate = atoi(temp);
	//locate=locate-y;
	if(locate>*size-1){
		printf(" \n No event found \n");
		return;
	}
	list[locate].hour=70;
	list[locate].min=70;
	strcpy(list[locate].name,"");
	sort(list,*size);
	(*size)--;
}