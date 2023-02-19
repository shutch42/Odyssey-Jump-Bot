# Odyssey-Jump-Bot
An Arduino Bot to beat the Jump Rope Challenge in Super Mario Odyssey  
  
<img src="https://github.com/shutch42/Odyssey-Jump-Bot/blob/master/img/Jumping.gif" width="30%">  
  
## Setup and Implementation  
<img src="https://github.com/shutch42/Odyssey-Jump-Bot/blob/master/img/arduinos.jpg" width="50%">  
  
There are two different devices involved in this project.  
  
### Controller
First, one microcontroller is needed to emulate a nintendo switch controller. 
This is done using the code in the 'Controller' Directory. The base code for this is made possible by the LUFA project, 
and specifically shinyquagsire23's splatoon message bot that was made with it. This project was used as a base program for my project, 
and I modified it so that rather than sending controller instructions determined by an image file, it reads for a digital input on pin 7,
and then sends an 'A Button' press over USB when the signal is received.  
  
One important thing to note with this section of the project is that it will only work on certain microcontrollers. Speceifically an AVR controller with USB communication is needed. 
I have only tested it with an Arduino Leonardo, but it should work with an Arduino Micro, Teensy 2.0++, or Arduino Uno R3 with a couple of modifications.  
  
To compile and load this program to the microcontroller, take a look at the README in the Controller directory.

### Player
The second microcontroller is used to send the signal to jump to the nintendo switch controller. 
This program is much simpler. All it does is wait for the user to press a button, 
and then it will begin generating the signals to jump in time with the jump rope minigame. 
To set this up, you will need to wire a button to pin 7, and then connect pin 13 on the microcontroller to pin 7 on the other microcontroller.  
  
The nice thing with this part of the program is that it will work with any arduino-compatible microcontroller. 
As long as Arduino IDE recognizes it, then it should work. Just compile load the program using Arduino IDE.  
  
### Possible Improvements?
There is probably a way to do all of this on one microcontroller, but I'm afraid that it will require heavy modification of the original code. 
The controller program does not work if regular delays are used, 
and it is already using interrrupts in a way that makes it difficult to add a timer to control the jumps. 
This is why I decided that it would be easiest to just use two microcontrollers, but I still think that it is possible to move everything to one device.
  
## Usage
Once everything is wired up and programmed, plug the microcontroller that is running the 'Controller' code into the nintendo switch. 
Use your actual switch controller to move Mario into place so that he is standing right behind the jump rope. 
When you are ready to go, press the button on the 'Player' microcontroller, and then Mario should jump up. 
From there, use your regular switch controller to move Mario into the middle of the jump rope while Mario is in the air. 
*This can be tricky, because the nintendo switch won't receive 'jump' signals while you are using the regular controller.* 
In other words, you cannot use the joycons to move while mario is about to jump off the ground. You can only move while he is in mid-air. 
But, once you have this figured out, and you have the timing right for the first jump, the Arduino will take over and complete the challenge for you. 
It might take a couple of tries, but it will eventually work. It doesn't work forever, but it will get you past 100 jumps to get that tricky moon.
  
## References
This project is heavily inspired by two other projects that were used to beat the jump rope minigame in Mario Odyssey.  
1. pimanrules videos, [How I Cheesed the Jump Rope Challenge in Super Mario Odyssey](https://youtu.be/hu3HEwc6Pwk) and [Code Review #1: A Deep Dive into the Jump Rope Bot code](https://youtu.be/9lLxey7zX7A)
     - This project introduced me to [shinyquagsire23's splatoon message bot](https://github.com/shinyquagsire23/Switch-Fightstick), which was used as a starting point for using an arduino as a switch controller.
2. Antin Harasymiv's project on FreeCodeCamp, 
[MacGyvering the Mario Odyssey Jump Rope Challenge](https://www.freecodecamp.org/news/mario-jump-rope-challenge-f7bb44faf6bb/)
     - I used the timing data from this project in my code
