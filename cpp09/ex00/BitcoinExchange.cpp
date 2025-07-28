#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
	: _rates(other._rates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		this->_rates = other._rates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}



bool BitcoinExchange::loadDatabase(const std::string &filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		return false;

	std::string line;

	while (std::getline(file, line)) {
		if (line == "date,exchange_rate")
			continue;
		std::istringstream ss(line);
		std::string date, rateStr;
		if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
			float rate = static_cast<float>(std::atof(rateStr.c_str()));
			_rates[trim(date)] = rate;
		}
	}
	return true;
}

void BitcoinExchange::processInput(const std::string &filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;

	while (std::getline(file, line)) {
		if (line == "date | value")
			continue;
		size_t pipe = line.find('|');
		if (pipe == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, pipe));
		std::string valueStr = trim(line.substr(pipe + 1));

		float value;
		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (!isValidValue(valueStr, value)) {
			continue;
		}

		std::map<std::string, float>::const_iterator it = _rates.lower_bound(date);
		if (it == _rates.end() || it->first != date) {
			if (it == _rates.begin()) {
				std::cerr << "Error: no earlier date found." << std::endl;
				continue;
			}
			--it;
		}

		float result = value * it->second;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
}

bool BitcoinExchange::isValidDate(const std::string &date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;

	int year, month, day;
	char dash1, dash2;
	std::istringstream ss(date);
	if (!(ss >> year >> dash1 >> month >> dash2 >> day)) return false;
	if (dash1 != '-' || dash2 != '-') return false;

	if (month < 1 || month > 12 || day < 1 || day > 31) return false;
	return true;
}

bool BitcoinExchange::isValidValue(const std::string &valStr, float &value) {
	std::istringstream ss(valStr);
	ss >> value;
	if (ss.fail() || !ss.eof()) {
		std::cerr << "Error: bad input => " << valStr << std::endl;
		return false;
	}
	if (value < 0.0f) {
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000.0f) {
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

std::string BitcoinExchange::trim(const std::string &str) {
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");
	if (start == std::string::npos || end == std::string::npos) return "";
	return str.substr(start, end - start + 1);
}
