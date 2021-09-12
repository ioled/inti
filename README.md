<p align="center">
 <a href="https://www.ioled.cl/"><img src="logo-ioled.png" width="400"></a>
</p>

# iOLED Inti
<img src="https://img.shields.io/badge/-C-yellow?logo=C&logoColor=white&logoWidth=30">


Este repositorio contiene el firmare de la placa IoT iOLED desarrollado en Espressif IoT Development Framework. El dispositivo se conecta a wifi  y a través del protocolo MQTT recibe y manda mensajes. 

El dispositivo sensa humedad y temperatura con el sensor SHT20 cada 1 minuto. El dispositivo cuenta con un reloj interno: DS3231, 
que actualiza la hora cada vez que se conecta a internet. El control de intensidad se realiza con un DAC: MCP4725.
