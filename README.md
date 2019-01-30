JoyBro
==============
![Image Pult](https://raw.githubusercontent.com/voltbro/BroJoystick/master/docs/scheme-joystick_v2.png)

Additional Arduino libraries
-----
Protobuf MicroProcessor's protocol lib
https://github.com/nanopb/nanopb

PacketSerial - packets managing and COBS encoding lib
https://github.com/bakercp/PacketSerial

Libraries should be installed into Arduino\Libraries\


Description
-----
Protobuf file for data structure design [BroJoystick.proto](https://github.com/voltbro/BroJoystick/BroJoystick.proto)

Data sending [examples/bro_pult/bro_pult.ino](https://github.com/voltbro/BroJoystick/examples/bro_pult/bro_pult.ino)

Data recieving and Serial output [examples/bro_pult_reciver/bro_pult_reciver.ino](https://github.com/voltbro/BroJoystick/examples/bro_pult_reciver/bro_pult_reciver.ino)


Extras
-----

Protobuf description
https://developers.google.com/protocol-buffers/

C files based on .proto data
```
protoc --nanopb_out=. BroJoystick.proto
```
