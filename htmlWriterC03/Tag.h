/**
* \file Tag.h
* \brief INTERFACE file for an html Tag class
* \author Stephen Graham
* \date   2023-11-29
**/
#pragma once
#include <string>
#include <vector>
class Tag
{
private:
	std::string tagName;
	std::string tagContents;
	std::vector<Tag> tagChildren;
public:
	// Tag();  // NO default constructor provided!
	Tag(std::string n); /// constructor sets the tagName = n

	/**
	* writeTag() converts the tag and its contents to a string
	* \return    string version of the tag and its contents
	**/
	std::string writeTag();

	/**
	* addContents() set the content for the current Tag
	* \param     s string the contents for the tag
	* \post      the tagContents = s
	**/
	void addContents(std::string s);
	/**
	* addContents() set the content for the current Tag
	* \param     t Tag contents for the tag
	* \post      the tagChildren has t appended
	**/
	void addContents(Tag t);
};

