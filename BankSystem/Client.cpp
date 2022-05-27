#include "Client.h"

Individual::Individual(string _name, string _surname, string _patronymic, string _sex, string _birth_date, string _passport, string _phone_number, string _address)
{
	name = _name;
	surname = _surname;
	patronymic = _patronymic;
	sex = _sex;
	birth_date = _birth_date;
	passport = _passport;
	phone_number = _phone_number;
	address = _address;
}

void Individual::set_surname(string _surname)
{
	surname = _surname;
}

void Individual::set_patronymic(string _patronymic)
{
	patronymic = _patronymic;
}

void Individual::set_sex(string _sex)
{
	sex = _sex;
}

void Individual::set_birth_date(string _birth_date)
{
	birth_date = _birth_date;
}

void Individual::set_passport(string _passport)
{
	passport = _passport;
}

LegalEntity::LegalEntity(string _name, string _phone_number, string _address)
{
	name = _name;
	phone_number = _phone_number;
	address = _address;
}

void Client::set_name(string _name)
{
	name = _name;
}

void Client::set_phone_number(string _phone_number)
{
	phone_number = _phone_number;
}

void Client::set_address(string _address)
{
	address = _address;
}
