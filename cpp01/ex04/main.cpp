/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 05:27:44 by soksak            #+#    #+#             */
/*   Updated: 2025/01/09 06:34:17 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

static std::string read_file(std::string &filename)
{
    std::ifstream inputFile((filename).c_str());
	std::ostringstream buffer;
    std::string line;

	if (inputFile.good())
	{
		buffer << inputFile.rdbuf();
		inputFile.close();
		return (buffer.str());
	}
	else
	{
		std::cout << "Unable to open file" << std::endl;
		return ("");
	}
}

static void replace_and_write(std::string &filename, std::string &s1, std::string &s2, std::string &read_content)
{
	std::ofstream outputFile((filename + ".replace").c_str());
	std::string content;
	size_t pos = 0;
	size_t found;

	if (!outputFile.good())
	{
		std::cout << "Unable to create " << filename <<".replace file." << std::endl;
		return ;
	}
	while ((found = read_content.find(s1, pos)) != std::string::npos)
	{
		content.append(read_content, pos, found - pos);
		content.append(s2);
		pos = found + s1.length();
	}
	content.append(read_content, pos);
	outputFile << content;
	outputFile.close();
}

int main(int ac, char **av)
{
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
	std::string read_content;

    if (ac != 4)
    {
        std::cout << "Usage: ./replace [filename] [s1] [s2]" << std::endl;
        return (1);
    }
	else
	{
		if (s1.empty() || s2.empty())
		{
			std::cout << "s1 and s2 can not be empty." << std::endl;
			return (1);
		}
		read_content = read_file(filename);
		if (read_content.empty())
			return (1);
		replace_and_write(filename, s1, s2, read_content);
		return (0);
	}
}
