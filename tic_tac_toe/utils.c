#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

#include "utils.h"
#include "game.h"


void register_value(int value, int arr[]){
    for(int i = 0; i < MAX_INDIVIDUAL_MOVE; i++){
        if (!arr[i]){
            arr[i] = value;
            break;
        }
    }
}

bool has(int arr[], int item){
    bool success = false;

    for(int i = 0; i < size(arr); i++){
        if(arr[i] == item) {
            success = true;
            break;
        }
    }
    return success;
}

int size(int arr[]){
    int len = 0;
    while(arr[len]){
        len++;
    }
    return len;
}