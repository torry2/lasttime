#!/bin/bash
wget "https://raw.githubusercontent.com/torry2/lasttime/main/lasttime.cpp" 
g++ lasttime.cpp -o lt
sudo mv lt /usr/local/bin/
rm lasttime.cpp
