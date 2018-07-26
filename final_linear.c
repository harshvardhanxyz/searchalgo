#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int check(char *found) {

	int j, flag = 0;
	for(j = 0; j < strlen(found); j++) {
		/* check the first char for if the number is negative or not */
		if((j == 0) && ((found[0]) == '-')) {
			/*if the number is negative continue the loop */
			continue;
		}
		/* checks whether the input string is a number or not */
		if(isdigit(found[j]) == 0) {
			/* if not print the following message and set the flag value to 1 */
			printf("invalid!!please try again...\n");
			flag = 1;
			break;
		}
	}
	return flag;
}

int main()  {
	
	/* initialize pointer variable to null */
	char *str = NULL;
	char *key = NULL;
        int i, j, k = 0, n, arr[100], search = 0, flag;

	/* input number of elements */
        printf("enter the no. of elements:");            
        scanf("%d", &n);
	if(n <= 0) {
		printf("error");
		return -1;
	}

	/* dynamically allocate 100 bytes of memory */
        str = (char *)malloc(sizeof(char) * 100);
        if (!str) {
		/* throw an error if malloc fails */						
                printf("Malloc error\n");		
                return -1;				
        }

	key = (char *)malloc(sizeof(char) * 100);
	if (!key) {
		printf("Malloc error\n");
		return -1;
	}

        printf("enter the elements:\n");
	for(i = 0; i < n; i++) {
                printf("enter the %d element:",i+1);
		/* initialize the str with Null */
                memset(str, 0, sizeof(char) * 100);
                scanf("%s", str);
		flag = check(str);
		/* if flag value is 1 re-enter valid no. */
		if(flag == 1) {
			i--;
			k++;
			if(k >= 5) {
				printf("Errror....");
				exit(0);
			}
		} else {
			/* if the string value is number,convert it to integer value */
			arr[i] = atoi(str);
        	}
	}
	/* free the str variable memory and set it to null */
	free(str);
	str = NULL;
	/* input the element to search */
	k = 0;
	do {
		flag = 0;
		printf("enter the element to search:");
		/* initialize the key value to Null */
		memset(key, 0, sizeof(char) * 100);
		scanf("%s", key);
		/* display the key */
		printf("entered key: %s\n", key);
		flag = check(key);
		k++;
	}while((flag != 0) & (k < 5));
	
	if(flag == 1) {
		printf("invalid key\n");
		free(key);
		key = NULL;
		return -1;
	}

	if(flag == 0) {
		search = atoi(key);
	}

        for(i = 0; i < n; i++) {
		/* compare the key element with each element in the array */
		if(arr[i] == search)  {
			/* if key is found in array print its position */
                        printf("key found at position %d\n", i+1);
			break;
		}	
	}
        if(i == n) {
        	/* if key is not found in the array print key not found */
        	printf("key not found\n");
        }
	free(key);
	key = NULL;
	/* returns 0 for succcessful execution of code */
	return 0;
}
