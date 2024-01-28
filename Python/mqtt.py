import paho.mqtt.client as mqtt 
import time

mqttBroker ="broker.hivemq.com"

client = mqtt.Client("nombre_cliente_xd")
client.connect(mqttBroker)

m = "Wena conchetumare"
t = "topicoreqlo"


#Publishing
for _ in range(3):
    client.publish(t, m)
    print("Just published " + str(m) + " to topic TEMPERATURE")
    time.sleep(1)

#Subscribe
print("Subscribing to topic: ",t)
client.loop_start()

def on_message(client, userdata, message):
    print("received message: " ,str(message.payload.decode("utf-8")))

client.subscribe(t)
client.on_message=on_message 
time.sleep(30)

client.loop_stop()