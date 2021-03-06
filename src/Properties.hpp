#ifndef PROPERTIES_HPP
#define PROPERTIES_HPP

#include <iostream>
#include <map>
#include <string>

class Properties {
	public:
		Properties(std::string path);
		std::string get(std::string property);
		std::string get(std::string property, std::string value);
	private:
		std::map<std::string, std::string> property;
};

#endif
