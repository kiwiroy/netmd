CC=gcc
#CC=gcc-3.1
UTILS = utilities/hex-to-char utilities/char-to-hex
LIBRARY = libnetmd.o
LIB = libnetmd.0.1.so
APP = netmd
PEDANTIC = -Wall

app: $(APP)

pedantic: PEDANTIC = -Wall -ansi
pedantic: $(APP)

utils: $(UTILS)

lib: $(LIBRARY)
	$(CC) $(CFLAGS) -lm `libusb-config --libs` -shared -Wl,-soname,${LIB} -o ${LIB} $(LIBRARY)

docs: libnetmd.h
	doxygen Doxyfile

all: app utils

clean:
	rm -fr *~ *.o *.so* *.a $(APP) $(UTILS) $(LIB) $(LIBRARY) documentation/html documentation/latex

libnetmd.o: libnetmd.c libnetmd.h libnetmd_secure.c
	$(CC) -c ${INCLUDE} ${CFLAGS} -fPIC $<

netmd: netmd.c libnetmd.c libnetmd.h libnetmd_secure.c
	$(CC) $(PEDANTIC) -g -o netmd netmd.c libnetmd.c libnetmd_secure.c `libusb-config --libs`
