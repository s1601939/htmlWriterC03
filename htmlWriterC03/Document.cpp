/**
* \file Document.cpp
* \brief IMPLEMENTATION file for an html Document class
* \author Stephen Graham
* \date   2023-11-29
**/
#include "Document.h"
#include <vector>
#include <string>
#include <fstream>

// Constructors
Document::Document() {
 // intentionally blank
}

// Mutators
void Document::addTag(Tag t) {
	tags.push_back(t);
}

// other
bool Document::write(std::ostream& ofs) {
	ofs << "<!DOCTYPE html>" << std::endl;
	for (auto tagNum = 0; (tagNum < tags.size()) && ofs.good(); tagNum++) {
		ofs << tags.at(tagNum).writeTag() << std::endl;
	}
	return ofs.good();
}