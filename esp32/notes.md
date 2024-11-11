# 2024-11-11

Hooked up the ESP32 to the sign, and got a number of things to work. The `light` component can address the LED strip, using the "WS2812x" variant driver and "RGB" color ordering. It's connected to PIN IO12 (which is in the same location as the pin 8 on the Arduino).

Furthermore, the `light` section can have multiple `partition` parts, so each letter has been assigned to a segment. They can now be controlled individually. However, the default color / gamma setting is odd. It looks purple/pink.

Also, the Addressable Light (display) component works (although, commented out right now). It is targeted towards a grid display, which is of course not quite what we have. However, that was interesting, was that we can import C++ code (see the top of the sign.yml file), so the old matrix we had could be used directly in the `pixel_mapper` config.

Note that, I think the letters N and O have been pushed in a rotated manner, so that the index no longer match up.

See (sign.yaml)[sign.yaml] for details and (esphome_web_ui.png)[esphome_web_ui.png] for the UI.


# 2024-11-08

First attempt with the ESP32. As of writing, not connected to the LED strip yet, but it works on the local wifi (and wired office network). (Note the replaced passwords and names in the sign.yml in this directory).

Also note, that these Docker based scripts cannot be used on a NFS based directory, so not over the NAS, home directory, etc.
