docker run --rm -v "${PWD}":/config -it ghcr.io/esphome/esphome wizard sign.yaml

# Selected options:
# 1.  Name: technopark
# 2a. MC: ESP32
# 2b. Board: esp32dev
# 3a.  wifi: <name>
# 3b.  password: <pass>
# 4.  OTA pass: <pass>

# Note, the wifi name and passwords have been removed here and in the sign.yml
