#############################################################################
# Event Horizon Client QMake Project                                        #
#############################################################################
! include( ../../common.pri ) {
	error( Could not find the common.pri file! )
}

#===========================================================================#
#  Project headers and source code list                                     #
#===========================================================================#
HEADERS   = include/client/model.h
SOURCES   = src/horizonclient.cpp     \
            src/model.cpp  \

#===========================================================================#
#   Project configuration options                                           #
#===========================================================================#
TEMPLATE  = app
CONFIG   += qt warn_on debug thread

QT       -= gui
QT       += network xml sql 

DEFINES  +=

LIBS     += -L../../dist -lengine
PRE_TARGETDEPS += ../../dist/libengine.a

#===========================================================================#
#   Misc. project settings                                                  #
#===========================================================================#
INCLUDEPATH += include/ ../shared/include ../engine/include
