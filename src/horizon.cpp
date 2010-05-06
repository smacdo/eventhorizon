#include <QCoreApplication>
#include <QTimer>
#include "horizon.h"

int main( int argc, char * argv[] )
{
	QCoreApplication app( argc, argv );
	QTimer::singleShot( 0, &app, SLOT(quit()) );
	return app.exec();
}
