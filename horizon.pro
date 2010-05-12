#############################################################################
# Event Horizon QMake Project File                                          #
#                                                                           #
TEMPLATE = subdirs
SUBDIRS  = projects/engine projects/client
CONFIG  += ordered

client.depends = engine
