#include <stdio.h>
#include "search.h"

const int COMMANDS_SIZE = 8 * sizeof(long);

void SetBit(commands_t A, int k);
int GetBit(commands_t A, int k);
int main() {
    int example_command = 25;
    int valid_commands[20] = {24, 31, 108, 19, 204, 47, 52, 98, 114, 117, 124, 126, 4, 5, 6, 7, 8, 9, 133, 134};
    commands_t commands = {0};
    for (int i = 0; i < 20; i++) {
        SetBit(commands, valid_commands[i]);
    }
    printf("%d\n", GetBit(commands, example_command));
    return 0;
}

void SetBit(commands_t A, int k)
{
    A[k / COMMANDS_SIZE] |= 1 << (k % COMMANDS_SIZE);
}

int GetBit(commands_t A, int k)
{
    return (A[k / COMMANDS_SIZE] & (1 << (k % COMMANDS_SIZE))) != 0;
}