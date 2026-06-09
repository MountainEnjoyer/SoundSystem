# ARDUINO SOUND SYSTEM
Welcome ! :wave: 
Here lies the code and the schematics of an Analogic Sound System inspired prototype. For now it juste plays 4 notes without interval with the note's play time adjustable.

It also has a GUI written in python to have visual feedback on the sounds played and a partition to show the notes for geater feedback.

![Gui](/README_Assets/GUI.png)

## Here is what you can find:
- The Program writed in C++ in the arduino IDE.
- The GUI written in Python depending on the version. It requires 2 librairies imported at the beggining of the file.
- The schematic of the apropriate version.
- And the ressources that helped me build the program. 

### EasyEDA Schematic

It uses 8 Potentiometer, the resistance does not matter as we just map the value based on the flow of Voltage.
![Schematic](/SoundSystem_V0.2.1/Schematic.png)


## Prototyping

I soldered the potentiometers in parallel for the speed's knobs and another for the note's knobs.
I also used the shield provided by the beginner's kit to solder the 5V volt supply and the ground.

![Open Prototype](/README_Assets/Proto.jpg)

# Final Word
This Project is a lot of fun to make and a great practicing tool.
I plan on making it bigger and seperating the code with interupts to memorize the notes their speed to add other notes to make it a fully functionnal instrument.
