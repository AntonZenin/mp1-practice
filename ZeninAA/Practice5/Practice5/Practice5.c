#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "dirent.h"
#include <string.h>

#define MAX_PATH_LEN 256
#define MAX_FILES 100

typedef struct {
    char name[MAX_PATH_LEN];
    long size;
} File;

int compare(const void* a, const void* b) {
    long sizeA = ((File*)a)->size;
    long sizeB = ((File*)b)->size;

    if (sizeA < sizeB) {
        return -1;
    }
    else if (sizeA > sizeB) {
        return 1;
    }
    else {
        return 0;
    }
}

void selectionSort(File* files, int count) {
    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < count; j++) {
            if (files[j].size < files[minIndex].size) {
                minIndex = j;
            }
        }
        File temp = files[minIndex];
        files[minIndex] = files[i];
        files[i] = temp;
    }
}

void insertionSort(File* files, int count) {
    for (int i = 1; i < count; i++) {
        File key = files[i];
        int j = i - 1;
        while (j >= 0 && files[j].size > key.size) {
            files[j + 1] = files[j];
            j--;
        }
        files[j + 1] = key;
    }
}

void merge(File* arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    File* L = (File*)malloc(n1 * sizeof(File));
    File* R = (File*)malloc(n2 * sizeof(File));


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0;  
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i].size <= R[j].size) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}
void mergeSort(File* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void showFiles(const char* dirPath, int method) {
    clock_t t_start;
    clock_t t_finish = 0 ;
    double time_f = 0;
    DIR* dir;
    struct dirent* entry;
    File files[MAX_FILES];
    int count = 0;

    dir = opendir(dirPath);

    if (dir == NULL) {
        printf("We can't open file\n");
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        char filePath[MAX_PATH_LEN];
        snprintf(filePath, sizeof(filePath), "%s/%s", dirPath, entry->d_name);

        FILE* file = fopen(filePath, "rb");
        if (file != NULL) {
            fseek(file, 0L, SEEK_END);
            long size = ftell(file);
            strcpy(files[count].name, entry->d_name);
            files[count].size = size;
            count++;
            fclose(file);
        }
    }
    closedir(dir);

    switch (method) {
    case 1:
        t_start = clock();
        selectionSort(files, count);
        break;
    
    case 2:
        t_start = clock();
        insertionSort(files, count);
        break;

    case 3:
        t_start = clock();
        mergeSort(files, 0, count - 1);
        break;

    default:
        printf("Invalid sorting method\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("File name: %s, Size: %ld bytes\n", files[i].name, files[i].size);
    }
}

int main() {
    clock_t t_start = 0; 
    clock_t t_finish; 
    double time_f; 

    char dirPath[MAX_PATH_LEN];
    int method;


    printf("Input way: ");
    scanf("%s", dirPath);


    printf("Sorting methods:\n");
    printf("1 - selection sort\n");
    printf("2 - insertion sort\n");
    printf("3 - merge sort\n");
    printf("Input sorting method: ");
    scanf("%d", &method); 
    
    showFiles(dirPath, method);
    t_finish = clock();
    time_f = (double)((t_finish - t_start)); 
    printf("Time: %.5lf\n", time_f); 

    return 0;
}
    

    
    
    
    

    
