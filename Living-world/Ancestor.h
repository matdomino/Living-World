#pragma once
#include <string>

#include <boost/serialization/access.hpp>


struct Ancestor {
	std::string organismId;
	int birthTurn;
	int deathTurn;

	Ancestor() {}

	Ancestor(const std::string& id, int birth, int death)
		: organismId(id), birthTurn(birth), deathTurn(death) {}

	friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& organismId;
		ar& birthTurn;
		ar& deathTurn;
	}
};