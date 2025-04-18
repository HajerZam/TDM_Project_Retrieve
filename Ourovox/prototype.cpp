#include <iostream>
#include <cstdlib>
#include <algorithm>

int main()
{
	std::string input;
	std::cout << "Type something for the bot to sing: ";
	std::getline(std::cin, input);
	
	// Adjust pitch (-p) and speed (-s) to make it more singy
	std::string inputLower = input;
	std::transform(inputLower.begin(), inputLower.end(), inputLower.begin(), ::tolower);

	// Check for scary words
	if (inputLower.find("the devine machine") != std::string::npos || 
        inputLower.find("disc 19") != std::string::npos || 
        inputLower.find("dr. sheraz") != std::string::npos) {
		std::string creepyLine = "don't...bring...it...up...in...MY PRESENCE...";
		std::string command = "espeak \"" + creepyLine + "\" -s 80 -p 30 -v en+f3"; // slower, lower pitch, female scary voice
											    system(command.c_str());
	}
	else
	{
		std::string command = "espeak \"" + input + "\" -s 120 -p 80";
		system(command.c_str());
	}
    return (0);
}
