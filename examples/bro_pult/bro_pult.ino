#include <pb_encode.h>
#include <PacketSerial.h>
#include <BroJoystick.pb.h>


PacketSerial serial;

uint8_t buffer[128];
size_t message_length;
bool status;

const byte NUMBER_OF_PINS = 15;
int inputPins[NUMBER_OF_PINS] = {A0, A1, A2, A3, A4, A5, 4, 5, 6, 7, 8, 9, 10, 11, 12};

void setup() {

    serial.begin(9600, 1);
    for(int i=0; i < NUMBER_OF_PINS; i++){
      pinMode(inputPins[i], INPUT);
    }
    //HC-12 transmiting mode on
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
}

void loop() {

    BroJoystick joystic = BroJoystick_init_zero;

    /* Create a stream that will write to our buffer. */
    pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));

    joystic.LeftJoy_X = analogRead(A4);
    joystic.LeftJoy_Y = analogRead(A3);
    joystic.LeftJoy_Btn = digitalRead(A2);

    joystic.RightJoy_X = analogRead(9);
    joystic.RightJoy_Y = analogRead(10);
    joystic.RightJoy_Btn = digitalRead(4);

    joystic.LeftSlider = analogRead(A5);
    joystic.RightSlider = analogRead(8);

    joystic.btn1 = digitalRead(A0);
    joystic.btn2 = digitalRead(A1);
    joystic.btn3 = digitalRead(12);
    joystic.btn4 = digitalRead(11);

    joystic.sw1 = digitalRead(7);
    joystic.sw2 = digitalRead(6);
    joystic.sw3 = digitalRead(5);

    /* Now we are ready to encode the message! */
    status = pb_encode(&stream, BroJoystick_fields, &joystic);
    message_length = stream.bytes_written;

    /* Then just check for any errors.. */
    if (!status)
    {
        //Encoding failed
        Serial.println(PB_GET_ERROR(&stream));
        return 1;
    }

    serial.send(buffer, message_length);
    delay(10);

}
