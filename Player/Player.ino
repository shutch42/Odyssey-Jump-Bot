#define JUMP 13
#define BUTTON 7

int delay_time = 1067;
int jump_count = 0;
int jumping = 0;

void setup() {
  // Connect button on pin 7
  pinMode(BUTTON, INPUT);

  // Attach second arduino (controller) via pin 13
  pinMode(JUMP, OUTPUT);
}

void loop() {
  if(digitalRead(BUTTON)) {
    // On button press, reset delay and start jumping
    delay_time = 1067;
    jump_count = 0;
    jumping = 1;
  }
  if(jumping) {
    // Press the A Button for 100 ms
    digitalWrite(13, HIGH);
    delay(100);
    
    // Release A button and wait for next jump
    digitalWrite(13, LOW);
    delay(delay_time);
    
    // Depending on the current jump number, change the delay time
    jump_count++;
    switch(jump_count) {
      case 5:
        delay_time = 950;
        break;
      case 10:
        delay_time = 858;
        break;
      case 15:
        delay_time = 800;
        break;
      case 20:
        delay_time = 733;
        break;
      case 25:
        delay_time = 675;
        break;
      case 30:
        delay_time = 633;
        break;
      case 35:
        delay_time = 583;
        break;
      case 40:
        delay_time = 550;
        break;
      case 45:
        delay_time = 508;
        break;
      case 50:
        delay_time = 485;
        break;
    }
  }
}
