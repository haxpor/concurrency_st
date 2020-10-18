#!/bin/bash

OUTDIR=bin-linux

if [ ! -d ${OUTDIR} ]; then
    mkdir ${OUTDIR}
fi

# build shared library (.so)
g++ -O2 -g -shared -fPIC -I./ lib.cpp -o ${OUTDIR}/liblib.so

# build main program linking with built .so file
g++ -O2 -g -I./ -c main.cpp -o ${OUTDIR}/main.o
g++ ${OUTDIR}/main.o -L${OUTDIR}/ -llib  -o ${OUTDIR}/main.out

# generate assembly + source list from .o file
objdump -d -M intel -S ${OUTDIR}/main.o > ${OUTDIR}/main.s
