#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct student {
    char name[20];
    int point;
};

void addStudent(struct student students[], int *count) {
    printf("Nhap ten sinh vien: ");
    scanf("%s", students[*count].name);

    printf("Nhap diem sinh vien: ");
    scanf("%d", &students[*count].point);

    (*count)++;
}

void printStudents(struct student students[], int count) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < count; i++) {
        printf("Ten: %s, Diem: %d\n", students[i].name, students[i].point);
    }
}

void searchStudent(struct student students[], int count, char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Diem cua %s la: %d\n", students[i].name, students[i].point);
            return;
        }
    }
    printf("Khong tim thay sinh vien.");
}

int main() {

    struct student students[MAX_STUDENTS];
    int count = 0;
    int n;
    char searchName[50];

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        addStudent(students, &count);
    }

    printStudents(students, count);

    printf("Nhap ten sinh vien can tim: ");
    scanf("%s", searchName);

    searchStudent(students, count, searchName);
    return 0;
}