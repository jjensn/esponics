#!/bin/bash

docker run --rm -v "${PWD}":/config -it esphome/esphome esp_water_controller.yaml run
