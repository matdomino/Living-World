#pragma once
#include "Organism.h"

#include <boost/serialization/access.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include <boost/serialization/export.hpp>

class Plant : public Organism {
	protected:
		bool isPoisonous;
	public:
		Plant() : isPoisonous(0) {}

		Plant(int givenLifeSpan, std::string givenOrganismId, std::list<Ancestor>* givenAncestors, int givenReproducePower, int givenPowerLimit, bool givenPoisonousStatus)
			: Organism(givenLifeSpan, givenOrganismId, givenAncestors, givenReproducePower, givenPowerLimit), isPoisonous(givenPoisonousStatus) {}

		virtual char getChar() = 0;

		std::string getDetails() {
			return("Organism: " + this->organismId + "\n"
				+ "Power: " + std::to_string(this->power) + " (max: " + std::to_string(this->powerLimit) + ")" + "\n"
				+ "Minimal reproduce power level: " + std::to_string(this->reproducePower) + "\n"
				+ "Survived rounds: " + std::to_string(this->turnsSurvived) + " (lifespan: " + std::to_string(this->lifeSpan) + ")" + "\n"
				+ "Poisonous: " + std::to_string(this->isPoisonous) + "\n"
				);
		}

		virtual bool getPoisonousStatus() {
			return this->isPoisonous;
		}

		virtual void live() {
			if (this->powerLimit > this->power) {
				power++;
			}

			this->turnsSurvived++;
		}
private:
	friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& boost::serialization::base_object<Organism>(*this);
		ar& isPoisonous;
	}
};

BOOST_CLASS_EXPORT_GUID(Plant, "Plant");