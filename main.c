#include <stdio.h>
#include <dirent.h>
#include <string.h>

int isDigit(char* name){
	int len = strlen(name);
	int i;
	for(i = 0; i < len; i++){
		if(name[i] < '0' || name[i] > '9') return 0;
	}
	return 1;
}

int main(int argc, char* argv[]){
	struct dirent *directory;
	DIR *dp;
	
	char line[256]; //Lines in a file
	char procName[124];//Name of process
	char procStat[124];//Status of process
	char temp[64];
	
	int counter = 0; //Holds how many processes there are
	
	dp = opendir("/proc");
	if(dp == NULL){
		perror("Directory could not be opened!!!");
		return 1;
	}
	while((directory = readdir(dp)) != NULL){
		if(isDigit(directory->d_name)){
			counter++;
			char path[124];
			strcpy(path,"/proc/");

			strcat(path,directory->d_name);
							
			strcat(path,"/status");//Full path of status file which belongs to current process
			FILE* file = fopen(path,"r");
			if(file == NULL){
				perror("File could not be opened!!!");
				return 1;
			} 
			while(fgets(line,sizeof(line),file)){
				sscanf(line,"%s",temp);
				if(strcmp(temp,"Name:") == 0){
					sscanf(line,"%*s %s",procName);
				}
				else if(strcmp(temp,"State:") == 0){
					sscanf(line,"%*s %*s (%[^)])",procStat);
				}
			}
			printf("ID: %-10sName: %-40s\tStatus: %s\n",directory->d_name,procName,procStat);
			fclose(file);
		}
	}
	closedir(dp);
	printf("\nThere are %d processes\n",counter);
	return 0;
}
