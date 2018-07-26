
#include  <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int check(char *found) {
	int i, flag = 0;
	for(i = 0; i < strlen(found); i++) {
		if((i == 0) && ((found[0]) == '-')) {
			continue;
		}
		if(isdigit(found[i]) == 0) {
			printf("invalid!please try again_foo\n");
			flag = 1;
			break;
		}
	}
	return flag;
}
int main()  {
	
	int arr[100], i, k = 0, n, mid, key = 0, high, low, flag = 0;
	char *str = NULL;
	char *search = NULL;

	str = (char *)malloc(sizeof(char) * 100);
	if(!str) {
		printf("Malloc error\n");
		return -1;
	}
	
	search = (char *)malloc(sizeof(char) * 100);
	if(!search) {
		printf("Malloc error\n");
		return -1;
	}
	printf("enter the no of elements");
	scanf("%d",&n);
	if(n <= 0) {
		printf("error0\n");
		exit(0);
	}
	
	printf("Enter the elements in ascending order:\n");
	for(i = 0; i < n; i++) {
		printf("enter element %d:",i+1);
		memset(str, 0, sizeof(char) * 100);
		scanf("%s", str);
		flag = check(str);
		if(flag == 1) {
			i--;
			k++;
			if(k >= 5) {
				printf("error1..");
				exit(0);
			}
		} else {
			arr[i] = atoi(str);
		}
	}
	free(str);
	str = NULL;
	flag = 0;
	k = 0;
	
	do {
		printf("enter the key element:\n");
		memset(search, 0, sizeof(char) * 100);
		scanf("%s", search);
		flag = check(search);
		printf("entered key : %s\n",search);
		k++;
	}while((flag != 0) & (k < 5));
	
	if(flag == 1) {
		printf("error2..\n");
		free(search);
		search = NULL;
		exit(0);
	}

	if(flag == 0) {
		key = atoi(search);
	}

	high = n-1;
	low = 0;
	mid = (high + low) / 2;

	while(low <= high)  {

                if(arr[mid] < key) {
                        low = mid + 1;
		} else if(arr[mid] == key) {
			printf("key found at position %d\n",mid+1);
			break;
		} else {
			high = mid - 1;
		}
		mid = (high+low) / 2;
	}
	
	if(low > high) {
		printf("key not found!!");
		exit(0);
	}
	free(search);
	search = NULL;
	return 0;
}
