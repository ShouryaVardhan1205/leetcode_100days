#include <stdio.h>

int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};

    // Count frequency of each task
    for(int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    // Find maximum frequency
    int maxFreq = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] > maxFreq)
            maxFreq = freq[i];
    }

    // Count tasks with max frequency
    int maxCount = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] == maxFreq)
            maxCount++;
    }

    int result = (maxFreq - 1) * (n + 1) + maxCount;

    return (result > tasksSize) ? result : tasksSize;
}