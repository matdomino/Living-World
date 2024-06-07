#pragma once
#include "Plant.h"

#include <boost/serialization/access.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include <boost/serialization/export.hpp>

class Grass : public Plant {
private:
	static int idCounter;
public:
	Grass() {}

	Grass(std::list<Ancestor>* givenAncestors)
		: Plant(7, ("Grass" + std::to_string(++this->idCounter)), givenAncestors, 3, 3, false) {}

	char getChar() {
		return 'G';
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

BOOST_CLASS_EXPORT_GUID(Grass, "Grass");
int Grass::idCounter = 0;