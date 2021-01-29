# https://leetcode.com/problems/valid-palindrome/
import re

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        # 정규식
        s = re.sub('[^a-z0-9]', '', s)

        return s == s[::-1]