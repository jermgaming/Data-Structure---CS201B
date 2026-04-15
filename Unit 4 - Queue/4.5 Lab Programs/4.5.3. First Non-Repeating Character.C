// Type Content here...
#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
    char stream[MAX];
    scanf("%s", stream);

    int freq[26] = {0};   // frequency array
    char queue[MAX];      // queue
    int front = 0, rear = 0;

    int n = strlen(stream);

    for(int i = 0; i < n; i++) {
        char ch = stream[i];

        // Step 1: Update frequency
        freq[ch - 'a']++;

        // Step 2: Push into queue
        queue[rear++] = ch;

        // Step 3: Remove repeating characters from front
        while(front < rear && freq[queue[front] - 'a'] > 1) {
            front++;
        }

        // Step 4: Print result
        if(front < rear)
            printf("%c ", queue[front]);
        else
            printf("-1 ");
    }
	printf("\n");
    return 0;
}