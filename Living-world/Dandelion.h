#pragma once
#include "Plant.h"

#include <boost/serialization/access.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include <boost/serialization/export.hpp>


class Dandelion : public Plant {
private:
	static int idCounter;
public:
	Dandelion() {}

	Dandelion(std::list<Ancestor>* givenAncestors)
		: Plant(4, ("Dandelion" + std::to_string(++this->idCounter)), givenAncestors, 2, 4, false) {}

	char getChar() {
		return 'D';
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

BOOST_CLASS_EXPORT_GUID(Dandelion, "Dandelion");
int Dandelion::idCounter = 0;