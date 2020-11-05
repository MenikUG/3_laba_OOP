#include <iostream>
#include <string>

using namespace std;

class Human {
protected:
    string name;
    int age;
    int weight;

public:
    Human() {
        name = "~";
        age = 0;
        weight = 0;
    }

    Human(string name, int age, int weight) {
        this->name = name;
        this->age = age;
        this->weight = weight;
    }

    Human(const Human& h) {
        name = h.name;
        age = h.age;
        weight = h.weight;
    }

    virtual void about_me() {
        printf("Меня зовут %s,мне %d лет и я вешу %d кг.\n", name.c_str(), age, weight);
    }

    ~Human() {
        // Деструктор
    }
};

class Student:public Human {
protected:
    int mark;

public:
    Student() {
        mark = 5;
    }

    Student(int mark) {
        this->mark = mark;
    }

    Student(const Student& s) {
        mark = s.mark;
    }

    virtual void about_me() {
        printf("Я студент %s, и имею средний балл %d за 2 семестр\n", name.c_str(), mark);
    }

    ~Student() {
        // Деструктор
    }
};

class Teacher :public Human {
protected:
    int work_experience;

public:
    Teacher() {
        work_experience = 5;
    }

    Teacher(int work_experience) {
        this->work_experience = work_experience;
    }

    Teacher(const Teacher& t) {
        work_experience = t.work_experience;
    }

    virtual void about_me() {
        printf("Меня зовут %s, и я преподаю программирование уже %d лет\n", name.c_str(), work_experience);
    }

    ~Teacher() {
        // Деструктор
    }
};

int main()
{
    setlocale(0, "");
    Human ra;
    Student re;
    Teacher rs;
    ra.about_me();
    re.about_me();
    rs.about_me();
}
