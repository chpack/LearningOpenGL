#!/bin/bash
if [ "$1" == 'd' ]; then
    make debug 
else
    make run
fi


