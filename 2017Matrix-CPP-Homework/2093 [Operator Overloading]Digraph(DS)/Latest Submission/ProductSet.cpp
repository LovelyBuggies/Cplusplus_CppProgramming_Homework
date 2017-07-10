 #include "Set.hpp"
#include "ProductSet.hpp"

ProductSet::ProductSet(Set a, Set b) : first(a),second(b) {
}
//constructor

Set ProductSet::getFirstSet() const{
	return first;
}
Set ProductSet::getSecondSet() const{
	return second;
}