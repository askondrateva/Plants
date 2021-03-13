#include <iostream>
#include <string>

using namespace std;

//Базовый класс: растения
class Plants {
public:
    string namep; //название растения
    string season; //сезон цветения
    double sm; //насколько см растение вырастает за месяц
    double data; //сколько месяцев растению

    //Метод для нахождения длины растения
    double Length() {
        double l = 0;
        l = sm * data;
        return l;
    }

    //Конструктор для создания объекта
    Plants(string n, string sn, double s, double d) {
        namep = n;
        season = sn;
        sm = s;
        data = d;
    }

    //Метод для печати информации о растении
    void PrintInf() {
        cout << "Название растения: " << namep << endl;
        cout << "Сезон цветения: " << season << endl;
        cout << "Насколько быстро растет: " << sm << " см в месяц" << endl;
        cout << "Растению уже: " << data << " месяцев" << endl;
        cout << "Длина вашего растения: " << Length() << " см" << endl;
    }

};

//Дочерний класс: домашние растения
class Home_Plants : public Plants {
public:
    string light; //Свет для растения

    // Метод для определения частоты полива
    double Poliv() {
        double p = 0;
        p = Length() / 50;
        return p;
    }

    //Метод для нахождения комфортной температуры для растения 
    void Temp(string light) {
        if (light == "Мало света") {
            cout << "Комфортная температура для вашего растения: +5 до +10 C " << endl;
        }
        if (light == "Не очень много света") {
            cout << "Комфортная температура для вашего растения: +10 до +15 C " << endl;
        }
        if (light == "Много света") {
            cout << "Комфортная температура для вашего растения: +15 до +22 C " << endl;
        }
    }

    //Конструктор для создания объекта
    Home_Plants(string n, string sn, double s, double d, string l) : Plants(n, sn, s, d) {
        light = l; 
    }

    //Метод для печати информации о растении
    void PrintInf() {
        cout << "Название растения: " << namep << endl;
        cout << "Сезон цветения: " << season << endl;
        cout << "Насколько быстро растет: " << sm << " см в месяц" << endl;
        cout << "Растению уже: " << data << " месяцев" << endl;
        cout << "Длина вашего растения: " << Length() << " см" << endl;
        cout << "Количество света, необходимое вашему растению: " << light << endl;
        Temp(light);
        cout << "Количество поливов: " << Poliv() << " раз(а)" << endl;

    }
};

//Дочерний класс: уличные растения
class Street_Plants : public Plants {
public:   
    string plod; //наличие плодов

    //Метод для определения места высадки уличного растения
    void Location(string plod) {
        if (plod == "Да") {
            cout << "Ваше растение следует высадить в огороде или теплице" << endl;
        }
        else {
            cout << "Ваше растение следует высадить в палисаднике или саде" << endl;
        }
    }
                 
    //Конструктор для создания объекта
    Street_Plants(string n, string sn, double s, double d, string p) : Plants(n, sn, s, d) {
        plod = p;
    }

    //Метод для печати информации о растении
    void PrintInf() {
        cout << "Название растения: " << namep << endl;
        cout << "Сезон цветения: " << season << endl;
        cout << "Насколько быстро растет: " << sm << " см в месяц" << endl;
        cout << "Растению уже: " << data << " месяцев" << endl;
        cout << "Наличие плодов: " << plod << endl;
        cout << "Длина вашего растения: " << Length() << " см" << endl;
        Location(plod);
    }
};

int main() {
    
    //Русская раскладка в консоли
    setlocale(LC_ALL, "Russian");

    //Создание объектов
    //Объект базового класса Растения
    Plants p1("Ель", "Август", 110, 10);
    p1.PrintInf();

    cout << endl;

    //Объект дочернего класса Домашние растения
    cout << "Домашнее растение:" << endl;
    for (int i = 0; i < 50; i++) {
        cout << "-";
    }
    cout << endl;
    Home_Plants p2("Декабрист", "Декабрь", 12, 5, "Много света");
    p2.PrintInf();

    cout << endl;

    Home_Plants p3("Кактус", "Цветет редко", 18, 8, "Мало света");
    p3.PrintInf();

    cout << endl;

    //Объект дочернего класса Уличные растения
    cout << "Уличное растение:" << endl;
    for (int i = 0; i < 50; i++) {
        cout << "-";
    }
    cout << endl;
    Street_Plants p4("Огурцы", "Сентябрь", 10, 4, "Да");
    p4.PrintInf();

    cout << endl;

    Street_Plants p5("Тюльпаны", "Май", 6, 3, "Нет");
    p5.PrintInf();

    return 0;
}