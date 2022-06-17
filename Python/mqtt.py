import paho.mqtt.client as mqtt
import subprocess
import time
import os
import keylogger

def on_message(client, userdata, message):
    print("message received " ,str(message.payload.decode("utf-8")))
    print("message topic=",message.topic)
    print("message qos=",message.qos)
    print("message retain flag=",message.retain)

mqttBroker="broker.hivemq.com"
#mqttBroker="mqtt.eclipseprojects.io"

topic = "pruebaqla"
cliente = "clienteqlo"

client = mqtt.Client(cliente)

#client.on_message=on_message
client.connect(mqttBroker, port=1883)

while True:
    os.system("mosquitto_pub -h broker.hivemq.com -p 1883 -t pruebaqla -m kweaasa")
    time.sleep(1)
    print("publicando weas")

while False:
    client.subscribe(topic, qos=0)
    client.loop_start()

    
