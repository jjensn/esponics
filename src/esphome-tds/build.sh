#!/bin/bash
FILE="${PWD}/_esp_tds.yaml"

if [ -f "$FILE" ]; then
    docker run --rm -v "${PWD}":/config -it esphome/esphome _esp_tds.yaml run 
else 
    docker run --rm -v "${PWD}":/config -it esphome/esphome esp_tds.yaml run
fi

