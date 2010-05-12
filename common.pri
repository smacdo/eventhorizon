#Includes common configuration for all subdirectory .pro files.
#INCLUDEPATH += include
WARNINGS += -Wall

# The following keeps the generated files at least somewhat separate 
# from the source files.
#UI_DIR = uics
UI_DIR  = .build/ui
MOC_DIR = .build/mocs
OBJECTS_DIR = .build/objs
DESTDIR = ../../dist/
