#include <iostream>
#include <queue>

using namespace std;

class Student {

public:
    int sum;
    int yuwen;
    int id;

    // 对小于号进行重载
    bool operator<(Student a) const {
        if (sum == a.sum) {
            if (yuwen == a.yuwen) {
                return id > a.id;
            }
            return yuwen < a.yuwen;
        }
        return sum < a.sum;
    }

    Student(int id, int yuwen, int _math, int english) {
        this->yuwen = yuwen;
        this->sum = yuwen + _math + english;
        this->id = id;
    }
};

int main() {
    priority_queue<Student> q;
    int size;
    cin >> size;
    int yuwen;
    int _math;
    int english;

    for (int i = 0; i < size; i++) {
        cin >> yuwen;
        cin >> _math;
        cin >> english;
        q.push(Student(i + 1, yuwen, _math, english));
    }
    for (int i = 0; i < size && i < 5; i++) {
        Student student = q.top();
        q.pop();
        cout << student.id << " " << student.sum << endl;
    }
    return 0;
}
