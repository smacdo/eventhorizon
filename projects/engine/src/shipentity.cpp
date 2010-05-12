#include "engine/shipentity.h"
#include <QString>

ShipEntity::ShipEntity( QObject * parent )
	: QObject( parent ),
	  m_name( "[Untitled]" ),
	  m_position(),
	  m_physics( 2.5, 1.5, 5.0 )
{
}

ShipEntity::~ShipEntity()
{
}
