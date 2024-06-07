#pragma once
#include "Plant.h"

#include <boost/serialization/access.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include <boost/serialization/export.hpp>

class Toadstool : public Plant {
private:
	static int idCounter;
public:
	Toadstool() {}

	Toadstool(std::list<Ancestor>* givenAncestors)
		: Plant(12, ("Toadstool" + std::to_string(++this->idCounter)), givenAncestors, 6, 8, true) {}

	char getChar() {
		return 'T';
	}
private:
	friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& boost::serialization::base_object<Plant>(*this);
		// ar& idCounter;
	}
};

int Toadstool::idCounter = 0;

BOOST_CLASS_EXPORT_GUID(Toadstool, "Toadstool");