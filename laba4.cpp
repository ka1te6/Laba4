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
        {0, "Олегов Олег Олегович"},
        {1, "Иванов Иван Иванович"},
        {2, "Петров Петр Петрович"},
        {3, "Сидоров Сидор Сидорович"},
        {4, "Алексеев Алексей Алексеевич"},
        {5, "Михайлов Михаил Михайлович"},
        {6, "Кузнецов Кузьма Кузьмич"},
        {7, "Федоров Федор Федорович"},
        {8, "Смирнов Семен Семенович"},
        {9, "Васильев Василий Васильевич"},
        {10, "Павлов Павел Павлович"},
        {11, "Николаев Николай Николаевич"},
        {12, "Андреев Андрей Андреевич"},
        {13, "Григорьев Григорий Григорьевич"},
        {14, "Егоров Егор Егорович"},
        {15, "Дмитриев Дмитрий Дмитриевич"},
        {16, "Сергеев Сергей Сергеевич"},
        {17, "Александров Александр Александрович"},
        {18, "Максимов Максим Максимович"},
        {19, "Георгиев Георгий Георгиевич"},
        {20, "Артемов Артем Артемович"},
        {21, "Викторов Виктор Викторович"},
        {22, "Борисов Борис Борисович"},
        {23, "Антонов Антон Антонович"},
        {24, "Константинов Константин Константинович"},
        {25, "Денисов Денис Денисович"},
        {26, "Игорев Игорь Игоревич"},
        {27, "Романов Роман Романович"},
        {28, "Станиславов Станислав Станиславович"},
        {29, "Ярославов Ярослав Ярославович"}
    };
    map<int, int> groupsNumber = {
        {0, 11},
        {1, 12},
        {2, 13}
    };
    map<int, string> marks = {
        {0, "Неудовлетворительно"},
        {1, "Удовлетворительно"},
        {2, "Хорошо"},
        {3, "Отлично"}
    };
    map<int, string> subjectsNames = {
        {1, "Алгоритмические языки"},
        {2, "Математический анализ"},
        {3, "Аналитическая геометрия"},
        {4, "Теоретическая информатика"},
        {5, "История"}
    };

    int cnt_students, cnt_groups, cnt_subjects;
    cout << "Введите количество студентов: ";
    cin >> cnt_students;
    cout << "Введите количество групп: ";
    cin >> cnt_groups;
    cout << "Введите количество предметов: ";
    cin >> cnt_subjects;
    if ((cnt_students > MAX_CNT_STUDENTS) || (cnt_groups > MAX_CNT_GROUPS) || (cnt_subjects > MAX_CNT_SUBJECTS)) {
        cout << "Ошибка ввода";
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
        cout << left << setw(15) << "ФИО:" << students_vec[i].fullName << endl;
        cout << "Номер группы:" << students_vec[i].numOfGroup << endl;
        cout << left << setw(15) << "Предметы:" << endl;

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
            if (student.subjects[j].mark != "Отлично") {
                allExcellent = false;
                break;
            }
        }
        if (allExcellent) {
            excellentStudentsInGroup[student.numOfGroup]++;
        }
    }

    if (excellentStudentsInGroup.empty()) {
        cout << "Нет студентов, сдавших все экзамены на 'Отлично'." << endl;
    }
    else {
        cout << "Количество студентов, сдавших все экзамены на 'Отлично' по группам:" << endl;
        for (const auto& group : excellentStudentsInGroup) {
            cout << "Группа " << group.first << ": " << group.second << " студентов" << endl;
        }
    }

    return 0;
}
