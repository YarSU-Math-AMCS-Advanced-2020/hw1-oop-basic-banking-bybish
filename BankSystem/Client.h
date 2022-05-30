#pragma once
#include <string>
#include <vector>

using namespace std;

class Client
{
public:
	string get_name() { return name; }
	string get_phone_number() { return phone_number; }
	string get_address() { return address; }

	void set_name(string _name);
	void set_phone_number(string _phone_number);
	void set_address(string _address);

protected:
	string name;
	string phone_number;
	string address;
};

class Individual : public Client
{
public:
	
	Individual() {};
	Individual(string _name, string _surname, string _patronymic, string _sex, string _birth_date, string _passport, string _phone_number, string _address);

	string get_surname() { return surname; }
	string get_patronymic() { return patronymic; }
	string get_sex() { return sex; }
	string get_birth_date() { return birth_date; }
	string get_passport() { return passport; }

	void set_surname(string _surname);
	void set_patronymic(string _patronymic);
	void set_sex(string _sex);
	void set_birth_date(string _birth_date);
	void set_passport(string _passport);

private:
	string surname;
	string patronymic;
	string sex;
	string birth_date;
	string passport;

};

class LegalEntity : public Client
{
public:
	LegalEntity() {};
	LegalEntity(string _name, string _phone_number, string _address);
};