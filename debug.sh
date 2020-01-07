#!/bin/bash

# remove core and ignore warning
rm core -rf

for crash in `ls crashes`
do

    echo "crashes/$crash caused crash"
    ./dump-pe "crashes/$crash"
    if [ -f core ]
    then
        #echo "input: crashes/$crash" >> debug_out
        #gdb ./dump-pe core -q -batch -ex bt | head -3 >> debug_out
        #echo >> debug_out
        echo "############### input: crashes/$crash #########################" >> debug_out
        gdb ./dump-pe core -q -batch -ex bt | grep "#" | head -1 >> debug_out
        echo >> debug_out
        rm core
    fi
done
