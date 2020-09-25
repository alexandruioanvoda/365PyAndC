#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int is_palindrome(char s[1000]) {
	int i, flag = 1, len = strlen(s);
	for (i = 0; i < len; i++) {
		if (s[i] != s[len-i-1]) {
			flag = 0;
            break;
        }
    }
    return (flag);
}

char * longestPalindrome(char * s) {
	int n = strlen(s); char g[1000];
	if (n == 1) {
		return s;
	} else {
		if (n == 2) {
			if (s[0]==s[1]) {
				printf("Basecase 2-len palindrome.\n");
				return s;
			} else {
				printf("Basecase 2-len non-palindrome.\n");
				return s;
			}
		}
	}
	char max_st[1000], subst[1000];
	max_st[0] = s[0];
	int subst_idx, n_max = 1, no_palindrome = 1;
	
	// Print all substrings here
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			if (j == i) {
				continue;
			}
			memset(subst, 0, sizeof subst);
			subst_idx = 0;

			for (int k = i; k <= j; k++) {
				subst[subst_idx] = s[k];
				subst_idx++;
			}

			if (n_max < (j-i+1) && is_palindrome(subst)==1) {
				// Then the substring between i and j is a palindrome that's larger than the largest we've seen so far.
				no_palindrome = 0;
                n_max = j-i+1;
				memset(max_st, 0, sizeof max_st);
				subst_idx = 0;
				for (int k = i; k <= j; k++) {
					max_st[subst_idx] = s[k];
					subst_idx++;
				}
			}
		}
	}
	char * to_return = max_st;
	return to_return;
}

int main() {
	char s[1000] = "babad";
	char * ptr = s;
	printf("\nOriginal array of chars: %s, %s\n", ptr, s);
	printf("\nLongest palindrome: %s\n", longestPalindrome(ptr));
	return 0;
}