#!/bin/bash

# Petit script qui se lance et va tourner à l'infini et afficher la date courrane
while true; do
    sleep 3
    date +"The Process [$$] says: The current date and time is %F %T"
done
