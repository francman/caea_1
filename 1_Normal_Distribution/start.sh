#!/bin/sh

#clean
make clean

#building C program
make

#Running Program
./histogram

#Plotting the data
gnuplot histogram_plot.p

#Plotting pmf
gnuplot pmf_plot.p
gnuplot pmf_plot2.p
