#include "TripClass.hpp"

Trip :: Trip(string F)
{
	File = F;
	ifstream file(File);
	while(file >> t.codeT >> t.codeS >> t.codeB >> t.time )
            vt.push_back(t);
    file.close();
}