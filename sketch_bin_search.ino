const int NUM_LEDS = 10;
const int ledPins[NUM_LEDS] = {13, 12, 14, 27, 26, 25, 33, 32, 15, 4};

int targetLED = 0;

void setup() {
  Serial.begin(115200);
  
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
  
  randomSeed(analogRead(0));
}

void loop() {
  targetLED = random(0, NUM_LEDS);
  Serial.print("Searching for LED at index: ");
  Serial.println(targetLED);
  
  resetAnimation();
  
  blinkLED(targetLED, 3, 300);
  delay(500);
  
  binarySearchVisualization(targetLED);
  
  delay(500);
  blinkLED(targetLED, 3, 300);
  
  delay(2000);
  allLEDsOff();
  delay(1000);
}

void resetAnimation() {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(80);
  }
  
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], LOW);
    delay(80);
  }
  
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(80);
  }
  
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], LOW);
    delay(80);
  }
  
  delay(300);
}

void blinkLED(int index, int times, int delayTime) {
  for (int i = 0; i < times; i++) {
    digitalWrite(ledPins[index], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[index], LOW);
    delay(delayTime);
  }
}

void binarySearchVisualization(int target) {
  int left = 0;
  int right = NUM_LEDS - 1;
  int mid;
  
  while (left <= right) {
    // Flash all active LEDs for 1 second
    for (int i = left; i <= right; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
    delay(1000);
    
    // Turn off all LEDs briefly
    for (int i = left; i <= right; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    delay(200);
    
    // Calculate middle index
    mid = left + (right - left) / 2;
    
    Serial.print("Left: ");
    Serial.print(left);
    Serial.print(" Mid: ");
    Serial.print(mid);
    Serial.print(" Right: ");
    Serial.println(right);
    
    // Check if we found the target
    if (mid == target) {
      Serial.println("Found!");
      digitalWrite(ledPins[mid], HIGH);
      break;
    }
    
    // Prune left half (turn off with wave from right to left)
    if (target > mid) {
      Serial.println("Pruning left half");
      for (int i = mid; i >= left; i--) {
        digitalWrite(ledPins[i], LOW);
        delay(100);
      }
      left = mid + 1;
    }
    // Prune right half (turn off with wave from left to right)
    else {
      Serial.println("Pruning right half");
      for (int i = mid; i <= right; i++) {
        digitalWrite(ledPins[i], LOW);
        delay(100);
      }
      right = mid - 1;
    }
    
    delay(500);
  }
}

void allLEDsOff() {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}