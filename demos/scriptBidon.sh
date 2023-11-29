#!/bin/bash

# Petit script qui se lance et va tourner à l'infini et afficher la date courrante
while true; do
    sleep 3
    date +"Le Process [$$] dit: La date courrante et temps est %F %T"
done
