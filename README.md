Братьея Вольт JoyStick
==============

Пульт управления БратьевВольт

![Image Pult](https://raw.githubusercontent.com/voltbro/BroJoystick/master/docs/scheme-joystick_v2.png)

Дополнительные библиотеки Arduino
-----
Протокол Protobuf для микроконтроллеров
https://github.com/nanopb/nanopb

PacketSerial работа с пакетами с кодирование COBS
https://github.com/bakercp/PacketSerial

Модули необходимо установить в Директорию libraries в папке Arduino


Описание
-----
Файл в формате Protobuf для формирования структуры данных [BroJoystick.proto](https://github.com/voltbro/BroJoystick/BroJoystick.proto)

Отправка данных [examples/bro_pult/bro_pult.ino](https://github.com/voltbro/BroJoystick/examples/bro_pult/bro_pult.ino)

Прием данных и вывод в Serial [examples/bro_pult_reciver/bro_pult_reciver.ino](https://github.com/voltbro/BroJoystick/examples/bro_pult_reciver/bro_pult_reciver.ino)


Дополнительно
-----

Описание протокола Protobuf
https://developers.google.com/protocol-buffers/

Генерация С файлов на основе .proto данных
```
protoc --nanopb_out=. BroJoystick.proto
```
