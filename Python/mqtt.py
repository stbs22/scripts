import paho.mqtt.client as mqtt
import subprocess
import time

def on_message(client, userdata, message):
    print("message received " ,str(message.payload.decode("utf-8")))
    print("message topic=",message.topic)
    print("message qos=",message.qos)
    print("message retain flag=",message.retain)

#mqttBroker="broker.hivemq.com"
mqttBroker="mqtt.eclipseprojects.io"

topic = "pruebaqla/ylawea"
cliente = "clienteqlo"

client = mqtt.Client(cliente)
client.on_message=on_message
client.connect(mqttBroker, port=1883)

while False:
    client.publish(topic, "wena ctm",qos=0)
    time.sleep(1)
    print("publicando weas")

while True:
    client.subscribe(topic, qos=0)
    client.loop_start()

    
