#!/bin/sh
# You can consider this file as being in the public domain.

# Determine the location of the BUILD folder
if test -d ../../../BUILD/contrib/zipios
then
	BUILD=../../../BUILD/contrib/zipios
else
	BUILD=../BUILD/zipios
fi

if test "$1" = "-d"
then
	# Force a rebuild of the documentation
	#
	rm -rf ${BUILD}/doc/zipios-doc-2.0*
	make -C ${BUILD} zipios_Documentation
	make -C ${BUILD} install
else
	make -C ${BUILD}
fi
