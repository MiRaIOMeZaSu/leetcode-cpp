#include <iostream>
#include<bits/stdc++.h> //万能
#include <string.h>


using namespace std;

struct Student {
    int id;
    int year;
    int month;
    int day;
    char name[100];

    bool operator<(Student a) const {
        if (year == a.year) {
            if (month == a.month) {
                if (day == a.day) {
                    return id > a.id;
                }
                return day < a.day;
            }
            return month < a.month;
        }
        return year < a.year;
    }
};

int main() {
    int size;
    cin >> size;
    struct Student student[size];
    char buff[100];
    for (int i = 0; i < size; i++) {
        cin >> buff;
        strcpy(student[i].name, buff);
        cin >> student[i].year;
        cin >> student[i].month;
        cin >> student[i].day;
        student[i].id = i;
    }
    sort(student, student + size);
    for (int i = 0; i < size; i++) {
        cout << student[i].name << endl;
    }
    return 0;
}
