#include "BusClass.hpp"

Bus :: Bus(string F)
{
	File = F;
	ifstream file(File);
	while(file >> b.codeB >> b.model >> b.number >> b.bulk)
            vb.push_back(b); 
    file.close();
}