#include <cstdlib>

int generateRandom(int min, int max) {
	return min + rand() % (max - min + 1);
}