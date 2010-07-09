#include "eventhorizonclientapp.h"

#include <cassert>

using namespace Ogre;

EventHorizonClientApp::EventHorizonClientApp()
{
}

EventHorizonClientApp::~EventHorizonClientApp()
{
}

void EventHorizonClientApp::createScene()
{
    SceneNode *root = mSceneMgr->getRootSceneNode();
    assert( root != NULL );

    // Set lighting
    mSceneMgr->setAmbientLight( Ogre::ColourValue( 1.0, 1.0, 1.0 ) );

    //
    // Create the player's ship
    //
    Ogre::Entity* playerMesh = mSceneMgr->createEntity( 
        "PlayerShip", "razor.mesh" );
    Ogre::SceneNode* playerNode = root->createChildSceneNode("PlayerNode");

    playerMesh->setMaterialName("razor");

    playerNode->attachObject( playerMesh );
}

