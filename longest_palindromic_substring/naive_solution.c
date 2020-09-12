#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int is_palindrome(char st[5]) {
	int i, flag = 1, len = strlen(st);
	for (i = 0; i < len; i++) {
		if (st[i] != st[len-i-1]) {
			flag = 0;
            break;
        }
    }
    return(flag);
}

int main()
{
	char st[1000], max_st[1000];
	int subst_idx;
	scanf("%s", st);
	max_st[0]=st[0];
	int n_max = 1;

	// Print all substrings here
	int n = strlen(st);
	printf("Length of the string is: %d\n", n);
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			char subst[1000] = {0};
			int subst_idx = 0;
			for(int k = i; k <= j; k++) {
				subst[subst_idx] = st[k];
				subst_idx++;
			}
			printf("Substring: %s\nIs palindrome: %d\n\n", subst, is_palindrome(subst));

			if (is_palindrome(subst)==1 && n_max < (j-i+1)) {
				n_max = j-i+1;
				char max_st[1000] = {0};
				int subst_idx = 0;
				for (int k = i; k <= j; k++) {
					max_st[subst_idx] = st[k];
					subst_idx++;
				}
			}
		}
	}

    printf("%d\n", is_palindrome(st));
    printf("Length of max pal: %d\n", n_max);
    printf("String max pal: %s\n", max_st);
    return(0);
}