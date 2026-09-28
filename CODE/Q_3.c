#include <string.h>
#include <stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char* s) {
    int left = 0;
    int maxLength = 0;
    int n = strlen(s);
    
    // Acts as unordered_set<char> for ASCII characters
    bool charSet[256] = {false};

    for (int right = 0; right < n; right++) {
        unsigned char rc = (unsigned char)s[right];
        
        while (charSet[rc]) {
            unsigned char lc = (unsigned char)s[left];
            charSet[lc] = false;
            left++;
        }

        charSet[rc] = true;
        maxLength = MAX(maxLength, right - left + 1);
    }

    return maxLength;
}