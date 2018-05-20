#!/bin/bash

g++ -s -Os -lGL -std=c++17 -c *.cpp `pkg-config --cflags --libs gtk+-3.0` && \
g++ -s -Os -lGL -std=c++17 *.o `pkg-config --cflags --libs gtk+-3.0` -o screendimmer && \
echo 'done'
#./screendimmer start &
