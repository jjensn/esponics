# ESPonics 

###  Automated hydroponics with ESP8266 microcontrollers & Home Assistant

![Botanist Dr](https://raw.githubusercontent.com/jjensn/esponics/master/photos/botanist.jpeg)

![Grafana](https://raw.githubusercontent.com/jjensn/esponics/master/screenshots/grafana_1_small.png)

I absolutely want to credit Reddit user [u/ghoofman](https://www.reddit.com/user/ghoofman) for both the inspiration and build help. Without him none of this would have been possible. You can read his post and see pictures of his setup [here](https://www.reddit.com/r/Hydroponics/comments/llg8im/my_pandemic_hobby_getting_out_of_control/). He's also given me permission to post some of his 3D printable models, which I'll link later in the post. 

## Automation demo and dashboard screenshots:
- Dashboard ([top](https://raw.githubusercontent.com/jjensn/esponics/master/screenshots/dashboard_1.png) and [bottom](https://raw.githubusercontent.com/jjensn/esponics/master/screenshots/dashboard_2.png))
- Charting with Grafana
    - [Gauges](https://raw.githubusercontent.com/jjensn/esponics/master/screenshots/grafana_1.png)
    - [Trends and history](https://raw.githubusercontent.com/jjensn/esponics/master/screenshots/grafana_2.png)
- Sensor calibrations through Home Assistant UI
    - [pH](https://raw.githubusercontent.com/jjensn/esponics/master/screenshots/calibration_ph.png)
    - [Water level](https://raw.githubusercontent.com/jjensn/esponics/master/screenshots/calibration_water_level.png)
- [(Video) Changing nutrient flow based on solution temperature](https://streamable.com/u1edjl)

## Hydroponic closet photos:
- [Automation system](https://raw.githubusercontent.com/jjensn/esponics/master/photos/underside.jpeg)
- [Front view](https://raw.githubusercontent.com/jjensn/esponics/master/photos/electronics_fronton.jpeg)
- [1" PVC with TDS/water level/pH/float switch](https://raw.githubusercontent.com/jjensn/esponics/master/photos/water_sensor.jpeg)
- [Closet entrance](https://raw.githubusercontent.com/jjensn/esponics/master/photos/room.jpeg)
- [Grow rails](https://raw.githubusercontent.com/jjensn/esponics/master/photos/fence_posts.jpeg)
- [Lights + rails](https://raw.githubusercontent.com/jjensn/esponics/master/photos/posts_with_lights.jpeg)
- [Electric 'T' valve](https://raw.githubusercontent.com/jjensn/esponics/master/photos/bucket_and_valve.jpeg)
- [Piping to plants or chiller](https://raw.githubusercontent.com/jjensn/esponics/master/photos/plants_or_chiller.jpeg)
- [Refill diaphram pump](https://raw.githubusercontent.com/jjensn/esponics/master/photos/refill.jpeg)
- [Ebb & flow adjustable heights](https://raw.githubusercontent.com/jjensn/esponics/master/photos/outflow.jpeg)
- [Outflow tubing](https://raw.githubusercontent.com/jjensn/esponics/master/photos/outflow_bottom.jpeg)
- [Hot tub manifold 2"](https://raw.githubusercontent.com/jjensn/esponics/master/photos/hottub_manifold.jpeg)
- [Nutrient return to container](https://raw.githubusercontent.com/jjensn/esponics/master/photos/return.jpeg)
- [Adjustable lights using cargo rails](https://raw.githubusercontent.com/jjensn/esponics/master/photos/cargo_hooks_far.jpeg)
- [Cargo hooks (closer)](https://raw.githubusercontent.com/jjensn/esponics/master/photos/cargo_hooks_close.jpeg)
- [Timelapse camera](https://raw.githubusercontent.com/jjensn/esponics/master/photos/camera.jpeg)


## 3D models:
- [Peristaltic pump holders (credit to /u/ghoofman)](https://raw.githubusercontent.com/jjensn/esponics/master/models/gx/motor_mount_original.gx)
- [Peristaltic pump holders w/ mounts](https://raw.githubusercontent.com/jjensn/esponics/master/models/gx/motor_mount_with_brackets.gx)
- [pH bottle holder (credit to /u/ghoofman)](https://raw.githubusercontent.com/jjensn/esponics/master/models/gx/ph_holder.gx)
- [pH bottle caps with cable gland hole](https://raw.githubusercontent.com/jjensn/esponics/master/models/gx/ph_cap.gx)
- [1" PVC e-tape holder](https://raw.githubusercontent.com/jjensn/esponics/master/models/gx/1_in_etape_holder.gx)
- [TDS and pH probe holder for 1" PVC](https://raw.githubusercontent.com/jjensn/esponics/master/models/gx/ts_ph_probe_holder.gx)
- Buck converter case ([top](https://raw.githubusercontent.com/jjensn/esponics/master/models/gx/buck_converter_top.gx) / [bottom](https://raw.githubusercontent.com/jjensn/esponics/master/models/gx/buck_converter_bottom.gx))
- [Float switch holder](https://raw.githubusercontent.com/jjensn/esponics/master/models/gx/float_switch_holder.gx)
- SunFounder dual relay box ([top](https://raw.githubusercontent.com/jjensn/esponics/master/models/gx/dual_relay_top.gx) / [bottom](https://raw.githubusercontent.com/jjensn/esponics/master/models/gx/dual_relay_bottom.gx))


## Parts:
#### Sensors
- [DS18B20 Temperature Sensor Module Kit with Waterproof Stainless Steel Probe for Raspberry Pi](https://www.amazon.com/gp/product/B087JQ6MCP) 
- [Atlas Scientific Gravity Analog pH Kit](https://www.amazon.com/gp/product/B07VN8SKR7)
- [Gravity: Analog TDS Sensor/Meter for Arduino](https://www.dfrobot.com/product-1662.html)
- [Milone eTape 8"](https://milonetech.com/products/standard-etape-assembly)
- [Samsung GP-U999SJVLCAA SmartThings Water Leak Sensor - Automate Lights & Siren for Alert - ZigBee, Accessory Hub, White](https://www.amazon.com/gp/product/B07F951JDP)
- [Apple HomeKit Compatible Smart Home Temperature & Humidity Sensor Wireless Connection Detect Atmospheric Pressure Works with Apple HomeKit When Used with Aqara Hub](https://www.amazon.com/gp/product/B07JYSSST7)

#### Pumps & Valves
- [Peristaltic Pump Kamoer 12V DC DIY Liquid dosing Pump for Aquarium Lab Analytical 3mm ID x 5mm OD](https://www.amazon.com/gp/product/B07GWJ78FN)
- [IEIK Water Pressure Diaphragm Pump DC 12V Pressure Switch Sprayer Pump 5LPM 1.35 GPM 116PSI 165ft Self Priming Pump for Caravan RV Boat Marine Agricultural Spraying Port](https://www.amazon.com/gp/product/B072XLZX72)
- [HSH-Flo 3 Way 1/4" 3/8" 1/2" 3/4" 1" 12V/24VAC/DC 110-240VAC L Type Auto Return Brass Electrical On/Off Motorized Ball Valve (1/2 inch, 12V/24V AC/DC)](https://www.amazon.com/gp/product/B07GCZRD11)
- [MQ 330-800GPH Submersible Water Pump(20/30/40W) with Handle, Ultra Quiet Pump with High Lift, Fountain Pump with 2-3 Nozzles for Fish Tank, Pond, Aquarium, Hydroponics](https://www.amazon.com/gp/product/B07SMG6PLY)

#### Electronic Components
- [[2 Pack] DC-DC 5A Buck Converter 4-38V to 1.25-36V Step Down Voltage Regulator High Power Module with LED Display](https://www.amazon.com/gp/product/B085T73CSD)
- [12V 10 Amp Power Supply, FAVOLCANO DC 10A 120W Transformer, 5.5x2.1mm 5.5x2.5mm DC Output Jack for 3528 5050 5630 LED Lights Strips, 3D Printer, LED Driver, Laptop, CCTV Cameras](https://www.amazon.com/gp/product/B0814TV7J2)
- [SunFounder 2 Channel DC 5V Relay Module with Optocoupler Low Level Trigger Expansion Board for Arduino R3 MEGA 2560 1280 DSP ARM PIC AVR STM32 Raspberry Pi](https://www.amazon.com/gp/product/B00E0NTPP4)
- [HiLetgo 2pcs 5V One Channel Relay Module Relay Switch with OPTO Isolation High Low Level Trigger](https://www.amazon.com/gp/product/B00LW15A4W)
- [BN-LINK WiFi Heavy Duty Smart Plug Outlet, No Hub Required with Energy Monitoring and Timer Function, White, Compatible with Alexa and Google Assistant, 2.4 Ghz Network Only (2 Pack)](https://www.amazon.com/gp/product/B07CVPKD8Z)
- [GoControl CECOMINOD016164 HUSBZB-1 USB Hub](https://www.amazon.com/gp/product/B01GJ826F8)
- [Smart Plug, Power Strip, AHRISE WiFi Surge Protector（1680 Joules with 4 Smart Outlets and 4 Always on outlets and 4 USB Ports(Smart 4.8A 24W Total), 6ft Extension Cord, 1875W/15A, Black](https://www.amazon.com/gp/product/B07WGN3X5F)
- [Mini PC](https://www.amazon.com/Version%E3%80%91-Celeron-Windows-Fanless-Ethernet/dp/B07ZSC61TG)
- [HiLetgo 3pcs ESP8266 NodeMCU CP2102 ESP-12E Development Board Open Source Serial Module Works Great for Arduino IDE/Micropython (Large)](https://www.amazon.com/gp/product/B081CSJV2V)

#### Hardware
- [Cable Glands](https://www.amazon.com/gp/product/B07GJDYGP5)
- [XLX 12pcs (6 Set) 600V 15A 6 Positions Double Row Screw Terminal Strip and 400V 15A 6 Positions Red/Black Pre-Insulated Terminal Barrier Strip](https://www.amazon.com/gp/product/B01M7NT4VI)
- [Quickun Pure Silicone Tubing, 3mm ID x 5mm OD High Temp Food Grade Tube Pure Silicone Hose Tube for Home Brewing, Beer Line, Kegerator, Wine Making, Aquaponics, Air Hose by Proper Pour (16.4 Ft)](https://www.amazon.com/gp/product/B0852HXPN6)
- [US Cargo Control Black L Track – 6 Inch Length – Perfect for Securing Motorcycles, ATVs, Dirt Bikes, Utility Tractors, and More – Use On Pickup Trucks, Vans, Or Enclosed Trailers - 4 Pack](https://www.amazon.com/gp/product/B07WBZGD6B)
- [MOTO4U Single Stud Fitting Tie Down Anchor Quick Release Ring Spring Bolt L Track Fitting Airline Track (4Packs)](https://www.amazon.com/gp/product/B07K9QDNZV)
- [Waterway Plastics 806105121288 2" S X Dead End (4) 3/4" Rib Barb Manifold](https://www.amazon.com/gp/product/B004VTG51Y)
- [RAINPAL BBF020 Lead Free Compliant Brass Bulkhead Tank Fitting (Double Female 1/2” NPT and Male 3/4" NH Garden Hose Threaded) (5)](https://www.amazon.com/gp/product/B01HLBTX12)
- [Flantor Garden Hose Splitter, Heavy Duty Garden Hose Connector with 4 Shut-Off Valves 3/4, Outdoor Faucet with 3/4 Connector,Water Manifold Connector for Drip Irrigation Systems (4 Way)](https://www.amazon.com/gp/product/B07S7DBP2G)


#### Other
- [Level Sense 15 Feet Water Level Float Switch with Mounting Bracket](https://www.amazon.com/gp/product/B01A4RZULM)
- [Hank Z-Wave Plus Four Button Scene Controller HKZW-SCN04, White, Works with SmartThings (with custom handler)](https://www.amazon.com/gp/product/B0799SF1KC)
- [Atlas Scientific pH 4.00, 7.00, 10.00 Calibration Solution 125ml - 4oz (Pack of 3)](https://www.amazon.com/gp/product/B0063MWYMQ)
- [eSUN PLA PRO (PLA+) 3D Printer Filament, Dimensional Accuracy +/- 0.03mm, 1kg Spool, 1.75mm, Black](https://www.amazon.com/gp/product/B01EKEMDA6)
- [Webcam with Microphone for Desktop Laptop, Foscam 1080P HD USB Streaming Web Cam for Conference, Gaming, Courses, Flexible Mount, Privacy Cover Inlcuded, Business Grade](https://www.amazon.com/gp/product/B088LW8MZP)

