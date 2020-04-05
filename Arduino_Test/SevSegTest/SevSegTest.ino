#define MUX_PIN   2
#define SER_PIN   3
#define RCLK_PIN  4
#define SRCLK_PIN 5
#define SRCLR_PIN 6

static const byte digitMap[] = {
  B00111111, // 0
  B00000110, // 1
  B01011011, // 2
  B01001111, // 3
  B01100110, // 4
  B01101101, // 5
  B01111101, // 6
  B00000111, // 7
  B01111111, // 8
  B01101111, // 9
  B01110111, // A
  B01111100, // b
  B00111001, // C
  B01011110, // d
  B01111001, // E
  B01110001  // F
};

void writeDigit(uint8_t, bool);
void strobeRCLK();
void strobeSRCLK();
void strobeSRCLR();
void muxOn();
void muxOff();

void setup() {
  //Serial.begin(9600);
  pinMode(MUX_PIN, OUTPUT);
  pinMode(SER_PIN, OUTPUT);
  pinMode(RCLK_PIN, OUTPUT);
  pinMode(SRCLK_PIN, OUTPUT);
  pinMode(SRCLR_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int j = 0; j < 4; j++) {
    muxOn();
    strobeSRCLR();
    for (int i = 0; i < 4; i++) {
      writeDigit((i+j)%4, false);
    }
    muxOff();
    delay(1000);
  }
}

void writeDigit(uint8_t d, bool dp) {
  byte digit = digitMap[d];
  if (dp) digit |= (1 << 7);
  for (int i = 7; i >= 0; i--) {
    if ((digit >> i) & B1) {
      digitalWrite(SER_PIN, HIGH);
    } else {
      digitalWrite(SER_PIN, LOW);
    }
    strobeSRCLK();
  }
}

void strobeRCLK() {
  digitalWrite(RCLK_PIN, HIGH);
  digitalWrite(RCLK_PIN, LOW);
}

void strobeSRCLK() {
  digitalWrite(SRCLK_PIN, HIGH);
  digitalWrite(SRCLK_PIN, LOW);
}

void strobeSRCLR() {
  digitalWrite(SRCLR_PIN, LOW);
  digitalWrite(SRCLR_PIN, HIGH);
}

void muxOn() {
  digitalWrite(MUX_PIN, HIGH);
}

void muxOff() {
  digitalWrite(MUX_PIN, LOW);
}
