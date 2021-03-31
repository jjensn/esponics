#!/bin/bash
FILE="${PWD}/_esp_water_controller.yaml"

if [ -f "$FILE" ]; then
    docker run --rm -v "${PWD}":/config -it esphome/esphome _esp_water_controller.yaml run 
else 
    docker run --rm -v "${PWD}":/config -it esphome/esphome esp_water_controller.yaml run
fi

