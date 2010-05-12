#############################################################################
# Event Horizon QMake Project File                                          #
#                                                                           #
#===========================================================================#
#  Project headers and source code list                                     #
#===========================================================================#
HEADERS   = include/horizon.h   \
            include/coredefs.h  \
            include/gameentity.h \
            include/shipentity.h \
	    include/physicsinfo.h \
	    include/position.h
SOURCES   = src/horizon.cpp     \
            src/shipentity.cpp  \
            src/gameentity.cpp

#===========================================================================#
#   Project configuration options                                           #
#===========================================================================#
TEMPLATE  = app
TARGET    = horizon
CONFIG   += qt warn_on debug thread

QT       -= gui
QT       += network xml sql 

DEFINES  +=

#===========================================================================#
#   Misc. project settings                                                  #
#===========================================================================#
INCLUDEPATH += include/
OBJECTS_DIR = .build/
DESTDIR   = dist
#FORMS     = ui
#RESOURCES =
