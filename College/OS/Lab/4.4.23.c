//FIFO Page Replacement

#include<stdio.h>
#include<stdlib.h>


int front=-1,rear=-1;
int queue[100];
void enqueue(int x)
{
    if(rear==99)
    {
        printf("Queue is full");
    }
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=x;
    }
    else if(rear==99&&front!=0)
    {
        rear=0;
        queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}
void dequeue()
{
    if(front==-1)
    {
        printf("Queue is empty");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
}
void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
    }
}


int main()
{
    int frame = 0;
    int *ptr;
    int n;
    int hits = 0;
    int i, j, k;

    printf("Enter the number of frames: ");
    scanf("%d", &frame);

    printf("Enter the size of reference string: ");
    scanf("%d", &n);
    
    ptr = (int*)malloc(n * sizeof(int));

    printf("Enter the elements of reference string: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", (ptr + i));
    }

    for (i = 0; i < frame; i++)
    {
        enqueue(ptr[i]);
    }

    for (i = frame; i < n; i++)
    {
        if (queue[front] == ptr[i])
        {
            hits++;
        }
        else
        {
            if ((rear + 1) % 100 == front)
            {
                dequeue();
            }
            enqueue(ptr[i]);
        }
    }

    printf("\nTotal hits: %d", hits);

    return 0;
}


// Optimal Page

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() 
{
    int frame = 0;
    int page = 0;

    int i, j, k;    
    int page_fault = 0;

    int *ptr;
    printf("Enter the size of reference string: ");
    scanf("%d", &page);
    ptr = (int*)malloc(page*sizeof(int));

    //Reference string input
    printf("Enter the string elements: ");
    for(i = 0; i < page; i++) {
        scanf("%d", (ptr+i));
    }

    printf("Enter the size of frame: ");
    scanf("%d", &frame);

    int temp[frame];
    for(i = 0; i < frame; i++) {
        temp[i] = -1;
    }

    for(i = 0; i < page; i++) {
        j = 0;
        for(k = 0; k < frame; k++) {
            if(ptr[i] == temp[k]) {
                j = 1;
                break;
            }
        }
        if(j == 0) {
            page_fault++;
            if(page_fault <= frame) {
                temp[page_fault-1] = ptr[i];
            } else {
                int max_dist = -1;
                int replace = -1;
                for(k = 0; k < frame; k++) {
                    int dist = 0;
                    int l;
                    for(l = i+1; l < page; l++) {
                        if(temp[k] == ptr[l]) {
                            break;
                        }
                        dist++;
                    }
                    if(dist > max_dist) {
                        max_dist = dist;
                        replace = k;
                    }
                }
                temp[replace] = ptr[i];
            }
        }

        printf("\n");
        for(k = 0; k < frame; k++) {
            if(temp[k] != -1) {
                printf("%d\t\t\t", temp[k]);
            } else {
                printf("-\t\t\t");
            }
        }
        printf("\n%d", ptr[i]);
    }

    printf("\nTotal number of page faults: %d",page_fault);
    printf("\nTotal number of hits: %d",page-page_fault);

}

// LRU

#include <stdio.h>
#include <stdlib.h>

int main() {
    int frameCount, pageCount, i, j, k, pageFault = 0, hit = 0, min, leastRecentlyUsedIndex, flag = 0;
    int *frame, *pages, *lru;

    printf("Enter the number of frames: ");
    scanf("%d", &frameCount);

    frame = (int*)calloc(frameCount, sizeof(int));

    printf("Enter the number of pages: ");
    scanf("%d", &pageCount);

    pages = (int*)malloc(pageCount * sizeof(int));
    lru = (int*)calloc(frameCount, sizeof(int));

    printf("Enter the reference string: ");
    for (i = 0; i < pageCount; i++) {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < pageCount; i++) {
        flag = 0;
        for (j = 0; j < frameCount; j++) {
            if (frame[j] == pages[i]) {
                hit++;
                flag = 1;
                lru[j] = i;
                break;
            }
        }

        if (!flag) {
            pageFault++;

            if (i < frameCount) {
                frame[i] = pages[i];
                lru[i] = i;
            } else {
                min = lru[0];
                leastRecentlyUsedIndex = 0;

                for (j = 1; j < frameCount; j++) {
                    if (lru[j] < min) {
                        min = lru[j];
                        leastRecentlyUsedIndex = j;
                    }
                }

                frame[leastRecentlyUsedIndex] = pages[i];
                lru[leastRecentlyUsedIndex] = i;
            }
        }
    }

    printf("\nNumber of Page Faults: %d", pageFault);
    printf("\nNumber of Page Hits: %d", hit);

    return 0;
}
