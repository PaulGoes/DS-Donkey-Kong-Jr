# DS-Donkey-Kong-Jr
DS Homebrew Donkey Kong Jr Game and Watch

![DSDKJR](https://github.com/PaulGoes/DS-Donkey-Kong-Jr/blob/master/media/DKJRDS.jpg)

## INTRODUCTION

In 1982 I got my first ‘handheld’ console: the G&W Donkey Kong Jr. 
In 1983, I programmed my own version for the TRS-80 home computer.
And now I programmed this version for the DS homebrew. 

Why? Because it is simply possible to do and a fun experience too!
I got the trigger to start this at an information evening at my son's school.
A student of de 'hogeschool voor de kunsten' was telling about game design.
A girl asked him if it would be possible to program games for the Nintendo Wii.
That question triggered me because the month before I softmodded my Wii.

So I started looking for information about creating Wii homebrew applications.
I learned that the devkitpro development environment could help me with it.
So I decided to give it a try and to recreate a game that I programmed in 1983.
At the age of 13 I programmed a relatively simple version of the Game and Watch 
Donkey Kong Jr for the TRS-80 home computer. 
I thought it would be fun to recreate it for the Wii.

And after finishing the Wii version I thought the game would be great
to play on a Nintendo DS too. After all the original game is a handheld game!
So I ported the Wii version to the Nintendo DS.

This is the result and I hope you like it.

A video showing the game can be found on YouTube:

<a href="https://www.youtube.com/watch?v=YmWyA_B5KmM">
         <img src="https://github.com/PaulGoes/DS-Donkey-Kong-Jr/blob/master/media/DKJR%20Youtube.mp4" style="width:70%;">
      </a>

Some information:
- Gameplay identical to the Game & Watch Donkey Kong Jr.
- Each level becomes gradually more difficult: more birds and crocs are added.
- Background graphic 'borrowed' from 'Game and Watch Gallery 3'.
- All other graphics created from a picture taken from my G&W Donkey Kong Jr.
- All sounds recorded from a playing session with my G&W Donkey Kong Jr.

[ Yes, my G&W Donkey Kong Jr handheld is still working !]

The game is created using devkitpro: 
          https://devkitpro.org/.

Good introduction tutorials to using devkitpro and DS programming: 
          https://patater.com/files/projects/manual/manual.html.

	  
## HOW TO INSTALL AND START THE GAME USING THE DS WITH R4DS

1) It is as simple as putting the dkjunior.nds on the SD card.
2) Put the SD card back in the R4DS card.
6) Put the R4DS card back in the Nintendo DS.
7) Start the Donkey Kong Junior homebrew application.


## FILE INFORMATION

- Folder - audio: contains all the sounds.
- Folder - build: used to build the game application.
- Folder - gfx: contains all the graphics.
- Folder - source: contains the game sources.
    - File - main.c: the main game program source file.
- File - dkjunior.nds: game nds-file (result of build).
- File - dkjunior.elf: game elf-file (result of build).
- File - dkjunior.pnproj: devkitpro project definition file.
- File - icon.bmp: game icon image.
- File - Makefile: devkitpro project make file.




