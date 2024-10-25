#include <iostream>
#include <vector>
#include <map>
#include <time.h>
#include <iomanip>

using namespace std;

struct Subject {
    string name;
    string mark;
};

struct Student {
    string fullName;
    int numOfGroup;
    Subject* subjects;
};

const int MAX_CNT_STUDENTS = 15;
const int MAX_CNT_GROUPS = 3;
const int MAX_CNT_SUBJECTS = 5;

int main() {
    srand((unsigned int)(time(0)));

    setlocale(LC_ALL, "Russian");

    map<int, string> studentsFio = {
        {0, "������ ���� ��������"},
        {1, "������ ���� ��������"},
        {2, "������ ���� ��������"},
        {3, "������� ����� ���������"},
        {4, "�������� ������� ����������"},
        {5, "�������� ������ ����������"},
        {6, "�������� ������ �������"},
        {7, "������� ����� ���������"},
        {8, "������� ����� ���������"},
        {9, "�������� ������� ����������"},
        {10, "������ ����� ��������"},
        {11, "�������� ������� ����������"},
        {12, "������� ������ ���������"},
        {13, "��������� �������� �����������"},
        {14, "������ ���� ��������"},
        {15, "�������� ������� ����������"},
        {16, "������� ������ ���������"},
        {17, "����������� ��������� �������������"},
        {18, "�������� ������ ����������"},
        {19, "�������� ������� ����������"},
        {20, "������� ����� ���������"},
        {21, "�������� ������ ����������"},
        {22, "������� ����� ���������"},
        {23, "������� ����� ���������"},
        {24, "������������ ���������� ��������������"},
        {25, "������� ����� ���������"},
        {26, "������ ����� ��������"},
        {27, "������� ����� ���������"},
        {28, "����������� ��������� �������������"},
        {29, "��������� ������� �����������"}
    };
    map<int, int> groupsNumber = {
        {0, 11},
        {1, 12},
        {2, 13}
    };
    map<int, string> marks = {
        {0, "�������������������"},
        {1, "�����������������"},
        {2, "������"},
        {3, "�������"}
    };
    map<int, string> subjectsNames = {
        {1, "��������������� �����"},
        {2, "�������������� ������"},
        {3, "������������� ���������"},
        {4, "������������� �����������"},
        {5, "�������"}
    };

    int cnt_students, cnt_groups, cnt_subjects;
    cout << "������� ���������� ���������: ";
    cin >> cnt_students;
    cout << "������� ���������� �����: ";
    cin >> cnt_groups;
    cout << "������� ���������� ���������: ";
    cin >> cnt_subjects;
    if ((cnt_students > MAX_CNT_STUDENTS) || (cnt_groups > MAX_CNT_GROUPS) || (cnt_subjects > MAX_CNT_SUBJECTS)) {
        cout << "������ �����";
        return 0;
    }

    vector<Student> students_vec;
    for (int i = 0; i < cnt_students; i++) {
        Student student;
        student.fullName = studentsFio[rand() % 30];
        student.numOfGroup = groupsNumber[rand() % cnt_groups];
        student.subjects = new Subject[cnt_subjects];
        for (int j = 0; j < cnt_subjects; j++) {
            student.subjects[j].name = subjectsNames[j + 1];
            student.subjects[j].mark = marks[rand() % 4];
        }
        students_vec.push_back(student);
    }
    cout << "------------------------------------------------------------" << endl << endl;
    for (int i = 0; i < students_vec.size(); i++) {
        cout << left << setw(15) << "���:" << students_vec[i].fullName << endl;
        cout << "����� ������:" << students_vec[i].numOfGroup << endl;
        cout << left << setw(15) << "��������:" << endl;

        for (int j = 0; j < cnt_subjects; j++) {
            cout << left << setw(35) << students_vec[i].subjects[j].name << " "
                << setw(25) << right << students_vec[i].subjects[j].mark << endl;
        }
        cout << endl;
    }
    cout << "------------------------------------------------------------" << endl;

    map<int, int> excellentStudentsInGroup;
    for (const auto& student : students_vec) {
        bool allExcellent = true;
        for (int j = 0; j < cnt_subjects; j++) {
            if (student.subjects[j].mark != "�������") {
                allExcellent = false;
                break;
            }
        }
        if (allExcellent) {
            excellentStudentsInGroup[student.numOfGroup]++;
        }
    }

    if (excellentStudentsInGroup.empty()) {
        cout << "��� ���������, ������� ��� �������� �� '�������'." << endl;
    }
    else {
        cout << "���������� ���������, ������� ��� �������� �� '�������' �� �������:" << endl;
        for (const auto& group : excellentStudentsInGroup) {
            cout << "������ " << group.first << ": " << group.second << " ���������" << endl;
        }
    }

    return 0;
}
