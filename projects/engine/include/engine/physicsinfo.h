#ifndef HORIZON_PHYSICSINFO_H
#define HORIZON_PHYSICSINFO_H

#include <QMetaType>

struct PhysicsInfo
{
	PhysicsInfo()
		: velocity( 0.0f ),
		  acceleration( 0.0f ),
		  mass( 0.0f )
	{
	}

	PhysicsInfo( float v, float a, float m )
		: velocity( v ),
		  acceleration( a ),
		  mass( m )
	{
	}

	float velocity;
	float acceleration;
	float mass;
};

Q_DECLARE_METATYPE( PhysicsInfo );

#endif
