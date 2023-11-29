/**
* \file Document.h
* \brief INTERFACE file for an html Document class
* \author Stephen Graham
* \date   2023-11-29
**/
#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Tag.h"

class Document
{
private:
	std::vector<Tag> tags;
public:
	// Constructors
	Document(); // default constructor

	// mutators
	/**
	* addTag() adds a new tag to the document
	* \param t	the tag to be added 
	* \postcondition	the tags vector contains t
	**/
	void addTag(Tag t);

	/**
	* write()   exports the entire document to the specified stream
	* \param    ofs - some output stream of type ostream&
	* \pre		ofs is in a good state
	* \post		ofs has received all the tags in the document
	* \return   bool true if the write operation was successful
	**/
	bool write(std::ostream& ofs);
};

