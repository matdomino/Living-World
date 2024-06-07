#pragma once
#include "Animal.h"

#include <boost/serialization/access.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include <boost/serialization/export.hpp>

class Wolf : public Animal {
private:
	static int idCounter;
public:
	Wolf() {}

	Wolf(std::list<Ancestor>* givenAncestors)
		: Animal(8, ("Wolf" + std::to_string(++this->idCounter)), givenAncestors, 4, 8, 0, 1, 6) {}

	char getChar() {
		return 'W';
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

int Wolf::idCounter = 0;
BOOST_CLASS_EXPORT_GUID(Wolf, "Wolf");