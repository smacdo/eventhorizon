#include "model.h"

#include <QtCore>

void parseObjData( QTextStream& data )
{
	//
	// Read each line of the obj file
	//
	QString line;

	while ( data.readLine(line) && line.isNull() == false )
	{
		
	}
}

void parseMtlData( QTextStream& data )
{
	//
	// Read each line of the mtl file
	//
	QString line;

	while ( data.readLine(line) && line.isNull() == false )
	{
		// Trim whitespace, comments

		// What line is it?
		if ( line == "newmtl" )
		{
			// newmtl ...
		}
	}
}

void Model::loadModelFromObj( QTextStream& data )
{
	//
	// Tokenize the input data stream
	//
}
