#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void setfl(int* f, int* l, int value){
	if(*f==-1) *f = *l = value;
	else *l = value;
}

int main(void) {
	const char* fname = "input.txt";

	FILE* fp = fopen(fname, "r");
	if(!fp) {
		perror("file openning failed");
		return EXIT_FAILURE;
	}
	int sum = 0;
	char buf[128];
	const char* digits[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	while(fgets(buf, sizeof buf, fp) != NULL){
		int* f = malloc(sizeof(int)), *l = malloc(sizeof(int));
		*f = -1;
		for(int i = 0; buf[i] != '\n' && i < sizeof(buf); i++)
			if(isdigit(buf[i])){
				setfl(f, l, buf[i]-'0');
			} else {
				for(int j = 0; j < 9; j++){
					if(!strncmp(buf+i, digits[j], strlen(digits[j]))){
						setfl(f, l, j+1);
						break;
					}
                }
			}
		sum += *f*10 + *l;
        free(f); free(l);
	}
	fclose(fp);
	printf("%d\n", sum);
	return EXIT_SUCCESS;
}
