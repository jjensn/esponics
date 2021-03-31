#!/bin/bash
FILE="${PWD}/_esp_ph.yaml"

if [ -f "$FILE" ]; then
    docker run --rm -v "${PWD}":/config -it esphome/esphome _esp_ph.yaml run 
else 
    docker run --rm -v "${PWD}":/config -it esphome/esphome esp_ph.yaml run
fi

