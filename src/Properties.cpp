#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "Properties.hpp"

std::map<std::string, std::string> properties;

Properties::Properties(std::string path) {
	std::ifstream inputStream = std::ifstream(path);

	int i = 0;
	std::string trimDelimiter = " ";
	std::string line;
	while (getline(inputStream, line)) {
		i++;

		try {
			// Skip comments
			if (line.find("#") == 0) {
				continue;
			}

			int delimiter = line.find("=");

			// If '=' missing than not a property
			if (delimiter < 0) {
				continue;
			}

			int start = 0;
			int end = 0;

			// Get key
			std::string key = line.substr(0, delimiter);
			start = key.find_first_not_of(trimDelimiter);
			end = key.find_last_not_of(trimDelimiter);

			key = key.substr(start, (end + 1));

			// get value
			std::string value = line.substr((delimiter + 1), line.length());
			start = value.find_first_not_of(trimDelimiter);
			end = value.find_last_not_of(trimDelimiter);

			value = value.substr(start, (end + 1));

			// Put in properties
			properties[key] = value;
		}
		catch (std::out_of_range &oor) {
			std::cout << "Error line " << i << ": " << line << std::endl << oor.what() << line << std::endl;
		}
	}
}

/**
 * @std::string property to retrieve
 *
 * @return value
 */
std::string Properties::get(std::string property) {
	return properties.at(property);
}

/**
 * @param std::string property to retrieve
 * @param std::string value to return if property not found
 *
 * @return value or defaultProperty if not found
 */
std::string Properties::get(std::string property, std::string value) {
	try {
		return properties.at(property);
	}
	catch (std::out_of_range &oor) {
		return value;
	}
}
