#!/bin/bash

OUTDIR=bin-linux

if [ ! -d ${OUTDIR} ]; then
    mkdir ${OUTDIR}
fi

# build program
# 2 steps here as we need .o file to generate source listing + assembly code afterwards
g++ -g -I./ -c main.cpp -o ${OUTDIR}/main.o
g++ ${OUTDIR}/main.o -lpthread -pthread -o ${OUTDIR}/main.out

# generate assembly source listing
objdump -d -M intel -S ${OUTDIR}/main.o > ${OUTDIR}/main.s
