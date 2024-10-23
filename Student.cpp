#include <iostream>
#include <windows.h>

using namespace std;

class Student {
protected:
    string name;
    string specialty;
    int age;
    int courseNumber;
public:
    Student(string name_i, string specialty_i, int age_i, int courseNumber_i)
        : name{ name_i }, specialty{ specialty_i }, age{ age_i }, courseNumber{ courseNumber_i } {}

    virtual void display() {
        cout << name<< ", " << age << " років\nНавчається на " << courseNumber << " курсі спеціальності " << specialty << endl;
    }
};

class Aspirant : public Student {
    string theme;
    string deadline;
public:
    Aspirant(string name_i, string specialty_i, int age_i, int courseNumber_i, string theme_i, string deadline_i)
        : Student(name_i, specialty_i, age_i, courseNumber_i), theme{ theme_i }, deadline{ deadline_i } {}

    void display() override {
        Student::display();
        cout << "Пише дисертацію на тему " << theme << "\nСрок сдачі роботи - " << deadline << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Aspirant aspirant("Шевченко Микола Дмитрович", "Архітектор", 19, 3, "Архітектура стародавньої Греції", "29.06.2025");
    aspirant.display();
}