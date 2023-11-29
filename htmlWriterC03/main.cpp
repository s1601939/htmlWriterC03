/**
* \file main.cpp
* \brief TESTING file for an html Document class
* \author Stephen Graham
* \date   2023-11-29
**/
#include "Document.h"
#include <iostream>
#include <fstream>

int main() {
	using namespace std;
	
	{
		cout << "Test 1: Document default constructor & write()" << endl;
		Document dTest;
		dTest.write(cout);
		cout << "Test 1 complete\n" << endl;
	}

	{
		cout << "Test 2: Tag.writeTag() and Document.addTag()" << endl;
		Document dTest;
		Tag body("body");
		dTest.addTag(body);
		dTest.write(cout);
		cout << "Test 2 complete\n" << endl;
	}

	{
		cout << "Test 3: adding contents to a tag and Tag.writeTag()" << endl;
		Document dTest;
		Tag p("p");
		p.addContents("Hello world");
		dTest.addTag(p);
		dTest.write(cout);
		cout << "Test 3 complete\n" << endl;
	}

	{
		cout << "Test 4: adding Tag contents to a tag and Tag.writeTag()" << endl;
		Document dTest;
		Tag p("p");
		p.addContents("Hello world");
		Tag body("body");
		body.addContents(p);
		dTest.addTag(body);
		dTest.write(cout);
		cout << "Test 4 complete\n" << endl;
	}

	{
		cout << "Test 5: write full html document to a file test5.html\n";
		Document dTest;
		Tag html("html");
			Tag head("head");
				Tag title("title");
				title.addContents("This is the title contents for Test 5");
			head.addContents(title);
		html.addContents(head);
		
			Tag body("body");
				Tag h1("h1");
				h1.addContents("This is h1");
			body.addContents(h1);
			Tag p("p");
				p.addContents("Line 1");
			body.addContents(p);
		html.addContents(body);
		
		dTest.addTag(html);

		ofstream testFile ("test5.html");
		if (testFile.good()) dTest.write(testFile);
		testFile.close();
		cout << "Test 5 complete\n" << endl;
	}

}