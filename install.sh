#!/bin/bash
wget "https://raw.githubusercontent.com/torry2/lasttime/main/lasttime.cpp" 
g++ lasttime.cpp -o lasttime
mv lasttime /usr/local/bin/
rm lasttime.cpp
