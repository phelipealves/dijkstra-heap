#!/usr/bin/gnuplot

#set encoding iso_8859_1
set encoding utf8
set terminal postscript eps color solid enhanced 11

set size 0.75,0.5
set rmargin 2.1
set lmargin 7.1

set xrange [0:265000]
set yrange [0:12]

set xlabel "Número da Iteração"
set ylabel "Altura da fila de prioridade" offset 1.5,0

#set key outside;
#set key top right Left reverse;
set key at 265000,11;

set output "./graph_h.eps"

plot './out.ci' u 1:4:5 t "Altura da fila" w errorb lt 3 lw 1.5 ps 0.7
