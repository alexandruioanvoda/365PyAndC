#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int is_palindrome(char s[1000]) {
	int i, flag = 1, len = strlen(s);
	if (len == 1) {
		return (flag);
	}
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
			//printf("*(s) = %s", s);
			//printf("*(s) = %s", *(s+1));
			if (s[0]==s[1]) {
				return s;
			} else {
                g[0] = s[0];
                strcpy(s,g);
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
			//printf("Substring: %s\nIs palindrome: %d\n\n", subst, is_palindrome(subst));

			if (n_max < (j-i+1) && is_palindrome(subst)==1) {
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
    //printf("%d\n", is_palindrome(s));
    //printf("Length of max pal: %d\n", n_max);
    //printf("String max pal: %s\n", max_st);
  	
    if (no_palindrome == 1) {
        g[0] = s[0];
        strcpy(s,g);
		return (s);
    } else {
        strcpy(s,max_st);
        return s;
    }
}

int main() {
	char s[1000] = "zudfweormatjycujjirzjpyrmaxurectxrtqedmmgergwdvjmjtstdhcihacqnothgttgqfywcpgnuvwglvfiuxteopoyizgehkwuvvkqxbnufkcbodlhdmbqyghkojrgokpwdhtdrwmvdegwycecrgjvuexlguayzcammupgeskrvpthrmwqaqsdcgycdupykppiyhwzwcplivjnnvwhqkkxildtyjltklcokcrgqnnwzzeuqioyahqpuskkpbxhvzvqyhlegmoviogzwuiqahiouhnecjwysmtarjjdjqdrkljawzasriouuiqkcwwqsxifbndjmyprdozhwaoibpqrthpcjphgsfbeqrqqoqiqqdicvybzxhklehzzapbvcyleljawowluqgxxwlrymzojshlwkmzwpixgfjljkmwdtjeabgyrpbqyyykmoaqdambpkyyvukalbrzoyoufjqeftniddsfqnilxlplselqatdgjziphvrbokofvuerpsvqmzakbyzxtxvyanvjpfyvyiivqusfrsufjanmfibgrkwtiuoykiavpbqeyfsuteuxxjiyxvlvgmehycdvxdorpepmsinvmyzeqeiikajopqedyopirmhymozernxzaueljjrhcsofwyddkpnvcvzixdjknikyhzmstvbducjcoyoeoaqruuewclzqqqxzpgykrkygxnmlsrjudoaejxkipkgmcoqtxhelvsizgdwdyjwuumazxfstoaxeqqxoqezakdqjwpkrbldpcbbxexquqrznavcrprnydufsidakvrpuzgfisdxreldbqfizngtrilnbqboxwmwienlkmmiuifrvytukcqcpeqdwwucymgvyrektsnfijdcdoawbcwkkjkqwzffnuqituihjaklvthulmcjrhqcyzvekzqlxgddjoir";
	char *ptr = s;
	printf("\nOriginal array of chars: %s, %s\n", ptr, s);
	printf("\nLongest palindrome: %s\n", longestPalindrome(ptr));
	return 0;
}