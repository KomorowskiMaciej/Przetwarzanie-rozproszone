#!/bin/bash
g++ main.cpp
./a.out &
sleep 2
ps -u mac -l --forest