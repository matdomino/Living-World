#pragma once
#include "Animal.h"

#include <boost/serialization/access.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include <boost/serialization/export.hpp>

class Sheep : public Animal {
private:
	static int idCounter;
public:
	Sheep() {}

	Sheep(std::list<Ancestor>* givenAncestors)
		: Animal(12, ("Sheep" + std::to_string(++this->idCounter)), givenAncestors, 4, 8, 1, 0, 6) {}

	char getChar() {
		return 'S';
	}
private:
	friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& boost::serialization::base_object<Animal>(*this);
		// ar& idCounter;
	}
};

int Sheep::idCounter = 0;

BOOST_CLASS_EXPORT_GUID(Sheep, "Sheep");