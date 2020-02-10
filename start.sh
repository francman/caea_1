#!/bin/sh

#building C program
make

#Running Program
./histogram

#Plotting the data
gnuplot plot.p
