#include <pb_encode.h>
#include <PacketSerial.h>
#include <BroJoystick.pb.h>


PacketSerial serial;

uint8_t buffer[128];
size_t message_length;
bool status;

void setup() {

    Serial.begin(9600);

    serial.begin(9600, 1);

    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(9, INPUT);
    pinMode(10, INPUT);

}

void loop() {

    BroJoystick joystic = BroJoystick_init_zero;

    /* Create a stream that will write to our buffer. */
    pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));

    joystic.LeftJoy_X = analogRead(A1);
    joystic.LeftJoy_Y = analogRead(A2);

    joystic.RightJoy_X = analogRead(10);
    joystic.RightJoy_Y = analogRead(9);

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
