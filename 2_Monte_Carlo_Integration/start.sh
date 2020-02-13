#!/bin/sh

#clean
make clean

#building C program
make

#remove object files
rm *.o
