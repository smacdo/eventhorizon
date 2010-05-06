#ifndef HORIZON_POSITION_H
#define HORIZON_POSITION_H

#include <QMetaType>
#include <QPoint>

struct Position
{
	Position()
		: center( QPoint() ), heading( QPoint() )
	{
	}

	Position( const QPoint& center, const QPoint& heading )
		: center( center ), heading( heading )
	{
	}

	QPoint center;
	QPoint heading;
};

Q_DECLARE_METATYPE( Position );

#endif
