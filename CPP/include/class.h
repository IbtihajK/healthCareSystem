#ifndef  CLASS_H
#define CLASS_H

#include <iostream>
#include <string>

enum Gender {
  Male=1,
  Female=2,
  X=3
};

struct Date {
  int day;
  std::string month;
  int year;

  Date() : day(1), month("Jan"), year(1969) {}
  Date(int day, std::string month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
  }

  std::string GetData() {
    std::string statement = std::to_string(day) + "/" + month + "/" + std::to_string(year); 
    return statement;
  }

};

struct Medicine {
  std::string name;
  int price;
  Medicine() : name("ERROR NO NAME"), price(0) {}
  Medicine(std::string name, int price) : name(name), price(price) {}

  std::string GetData() {
    std::string statement = name + "  " + std::to_string(price); 
    return statement;
  }

};

struct Disease {
  std::string name;
  int level;
  Medicine medicine; 

  Disease() : name("ERROR NO NAME"), level(0), medicine(Medicine()) {};
  Disease(std::string name, int level, Medicine medicine) {
    this->name = name;
    this->level = level;
    this->medicine = medicine;
  }

  std::string GetData() {
    std::string statement = name + "  " + std::to_string(level) + medicine.name;
    return statement;
  } 

};

class Person {
private:

  std::string name; 
  std::string sex;
  int age;

public:

  Person() : name("ERROR NO NAME"), sex("0"), age(0) {}
  Person(std::string name, std::string sex, int age) {
    this->name = name;
    this->sex = sex;
    this->age = age;
  }

  std::string GetData() {
    std::string statement = name + "  " + std::to_string(age) + "  " + sex; 
    return statement;
  }

};

class Doctor : public Person {
private: 
  std::string qualification, specilization;
  Date joinDate;
  int experience;
public:

  Doctor() : Person(), qualification("0"), specilization("0"), joinDate(Date()), experience(0) {}
  Doctor(std::string name, std::string sex, int age, std::string qualification, std::string specialization, Date joinDate, int experience) : Person(name, sex, age), qualification(qualification), specilization(specilization), joinDate(joinDate), experience(experience) {}

  std::string GetData() {
    std::string statement = Person::GetData() + "  " + qualification + "  " +  joinDate.GetData() + std::to_string(experience);
    return statement;
  }

};

class Patient : public Person {
private:
  Disease disease;
  Date admitDate;
  Date dischageDate; 
  int price;
public: 

  Patient() : Person(), disease(Disease()), admitDate(Date()), dischageDate(Date()), price(0) {}
  Patient(std::string name, std::string sex, int age, Disease disease, Date admitDate, Date dischageDate) : Person(name, sex, age), disease(disease), admitDate(admitDate), dischageDate(dischageDate)  {} 

  std::string GetData() {
    std::string statement = Person::GetData() + "  " + disease.GetData() + "  " + admitDate.GetData() + "  " + dischageDate.GetData() + "  " + std::to_string(price); 
    return statement;
  }

};

#endif // ! CLASS_H
