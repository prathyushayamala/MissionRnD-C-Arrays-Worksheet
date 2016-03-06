/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int low = 0, high = len, mid,i,*temp;
	if (Arr==NULL){
		return NULL;
	}
	else{
		if (len <= 0){
			return NULL;
		}
		else{
			mid = (low + high) / 2;
			temp = (int*)malloc((len + 1)*sizeof(int));
			for (i = 0; i < len + 1; i++){
				temp[i] = Arr[i];
			}
			high = len;
			mid = (low + high) / 2;
			if (num < temp[0]){
				for (i = len; i >= 0; i--){
					temp[i] = temp[i - 1];
				}
				temp[0] = num;
			}
			else{
				if (num > temp[len - 1]){
					temp[len] = num;
				}
				else{
					if (num == temp[mid]){
						for (i = mid; i <= len; i++){
							temp[i + 1] = temp[i];
						}
						temp[mid] = num;
					}
					else{
						if (num < temp[mid]){
							i = 0;
							while (num >= temp[i]){
								i++;
							}
							for (int j = len; j >= i; j--){
								temp[j] = temp[j - 1];
							}
							temp[i] = num;
						}
						else{
							if (num > temp[mid]){
								i = mid;
								while (num >= temp[i]){
									i++;
								}
								for (int j = len; j >= i; j--){
									temp[j] = temp[j - 1];
								}
								temp[i] = num;
							}
						}
					}
				}
			}
		}
	}
		return temp;
}