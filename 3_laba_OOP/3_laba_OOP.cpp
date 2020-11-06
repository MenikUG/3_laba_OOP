#include <iostream>
#include <string>
#include <ctime>

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

class Storage {
private:
    Human** objects;
    int count_occupied;

public:
    Storage()
    {
    }
    
    void initialisat(int count) {
        objects = new Human* [count];
        for (int i = 0; i < count; ++i)
            objects[i] = NULL;
    }

    void add_object(int index, Human* object) {
        objects[index] = object;
    }

    void delete_object(int index) {
        delete objects[index];
        objects[index] = NULL;
    }

    void method(int index) {
        objects[index]->about_me();
    }

    bool check_empty(int index) {
        if (objects[index] == NULL) 
            return true;
        else return false;
    }

    void appeal_all(int n) {
        for (int i = 0; i < n; ++i) {
            printf("[%d] место ", i);
            if (check_empty(i))
                printf("Пустое\n");
            else method(i);
        }
    }

};

Human* random_object(int variant) {
    switch (variant) {
    case 1:
        return new Student;
    case 2:
        return new Teacher;
    }
}

int main()
{
    setlocale(0, "");
    Storage storage;
    srand(time(0));
    string text = " ";
    int n = 1000; // Кол-во операций
    int count = 10; // Кол-во элементов
    storage.initialisat(count);
    unsigned int start_time = clock();
    for (int i = 0; i < n; ++i) {         
        int act = rand() % count; // Выбираем с каким объектом взаимодействуем
        int vibor = 1 + rand() % 3; // Выбираем какое действие произойдёт с выбранным объектом
        int k = 1 + rand() % 2;
        printf("[%d]", i);
        switch (vibor) {
        case 1:  
            if (storage.check_empty(act)) { // Если место свободно, то добавляем объект
                if (k == 1) {
                    text = "Student";
                }
                else text = "Teacher";
                printf("  Добавили в [%i] место хранилища объект класса %s\n", act, text.c_str());
                storage.add_object(act, random_object(k));
            }
            else printf("  [%i] место хранилища занято, добавить объект невозможно\n", act);
            break;
        case 2:
            if (!storage.check_empty(act)) { // Если место занято, то удаляем объект
                printf("  Освободили [%i] место хранилища\n", act);
                storage.delete_object(act);
            }
            else printf("  [%i] место хранилища пустое, освободить место в хранилище невозможно\n", act);
            break;
        case 3:
            if (!storage.check_empty(act)) { // Если место занято, то вызываем метод у объекта
                printf("  Запуск метода about_me() у [%i] объекта из хранилища\n", act);
                storage.method(act);
            }
            else printf("  [%i] место хранилища пустое, вызвать метод невозможно\n", act);
            break;
        }           
    }


    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "\n" <<"Время работы = " << clock() / 1000.0 << endl;

    system("pause");
    cout << "\n\n" <<"Вы хотите посмотреть всё хранилище? 1 - Да, 2 - Нет ";
    int a;
    cin >> a;
    if (a == 1) {
        storage.appeal_all(count);
    }
}