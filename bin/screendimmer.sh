#!/bin/bash

if [[ $(ps aux | grep 'screendimmer start' | wc -l) < 2 ]]; then
	/opt/screendimmer/screendimmer start &
else
	/opt/screendimmer/screendimmer stop
fi
