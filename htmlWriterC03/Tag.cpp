/**
* \file Tag.cpp
* \brief IMPLEMENTATION file for an html Tag class
* \author Stephen Graham
* \date   2023-11-29
**/
#include "Tag.h"
#include <string>
#include <vector>

// Constructors
Tag::Tag(std::string n) : tagName(n) {
	// intentionally blank
	// maybe we would throw InvalidTag() exception if not valid
}

// accessor
std::string Tag::writeTag() {
	std::string theOutputString;
	theOutputString += "<" + tagName + ">";
	
	// output the contents and children
	if (!tagContents.empty()) {
		theOutputString += tagContents;
	}
	else {
		theOutputString += "\n";
		for (Tag& t : tagChildren) {
			theOutputString += t.writeTag(); // WARNING recursion
		}
	}

	theOutputString += "</" + tagName + ">\n";
	return theOutputString;
}

// mutators
void Tag::addContents(std::string s) {
	// maybe want to encode or sanitise this string.
	tagContents = s;
}

void Tag::addContents(Tag t) {
	tagChildren.push_back(t);
}