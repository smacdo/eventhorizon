#############################################################################
# Event Horizon Client QMake Project                                        #
#############################################################################
! include( ../../common.pri ) {
	error( Could not find the common.pri file! )
}

#===========================================================================#
#  Project headers and source code list                                     #
#===========================================================================#
HEADERS   = include/engine/gameentity.h \
            include/engine/shipentity.h \
            include/engine/physicsinfo.h
SOURCES   = src/gameentity.cpp          \
            src/shipentity.cpp

#===========================================================================#
#   Project configuration options                                           #
#===========================================================================#
TEMPLATE  = lib
CONFIG   += qt warn_on debug thread staticlib

QT       -= gui
QT       += network xml sql 

DEFINES  +=

#===========================================================================#
#   Misc. project settings                                                  #
#===========================================================================#
INCLUDEPATH += include/ ../shared/include
TARGET      = engine
