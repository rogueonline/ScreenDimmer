#!/bin/bash

g++ -lGL -std=c++17 -c *.cpp `pkg-config --cflags --libs gtk+-3.0` && \
g++ -lGL -std=c++17 *.o `pkg-config --cflags --libs gtk+-3.0` -o screendimmer && \
echo 'done'
#./screendimmer start &
