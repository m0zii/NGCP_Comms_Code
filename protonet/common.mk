# This is an automatically generated record.
# The area between QNX Internal Start and QNX Internal End is controlled by
# the QNX IDE properties.

ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

#===== USEFILE - the file containing the usage message for the application. 
USEFILE=

# Next lines are for C++ projects only

EXTRA_SUFFIXES+=cxx cpp

#===== LDFLAGS - add the flags to the linker command line.
LDFLAGS+=-lang-c++ -lsocket

VFLAG_g=-gstabs+

#===== EXTRA_INCVPATH - a space-separated list of directories to search for include files.
EXTRA_INCVPATH+=$(PROJECT_ROOT)/include

#===== EXTRA_SRCVPATH - a space-separated list of directories to search for source files.
EXTRA_SRCVPATH+=$(PROJECT_ROOT)/src  \
	$(PROJECT_ROOT)/src/message

#===== LIBS - a space-separated list of library items to be included in the link.
LIBS+=^socket

#===== CCFLAGS - add the flags to the C compiler command line. 
CCFLAGS+=-lsocket

#===== POST_BUILD - extra steps to do after building the image.
define POST_BUILD
-$(if $(filter AR, $(BUILD_TYPE)), @$(CP_HOST) $(BUILDNAME) $(PROJECT_ROOT_protonet)/../build/qnx/)
endef

include $(MKFILES_ROOT)/qmacros.mk
ifndef QNX_INTERNAL
QNX_INTERNAL=$(PROJECT_ROOT)/.qnx_internal.mk
endif
include $(QNX_INTERNAL)

postbuild:
	$(POST_BUILD)

include $(MKFILES_ROOT)/qtargets.mk

OPTIMIZE_TYPE_g=none
OPTIMIZE_TYPE=$(OPTIMIZE_TYPE_$(filter g, $(VARIANTS)))

