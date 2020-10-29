#!/usr/bin/env bash
#File: countFiles.sh
#Author: Ulises Magaña

FILENAME=$(ls BUNGEE_FILE_*.CSV)

if [[ $FILENAME ]]
then
    ls BUNGEE_FILE_* | wc -l &> NumberOfFiles.txt
else
    touch BUNGEE_FILE_1.CSV
    echo 0 > NumberOfFiles.txt
fi