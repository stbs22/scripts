import random, os, requests, threading
from time import sleep

# Importar la librería de Google para acceder a la API de YouTube Data
from googleapiclient.discovery import build

# Ingresar aquí tu clave de API de YouTube Data
API_KEY = "AIzaSyCSgJ252dAt9sCHC9Sb5t9PKsVumKX3Jo4"

caracteres = ["-", "_"] + [chr(i) for i in range(48, 58)] + [chr(i) for i in range(97, 123)] + [chr(i) for i in range(65, 91)]

def get_random_string():
    return "".join(random.choice(caracteres) for i in range(11))

# Función para verificar si el video existe usando la API de YouTube Data
def video_exists(video_id):
    youtube = build("youtube", "v3", developerKey=API_KEY)
    request = youtube.videos().list(part="id", id=video_id)
    response = request.execute()
    return response['items'] != []

video_id = get_random_string()

#Mientras la lista no esté vacia
intento = 0

while not video_exists(video_id):
    print(f"{video_id} No encontrado...")
    video_id = get_random_string()
    intento += 1
    if intento > 20:
        print("Buscando...")
        intento = 0

os.system("firefox https://youtu.be/" + video_id)
print("https://youtu.be/" + video_id)
