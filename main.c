#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "wow.h"

char ** parse_args(char * line){
	char  **a;
	a = malloc(100*100*sizeof(char));	
	int i = 0;
	while(line){
		a[i] = strsep(&line," ");
		i++;
	}
	a[i] = NULL;
	return a;
}

int main(){
	printf("type a command\n");
	char command[100] = "ls -a -l";
	char ** comrade;	
	comrade = parse_args(command);
	
	int i = 0;
	
	while(comrade[i]){
		printf("arg[%d] = %s\n",i,comrade[i]);
		i++;
	}
	printf("running arg0 + args\n");
	execvp(comrade[0],comrade);

	return 0;
}
