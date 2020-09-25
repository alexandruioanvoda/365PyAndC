# Very naive, possibly very expensive solution.
class Solution:
    def longestPalindrome(self, s: str) -> str:
        def is_palindrome(string):
            return(string == string[::-1])
        def all_substrings(string):
            return([string[i: j] for i in range(len(string)) for j in range(i + 1, len(string) + 1)])
        def all_substring_palindromes(string):
            pal = []
            for i in all_substrings(string):
                if is_palindrome(i):
                    pal.append(i)
            return(pal)
        pal = all_substring_palindromes(s)
        if len(pal) == 0:
            return ""
        else:
            return(max(pal, key = len))