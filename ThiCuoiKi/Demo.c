#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Job {
    char jobName[50];
    char description[200];
    int time;
    struct Job *next;
};

void addJob(struct Job** head, char* jobName, char* description, int time) {
    struct Job *newJob = (struct Job*)malloc(sizeof(struct Job));
    strcpy(newJob->jobName, jobName);
    strcpy(newJob->description, description);
    newJob->time = time;
    newJob->next = NULL;

    if (*head == NULL || (*head)->time > time) {
        newJob->next = *head;
        *head = newJob;
    } else {
        struct Job *current = *head;
        while (current->next != NULL && current->next->time <= time) {
            current = current->next;
        }
        newJob->next = current->next;
        current->next = newJob;
    }
}

void printListJob(struct Job* head) {
    struct Job *current = head;
    if (current == NULL) {
        printf("Danh sach rong.\n");
        return;
    }
    printf("Danh sach cong viec:\n");
    while (current != NULL) {
        printf("Ten: %s, Mo ta: %s, Thoi gian: %d\n", current->jobName, current->description, current->time);
        current = current->next;
    }
}

void deleteJob(struct Job** head, char* jobName) {
    if (*head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }
    struct Job *temp = *head, *prev = NULL;
    while (temp != NULL && strcmp(temp->jobName, jobName) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Khong tim thay cong viec.\n");
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Xaa cong viec thanh cong.\n");
}

void searchJobByName(struct Job *head, char* jobName) {
    struct Job *current = head;
    while (current != NULL) {
        if (strcmp(current->jobName, jobName) == 0) {
            printf("Ten: %s, Mo ta: %s, Thoi gian: %d\n", current->jobName, current->description, current->time);
            return;
        }
        current = current->next;
    }
    printf("Khong tim thay cong viec.\n");
}

void searchJobByDescriptionOrTime(struct Job* head, char* description, int time) {
    struct Job *current = head;
    int found = 0;

    while (current != NULL) {
        if ((description[0] != '\0' && strstr(current->description, description) != NULL) ||
            (time > 0 && current->time == time)) {
            printf("Ten: %s, Mo ta: %s, Thoi gian: %d", current->jobName, current->description, current->time);
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("Khong tim thay cong viec phu hop.\n");
    }
}

int main() {
    int choice, time;
    char jobName[50], description[200];
    struct Job *head = NULL;

    do {
        printf("\n----------MENU----------\n");
        printf("1. Them cong viec\n");
        printf("2. Hien thi lich lam viec\n");
        printf("3. Xoa cong viec\n");
        printf("4. Tim kiem cong viec theo ten\n");
        printf("5. Tim kiem cong viec theo mo ta hoac thoi gian\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhap ten cong viec: ");
                fgets(jobName, sizeof(jobName), stdin);
                jobName[strcspn(jobName, "\n")] = '\0';
                printf("Nhap mo ta cong viec: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0';
                printf("Nhap thoi gian: ");
                scanf("%d", &time);
                getchar();
                addJob(&head, jobName, description, time);
                break;

            case 2:
                printListJob(head);
                break;
            case 3:
                printf("Nhap ten cong viec can xoa: ");
                fgets(jobName, sizeof(jobName), stdin);
                jobName[strcspn(jobName, "\n")] = '\0';
                deleteJob(&head, jobName);
                break;
            case 4:
                printf("Nhap ten cong viec can tim: ");
                fgets(jobName, sizeof(jobName), stdin);
                jobName[strcspn(jobName, "\n")] = '\0';
                searchJobByName(head, jobName);
                break;
            case 5:
                printf("Nhap mo ta cong viec (hoac de trong): ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0';
                printf("Nhap thoi gian cong viec (0 de bo qua): ");
                scanf("%d", &time);
                getchar();
                searchJobByDescriptionOrTime(head, description, time);
                break;
        }
    } while (choice != 0);

    return 0;
}
