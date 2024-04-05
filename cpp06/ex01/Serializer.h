#ifndef SERIALISER_H
#define SERIALISER_H

#pragma once

#include <iostream>
# include <string>
# include <stdint.h>

struct Data
{
	std::string	name;
	int age;
};


class Serializer
{
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
private:
	Serializer();
    Serializer(const Serializer &);
	Serializer &operator=(const Serializer &);
    ~Serializer();
};

#endif