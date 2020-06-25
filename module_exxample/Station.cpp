#include "StationClass.hpp"

Station :: Station(string F)
{
	File = F;
	ifstream file(File);
	while(file >> s.codeS >> s.name)
            vs.push_back(s);
    file.close();
}