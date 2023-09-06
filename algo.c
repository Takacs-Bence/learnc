#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * params:
 * int n - length of the array
 * int m - number of operations to execute on 'ops' 
 *
 * input
 * -------------
 * -------------
 * 10 3
 * -------------
 * 1  5  3
 * 4  8  7
 * 6  9  1
 * ------------
 * output: 10
 * 
 * while the final array would contain
 * [ 3 0 0 7 0 -2 0 0 -7 -1 ]
 * 
 */
void max_sum(int n, int m, int ops[3][3]);

int main(int count, char* args[])
{
	// length of the arr
	int n = 10;
	// number of operations
	int m = 3;
	int ops[3][3] = {{1,5,3}, {4,8,7}, {6,9,1}};

	char *path = "./arr.txt";
	FILE *stream = fopen(path, "r");
	if (stream == NULL) {
		printf("could not open file at path %s\n", path);	
		return 1;
	}			

	int c = 0;
	char *s;

	while(1) {
		int cc = 7;
		if (c == 0) {
			cc = 6;
		} 
		c++;

		char line[cc];

		s = fgets(line, cc, stream);
		if (s == NULL) {
			break;		
		}		
		//printf("read line: %s\n", line);
		
	}

	fclose(stream);

	max_sum(n, m, ops);

	return 0;

}

void  max_sum(int n, int m, int ops[3][3])
{
	long ret = 0;
	int arr[10] = {};
	memset((void *) arr, 0, 10);

	for (int i = 0; i < m; i++) {
		int* op = ops[i];

		int *st = &op[0];
		printf("%d\t", *st);
		int *en = &op[1];
		printf("%d\t", *en);
		int *ad = &op[2];
		printf("%d\n", *ad);

		arr[*st - 1] = arr[*st - 1] + *ad;
		arr[*en] = arr[*en] + (-1 * *ad);
	}

	//printf("[ ");

	int *val = &arr[0];
	size_t i = 0;
	while (i < n) {
	    //printf("%d ", *val);

		long sum = ret + *val;
		if (sum > ret) {
			ret = sum;
		}
		val++;
		i++;
	}

	//printf("]\n");
	printf("the largest sum at any position was %ld\n", ret);
}
