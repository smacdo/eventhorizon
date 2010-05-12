#include <QCoreApplication>
#include <QTimer>
#include "horizon.h"

#include "shipentity.h"

int main( int argc, char * argv[] )
{
	QCoreApplication app( argc, argv );
	QTimer::singleShot( 0, &app, SLOT(quit()) );

	if ( QGLFormat::hasOpenGL() )
	{
		QMEssageBox::information( 0,
			"Event Horizon",
			"Your computer does not seem to support OpenGL :("
		);

		return -1;
	}
	
	ShipEntity ship;
	ship.setName("Scott");

	return app.exec();
}
