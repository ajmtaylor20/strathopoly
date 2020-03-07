#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int getPropertyData()
{
	
	std::vector<Space*> spaces;
	
	std::ifstream infile("properties.csv");
	
	/*TRACK ROW SO ROW 0 CAN BE AVOIDED*/
	int row = 0;
	while (infile)
	{
		/*CREATE BUFFER STRING*/
		std::string datastring;
		
		if (!std::getline(infile, datastring)) {break;} //if getline fales, break the loop
		
		/*CREATE STRING STREAM FROM BUFFER STRING*/
		std::istringstream strStream(datastring);
		
		/*CREATE NEW OBJECT AND START AT COLUMN 0*/
		Space* temp = new Space;
		int column = 0;
		
		/*FOR THE DuRATION OF THE STRING STREAM*/
		while (strStream)
		{
			std::string datastring;
			if(!std::getline(strStream, datastring, ',')) {break;}	//break datastring up by comma
			
			/*IGNORE ROW 0 AS IT CONTAINS LABELS*/
			if (row != 0)
			{
				/*READ DATA FROM EACH COLUMN AND UPDATE TEMP OBKECT*/
				switch(column)
				{
					case 0:	temp->name = datastring; std::cout << datastring; break;
					case 1: temp->type = datastring; break;
					case 2: temp->description = datastring; break;
					case 3: temp->rent = std::stoi(datastring); break;
					case 4: temp->price = std::stoi(datastring); break;
				}
				column++;
			}else{;/*do nothing with label row*/}
		}
		
		if( row != 0){spaces.push_back(temp);} /*STOP ROW 0 FROM STORING A GARBAGE OBJECT. OTHERWISE PUSH ONTO VECTOR*/
		row++;
	}
	
	return 0;
}