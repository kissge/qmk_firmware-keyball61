# Build Guide for Keyball39

This is the build guide for Keyball39.

Keyball39 is a 40% split keyboard with integrated 100% useful thumb trackball.

●[日本語のビルドガイドはこちら](https://github.com/Yowkees/keyball/blob/main/keyball39/doc/rev1/buildguide_jp.md)です。
  

![01](images/kb39_001.jpg)

## [Contents of Build Guide for Keyball39]

- [Build Guide for Keyball39](#build-guide-for-keyball39)
  - [\[Contents of Build Guide for Keyball39\]](#contents-of-build-guide-for-keyball39)
  - [1. Parts Check](#1-parts-check)
    - [1-1. Items included in the kit](#1-1-items-included-in-the-kit)
    - [1-2. Parts to be prepared by customers themselves before assembly](#1-2-parts-to-be-prepared-by-customers-themselves-before-assembly)
    - [1-3. Parts and options that can be installed even after assembled.](#1-3-parts-and-options-that-can-be-installed-even-after-assembled)
  - [2. Preparation](#2-preparation)
    - [2-1. Required tools](#2-1-required-tools)
  - [3. Mounting parts](#3-mounting-parts)
    - [3-1．Before soldering](#3-1before-soldering)
    - [3-2. Soldering the diodes](#3-2-soldering-the-diodes)
    - [3-3．Soldering the key socket](#3-3soldering-the-key-socket)
    - [3-4．Soldering the jumpers](#3-4soldering-the-jumpers)
    - [3-5．4-pin Socket, TRRS Socket, Tact Switch](#3-54-pin-socket-trrs-socket-tact-switch)
    - [3-6．Soldering the ProMicro](#3-6soldering-the-promicro)
    - [3-7．3-7．Writing firmware to ProMicro and Electric checking](#3-73-7writing-firmware-to-promicro-and-electric-checking)
    - [3-8．Soldering the LEDs (optional)](#3-8soldering-the-leds-optional)
  - [4. Assemble the ball-reading board](#4-assemble-the-ball-reading-board)
  - [4-1．Soldering the optical sensor](#4-1soldering-the-optical-sensor)
    - [4-2．Soldering the L-shaped conthrough pin header](#4-2soldering-the-l-shaped-conthrough-pin-header)
  - [5．Solder the left/right decision jumper on the left hand side](#5solder-the-leftright-decision-jumper-on-the-left-hand-side)
  - [6. Cutting of top plate](#6-cutting-of-top-plate)
  - [7. Assembly](#7-assembly)
    - [7-1. Mounting the Protection Plates](#7-1-mounting-the-protection-plates)
    - [7-2. Assembling the top plates](#7-2-assembling-the-top-plates)
    - [7-3. Assembling the bottom plates](#7-3-assembling-the-bottom-plates)
  - [8. Trackball installation](#8-trackball-installation)
    - [8-1. Insert the trackball reading board](#8-1-insert-the-trackball-reading-board)
    - [8-2. Assemble the trackball case](#8-2-assemble-the-trackball-case)
    - [8-3. Trackball case installation](#8-3-trackball-case-installation)
  - [9. Total finish](#9-total-finish)
  - [10. Write the regular firmware](#10-write-the-regular-firmware)
  - [11. How to use Keyball](#11-how-to-use-keyball)

<a id="1"></a>
## 1. Parts Check

When you receive your kit, please make sure whether all the items included in the kit.

<a id="1-1"></a>
###  1-1. Items included in the kit

The Keyball39 Standard set has one Trackball that can be attached on Right or Left side.

Included parts in the Keyball39 Standard Kit are the following

| Name | Number | Note |
|:-|:-|:-|
| Middle PCBs (left and right) | 1 set | |
| Top PCB plates (left and right) | 1 set | |
| Middle Acrylic plates (left and right) | 1 set | Main and Thumb plates |
| Bottom Acrylic plates (left and right) | 1 set | |
| ProMicro protection plate (left and right) | 1 set ||
| Trackball holding case white (top and bottom) | 1 set ||
| Φ2 Ceramic ball (spare) | 1 pcs ||
| Trackball reader circuit board | 1 plate ||
| Trackball readout IC | 1 pcs ||
| Lense for Trackball readout IC | 1 pcs ||
| L-shaped Conthrough pin (7-pin) | 1 pcs ||
| Flat head screw M1.7 | 2 pcs ||
| Small head screw M1.7 | 2 pcs ||
| TRRS Jack | 2 pcs ||
| Tact Switch | 2 pcs ||
| Straight Conthrough pin (12-pin) | 4 pcs ||
| Diodes (Surface mounting type) | more 50 pcs ||
| Kailh PCB Socket for Cherry MX | more 42 pcs ||
| Kailh PCB Socket for choc | 5 pcs | For Thumb low-profile modification |
| OLED module | 2 pcs ||
| Pin header (4 pin) | 2 pcs ||
| Pin socket (4 pin) | 2 pcs ||
| Spacer M2 7mm | more 13 pcs ||
| Spacer M2 9mm | 4 pcs ||
| Spacer M2 5mm | 5 pcs | For Thumb low-profile modification |
| Screws M2 3.5mm | more 34 pcs + ||
| Cushion rubber | 8 pcs ||


![02](images/kb39_007.jpg)

<a id="1-2"></a>
### 1-2. Parts to be prepared by customers themselves before assembly

The following are the parts you need to prepare before assembly.

| Name | Number | Note |
|:-|:-|:-|
| ProMicro | 2 pcs | You can choose from inexpensive ones or USB Type-C supported ones. |
| CherryMX Compatible Key Switches | 39 pcs | 34 pcs for Thumb low-profile |
| Low-profile choc Key Switches | 5 pcs | For Thumb low-profile |
| Trackball (34mm diameter) | 1 pc | Used to check operation |
| TRS (3-pole) cable | 1 cable | TRRS (4-pole) cable is also acceptable |
| Micro USB cable | 1 cable | Compatible with ProMicro you purchased |

![03](images/kb39_003.jpg)

<a id="1-3"></a>
### 1-3. Parts and options that can be installed even after assembled.

| Name | Number | Note |
|:-|:-|:-|
| CherryMX Compatible Keycaps | 39 pcs | 1U size 39 pcs |
| Low-profile choc Keycaps | 5 pcs | For Thumb low-profile |
| YS-SK6812MINI-E | 46 pcs | (Optional) *Notice: Cannot be used with SK6812MINI. |
| 名前 | 数 | 備考 |

![04](images/kb39_004.jpg)

<a id="2"></a>
## 2. Preparation

<a id="2-1"></a>
### 2-1. Required tools

You will need the following tools to assemble the Keyball39.

| Name |
|:-|
| Soldering iron (with adjustable temperature if you are mounting LEDs) |
| Solder (low melting point is effective when mounting LEDs) |
| Nippers |
| No. 0 + precision screwdriver |
| Tweezers |
| Sandpaper of about 150-grit |

![05](images/kb39_005.jpg)

<a id="3"></a>
## 3. Mounting parts

Now it's time to start the soldering process.  
The PCB is reversible, so you first need to decide which one is for the left hand and which one is for the right hand.  

The trackball will be attached to the PCB missing position, indicated by the red circle.  
If you want to use your right thumb to control the trackball, Placement will look like the picture below. 

![20](images/kb39_010.jpg)

If you operate the trackball with your left hand, Placement is as shown in the picture below. 

![21](images/kb39_011.jpg)

In this build guide, we will use the specification to put the trackball on the right hand.  
Place the PCB as shown below, and put masking tape on the surface to prevent mistakes.
I wanted to write "TOP FACE" on masking tape.

![22](images/kb39_012.jpg)

<a id="3-1"></a>
### 3-1．Before soldering
The tip of the soldering iron should be shaped like a bamboo spear, so that you can put solder on a flat surface and scoop out excess solder.

![27](images/kb39_027.jpg)

<a id="3-2"></a>
### 3-2. Soldering the diodes
Now let's solder the diodes one by one.  
All the diodes should be soldered on 【BACK SIDE ONLY】.
  
The silk marks on the diodes look like the arrows in the picture below. There are 45 diodes in total.  
Diodes have polarity, so be sure to install them in the correct orientation. The orientation is the direction where the straight line on the component matches the straight line on the end of the arrow on the silk mark.  
  
Look carefully at the picture below to confirm the orientation.  
All the diodes on the same board are oriented in the same direction, except for the diodes that are rotated 90 degrees. As you proceed with the soldering, make sure that the diodes are facing the same direction as the diodes around them.

![25](images/kb39_014.jpg)
  
The diode silk is marked with a black dot as shown in red in the following photo. So you can check the polarity even after the diode is soldered.

![26](images/kb39_015.jpg)

Now let's start soldering. At first, put some solder on one side of the diode pad.

![28](images/kb39_020.jpg)

Grab the diode with tweezers and hold it in place while you melt the solder that was previously applied.

![30](images/kb39_028.jpg)

Rotate the board 180 degrees and apply solder to the legs on the other side of the diode.
Finally, touch both legs with a soldering tip, and if the diode does not fall out, both legs are soldered.

![反対の足も半田付け](images/kb39_029.jpg)

Install a total of 45 diodes on the left and right sides.

![37](images/kb39_030.jpg)

<a id="3-3"></a>
### 3-3．Soldering the key socket
The key socket is soldered on the 【BACK SIDE】 as diodes.

Set the key socket. Key socket's shape matches the silk mark, and solder it.  
If it protrudes from the silk, the direction is wrong.

![85](images/kb39_075.jpg)

When assembling with thumb low-profile specifications, solder low-profile sockets to the thumb keys (Total 5 keys). This low-profile socket also has a direction.

Please confirm the direction with the following pictures. The correct direction is that the terminal with the black plastic part close to the octagonal shape is near the middle of the switch.

![85](images/kb39_077.jpg)

Solder the pad to the socket as shown in the blue circle.

![86](images/kb39_078.jpg)

If you apply a tip with a little solder on it from the side of the terminal and hold the socket by tweezers from above, the solder will melt and the socket will sink.  
In my experience, this method is the least likely to result in a poor connection.  

![87](images/kb39_079.jpg)

Rotate the board 180 degrees and solder the terminals on the other side in the same way.

45 of these are soldered on the left and right sides together, This task is finished.
The PCB socket for the thumb keys can be just either a CherryMX compatible socket or a low-pro socket. In the photo, both are attached.

![89](images/kb39_081.jpg)
<a id="3-4"></a>
### 3-4．Soldering the jumpers
You need to short the jumpers to control the OLED module and trackball sensor.

The jumper is soldered on __【Back Side Only】__.  
"Back Side Only" is indicated, and there are 【12 points】 on both of right and left board.  
You can bridge the pads by heating them with an iron tip to melt the solder.

![40](images/kb39_037.jpg)

If the solder is not fresh enough, the surface tension will drop and it will not bridge properly.
In this case, remove the solder and add more fresh solder or flux and try again.
If successfully bridged, it will look like the photo below.

![41](images/kb39_038.jpg)

You may find a few more jumpers, but these will be explained later.

<a id="3-5"></a>
### 3-5．4-pin Socket, TRRS Socket, Tact Switch
Solder the components shown in the photo below.  
Mount all of them on the __【TOP SURFACE】__.  

![51](images/kb39_040.jpg)

If you are worried about the parts floating around or moving, fix them with masking tape before soldering.

![52](images/kb39_041.jpg)

When all are installed, it will look like the photo below.

![53](images/kb39_042.jpg)


<a id="3-6"></a>
### 3-6．Soldering the ProMicro
The ProMicro can be replaced by soldering with the spring-loaded (Conthrough) pin headers pins shown in the photo below. The spring-loaded pin headers pins have mounting directions, so please look at the photo carefully.

![60](images/kb39_050.jpg)

First, insert the Conthrough pin headers on【TOP FACE】 of board.

![61](images/kb39_055.jpg)

Insert the conslue so that it fits the square frame of the silk. If the black frame of the silk is out of alignment with the conslue, the hole to insert is wrong.

![61](images/kb39_056.jpg)

Insert the ProMicro into the inserted spring-loaded pin headers pin.  
Keep this state, and Solder ONLY the ProMicro side.
"Soldering while inserted" prevents the spring-loaded pin headers are installed at unexpected angle.

![63](images/kb39_057.jpg)

The top of ProMicro can be equipped with an OLED.  
Insert a 4-pin header into the 4-pin socket and place the OLED module on it.
And solder only one pin of 4 pins.  

While melting the solder, push the OLED module from above so that it does not float. You can also adjust it so that it is parallel to the ProMicro for a better look.

![70](images/kb39_062.jpg)

Once the position is set, solder the remaining 3 pins.


<a id="3-7"></a>
### 3-7．3-7．Writing firmware to ProMicro and Electric checking
OK, let's write the test firmware to the ProMicro.

The test firmware has a concise keymap for easy operation checks, and the RGB LEDs light red, green, and blue in that order, making it easy to detect solder defects.
If you think you do not need the test firmware, for example, if you are forgoing LED soldering this time, you can use the regular firmware in [Chapter 10](#10 Writing Regular Firmware) You may write it here.

The firmware for the Keyball39 is the same whether the trackball is placed in the right or left hand.
Please write (FLASH) [Keyball39_test.hex](https://remap-keys.app/catalog/k895xiCpsM5zlYZCPTEN/firmware) that is registered in REMAP.
Press the FLASH button in the above link to see the instructions on how to write.

If the keyboard is not recognized even though the USB cable is connected, it will be recognized when the soldered RESET switch is pressed twice quickly.

*Be sure to write the same hex file to both the left and right ProMicro.

If you want to edit the Keyball39 firmware directly and build it yourself, you can find the source in [this repository](https://github.com/Yowkees/keyball/tree/main/qmk_firmware/keyboards/keyball). Source code is available for download.

After the writing is completed, short the key switch pad with tweezers as shown in the picture below to check the operation.  
sides of the keyboard may be reversed, but this is no problem right now. Please just check that some characters are entered and that ProMicro is working. It is not necessary to try all keys yet.
The earlier you check the operation, the easier it will be to isolate the problem.

*Be sure to write the same hex file to both the left and right ProMicro.

![75](images/kb39_067.jpg)

<a id="3-8"></a>
### 3-8．Soldering the LEDs (optional)

Please note that all LEDs are soldered on the 【BACK SIDE】!!

LEDs (YS-SK6812MINI-E) are option. A total of 46 LEDs can be installed on both sides.
  
However, LEDs are very sensitive to heat, so adjust the soldering iron temperature from 220°C to 280°C, before soldering.  
Since the tip temperature is low, the heat will not be transferred to the pad and it is easy to be failure soldering.  
The keyboard can be used without LEDs. I recommend to complete the project without LEDs first. You can add LEDs later.  

Place the LED on the YS-SK6812MINI-E and solder by aligning the notched leg of the four pins of the YS-SK6812MINI-E with the marked pad.

Some LED faces up and some LED faces down, but as long as the notches and markings on the pins are aligned as shown in the photo below, the top and bottom will automatically align.

Soldering all four pins at once will cause the component to overheat and break easily, so solder two pins at a time. To do this, put about 10 LEDs on the board at a time, and once the solder is applied, move on to soldering the next LED. This way you can avoid continually applying heat to one LED.

![80](images/kb39_070.jpg)

After the soldering is complete, check the lighting.  
The LEDs are wired in series, so if the light only comes on halfway, fix it by soldering the LED and the LED next to it, or by replacing the LED.

If No.12 LED is correctly lighting but No.13 is not lighting, usually 【No.12 or 13】LEDs has soldering problem. So please check and re-solder those LEDs.

Repeat the lighting check and soldering correction to ensure that all LEDs are lighting.

![82](images/kb39_073.jpg)

<a id="4"></a>
## 4. Assemble the ball-reading board
Prepare the board shown in the photo below (hereinafter referred to as the "ball board") and the sensor.
In some cases, you may receive a pre-soldered board to check the quality of the sensor and board. If this case, please skip this step and proceed to Chapter 4-2, Soldering the L-shaped 7pin Conthrough header.


![90](images/kb39_090.jpg)  

<a id="4-1"></a>
## 4-1．Soldering the optical sensor  

Insert the sensor IC from the __【BACK SIDE】__ of the ball board where no electric components are mounted.
Align the indentation indicating pin 1 of the IC with the pad mark on the board.

![91](images/kb39_091.jpg)

This is the direction of the IC when viewed from the back. Solder all pins from the surface where the component is mounted.

![92](images/kb39_092.jpg)

Use tweezers to peel off the protective stickers 【2 sheets】.

![93](images/kb39_093.jpg)

Attach the sensor lens to the side where the stickers were removed.
The lens has an direction. Please make sure the direction is correct, as the two thin pins of the lens may break if the direction is wrong.  
The lens has a protrusion in front of it as shown by the arrow in the photo below.

![95](images/kb39_095.jpg)

If the direction of the lens and IC match, the two pins of the lens should be able to be inserted into the IC softly and smoothly. Notice: Insert Lens slowly!

![94](images/kb39_094.jpg)

<a id="4-2"></a>
### 4-2．Soldering the L-shaped conthrough pin header
Next, attach the L-shaped spring-loaded pin headers to the right-hand board __【TOP FACE】__.  
The L-shaped spring-loaded pin headers also have a direction, and should be installed in the same way as in the picture below.  
Solder the one straight pins that does not have a U-shape.

![96](images/kb39_083.jpg)

Put a masking tape on the component to prevent it from floating and solder it from BACK side.

![97](images/kb39_084.jpg)

After Soldering from back side it will be below picture

![97](images/kb39_085.jpg)

<a id="5"></a>
## 5．Solder the left/right decision jumper on the left hand side

The standard firmware of the Keyball39 has an automatic left/right detection function. To activate this, solder a jumper on the __【Left hand board only】__. 

If you look at the left hand side board from the back, you will see a silk __[LEFT]__ in the red circle in the photo below. Please solder this Jumper.

![140](images/kb39_086b.jpg)

If the trackball is placed on the left hand side, the position is slightly different, and the LEFT jumper is in the position shown in the photo below.

Be sure to place the jumper on the 【LEFT SIDE】 of the board ONLY.

![141](images/kb39_087b.jpg)

This completes the soldering process.

As a side note, before de-energizing the soldering iron, put plenty of solder on the tip. The next time you use the soldering iron, you can remove the solder and resume work with a shiny soldering tip!

![100](images/kb39_096.jpg)

<a id="6"></a>
## 6. Cutting of top plate  

Keyball39 must be assembled by cutting away the perforations in the thumb key area of the top plate.
To cut them off, use a cutter to cut into the perforated areas on the front and back sides, then fold and separate them.

![101](images/kb39_100.jpg)

The detached cross section should be prepared with about 150-grit sandpaper.

![102](images/kb39_102.jpg)

<a id="7"></a>
## 7. Assembly 

<a id="7-1"></a>
### 7-1. Mounting the Protection Plates

Attach the ProMicro protection plates to the middle board.
First, screw in the 9mm spacer.

![110](images/kb39_104.jpg)

Screw in Acrylic protection plates.

The shapes of the protective plates are same for right and left side. Also, there is no front or back.

![111](images/kb39_105.jpg)  

<a id="7-2"></a>
### 7-2. Assembling the top plates  

Screw the 7mm spacers to the 【BACK SIDE】 of the top plate.

When assembling thumbs with low-profile specifications, install 4mm spacers on the top plate for thumb keys.

![112](images/kb39_107.jpg)

Insert the key switches into the four corners of the top plate and the thumb plate.

This will improve the positioning accuracy between the plates.

![113](images/kb39_108.jpg)

Align the screw holes on the top plate and middle acrylic plate and stack the plates on top of each other.

![114](images/kb39_110.jpg)

Next, the soldered middle board is also stacked, making sure that the screw holes are aligned and the key switch terminals are firmly inserted into the key sockets.


![114](images/kb39_112.jpg)

<a id="7-3"></a>
### 7-3. Assembling the bottom plates

Overlap the acrylic bottom plate from the back side and screw it in place.
Next, attach the cushion rubbers to the four corners of the keyboard.

<a id="8"></a>
## 8. Trackball installation 

<a id="8-1"></a>
### 8-1. Insert the trackball reading board

Insert the assembled trackball reader board into the 7-pin conthrough pin header. The board should be inserted vertically.

![120](images/kb39_114.jpg)

The ball board is now standing vertically.

![121](images/kb39_115.jpg)

<a id="8-2"></a>
### 8-2. Assemble the trackball case  

3 ceramic balls are fixed to the trackball case in advance. If the ceramic balls have fallen off, please fix by spare ceramic ball with a suitable bond.  
Please keep the spare ceramic ball in case you lose them in the future.

Shake the case to make sure the ceramic ball does not fall out.

![122](images/kb39_122.jpg)

The 2 pins on the top case can be inserted into the holes on the bottom case.  
Gently apply pressure from above and below to join them. (It's okay if you don't get a tight fit, because it will stick after this screw tightening.)

![123](images/kb39_123.jpg)

Attach an M1.7 tapping screw. The kit includes two types of screws: "small head screws" and "flat head screws". In this process, please use "small head screws".

![124](images/kb39_124.jpg)

Screw in these two locations as seen from the back of the case. Be careful not to over-tighten them.

![125](images/kb39_125.jpg)

<a id="8-3"></a>
### 8-3. Trackball case installation  

Attach the completed ball case to the main unit. The ball board is placed in the sensor compartment on the back side of the case.  
Gently fit the case from the top, making sure that the ball board indicated by the arrow is at the center of the case. If there is any sticking, do not force it in, but pull it out and reinsert it.

It should go all the way in without much effort.

![126](images/kb39_127.jpg)

If you check from the back of the unit, there may be a gap between the main board and the ball board, as indicated by the arrow.

![128](images/kb39_129.jpg)

In this case, lightly push from the front of the case (in the direction of the finger mark). If you use too much force, the L-shaped construe may be damaged, so press lightly.  
If the gap disappears as shown in the picture below, the screw holes in the blue circle will fit.

![129](images/kb39_130.jpg)

Tighten the two M1.7 Torx screws with __【wide flat heads】__ from the back of the body. Tighten the screws while holding the ball retainer case with your fingers to prevent it from rotating.

![130](images/kb39_132.jpg)

<a id="9"></a>
## 9. Total finish 

We are nearing completion! Fit the key switches of your choice.

Finally, push the 34mm trackball into the case and Keyball39 Building have done! 
Thank you for your hard working.  

![132](images/kb39_135.jpg)

![completed keyball39](images/kb39_136.jpg)

<a id="10"></a>
## 10. Write the regular firmware

Finally, let's write the firmware to ProMicro.

Keyball39 supports [REMAP](https://remap-keys.app/configure), so you can write firmware and change the keymap without installing any special software. 

To use REMAP, please write the following VIA-supported firmware

   - Keyball39 VIA-supported firmware [Keyball39 firmware page in the REMAP catalog](https://remap-keys.app/catalog/k895xiCpsM5zlYZCPTEN/firmware), open the Keyball39_via and FLASH the firmware.

For writing, as written in [Chapter 3-7](#3-7), press the FLASH button and instructions on how to write will appear.
If the keyboard is not recognized even though the USB cable is connected, press the soldered RESET switch twice quickly and it will be recognized.

*Be sure to write the same hex file to both left and right Pro Micro.

■If you want to build the firmware by yourself  
The latest firmware for Keyball39 is available at [Github repository](https://github.com/Yowkees/keyball/tree/main/qmk_firmware/keyboards/keyball). Copy this keyball folder to your QMK_Firmware/keyboards and edit the keymap etc. freely and build.  


<a id="11"></a>
## 11. How to use Keyball
   - The trackball motion will change to scroll up and down while switching to layer 3.
   - Keyball supports [REMAP](https://remap-keys.app/configure), so you can check, change and write keymap easily.
   - The USB cable can be plugged in either left or right. However, since the keymap is written to the ProMicro on the side where the USB cable is plugged in, please review the keymap when replacing the cable for the first time.
   - There are Special keys for Keyball users as below list. It is located on Layer 3. These key codes can be used for switching Cursor action to Scroll or Changing CPI and Speed of Scroll.

See [Special Keycode](../../../qmk_firmware/keyboards/keyball/lib/keyball/keycodes.md#english) also.



This concludes the Keyball39 build guide.
If you have any questions or problems with Keyball39, please post them to the Github repository [Yowkees/keyball Discussions](https://github.com/Yowkees/keyball/discussions). We'll get back to you as soon as possible.

Thank you very much. @Yowkees 2022
