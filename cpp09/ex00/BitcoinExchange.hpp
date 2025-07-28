#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

class BitcoinExchange {
private:
	std::map<std::string, float> _rates;

	bool isValidDate(const std::string &date);
	bool isValidValue(const std::string &valStr, float &value);
	std::string trim(const std::string &str);

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	bool loadDatabase(const std::string &filename);
	void processInput(const std::string &filename);
};

#endif
