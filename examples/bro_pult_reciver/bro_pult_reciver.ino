#include <pb_decode.h>
#include <PacketSerial.h>
#include <BroJoystick.pb.h>

uint8_t buffer[128];
size_t message_length;
bool status;

PacketSerial serial;
    
void setup() {
  
  Serial.begin(57600);
  serial.begin(9600, 1);
  
  serial.setPacketHandler(&onPacket);

}

void loop() {
  // put your main code here, to run repeatedly:
  serial.update();

}

void onPacket(const uint8_t* buffer, size_t size)
{

    BroJoystick joystic = BroJoystick_init_zero;
    pb_istream_t stream = pb_istream_from_buffer(buffer, size);
    status = pb_decode(&stream, BroJoystick_fields, &joystic);

        if (!status)
        {
            //Encoding failed:
            Serial.println(PB_GET_ERROR(&stream));
            return 1;
        }

    Serial.print(joystic.LeftJoy_X); Serial.print("|");//498
    Serial.print(joystic.LeftJoy_Y); Serial.print("|");//533
    Serial.print(joystic.RightJoy_X); Serial.print("|");//529
    Serial.print(joystic.RightJoy_Y); Serial.print("|");//507
    Serial.print(joystic.btn1); Serial.print("|");

    Serial.print("\n");
    
}


