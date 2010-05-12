#ifndef HORIZON_SHIPENTITY_H
#define HORIZON_SHIPENTITY_H

#include <QObject>
#include <QString>

#include "shared/position.h"
#include "engine/physicsinfo.h"

class ShipEntity : public QObject
{
	Q_OBJECT;
	Q_PROPERTY(QString name READ name WRITE setName);
	Q_PROPERTY(Position  position READ position WRITE setPosition);
	Q_PROPERTY(PhysicsInfo physics READ physics WRITE setPhysics);

public:
	ShipEntity( QObject *parent = 0 );
	~ShipEntity();

signals:

public slots:
	/**
	 * Get the name of the ship
	 */
	QString name() const { return m_name; }
	
	Position position() const { return m_position; }
	PhysicsInfo physics() const { return m_physics; }

	/**
	 * Set the name of the ship
	 */
	void setName( const QString& name ) { m_name = name; }
	void setPosition( const Position& pos ) { m_position = pos; }
	void setPhysics( const PhysicsInfo& info ) { m_physics = info; }

private:
	QString     m_name;
	Position    m_position;
	PhysicsInfo m_physics;
};

#endif
