# Integrantes: Catalina Henriquez Hnerietta y Francisca Gonzalez Hernandez
#Librerias
library(spotifyr)
library(tidyverse)
library(factoextra)
library(knitr)
library(dplyr)
library(tidyr)

#-------------------------------------------------------------------------------

#Usamos las siguientes lineas de codigo para conectar el API de spotify a R. Documentacion obtenida de:https://www.rcharlie.com/spotifyr/
Sys.setenv(Spotify_Client_ID = "9ae2edca1eb6469db6670cafac798086")
Sys.setenv(Spotify_Client_Secret = "f7bdb58803f1426e91cdf139738f46ee")
access_token <- get_spotify_access_token()
auth_token <- get_spotify_authorization_code(scope = scope)

#Busco los datos de una canción (que corresponde a la que se quiere usar para obtener recomendaciones).
#En este caso, para probar y construir el codigo, utilizamos la cancion stairway to heaven de led zepelin
song = search_spotify(type = 'track', q = 'hallway to hell', limit = 1) 
#En la q se debe ingresar el nombre de la cancion que se quiere buscar entre comillas ""

#Buscamos los features de la cancion escogida mediante su id 
song_features = get_track_audio_features(id = song$id)
song$id

#Unimos la informacion de la cancion con sus features mediante un merge
song <- merge(x = song, y = song_features, by = c("id"))

song_features_seleccionados <- select(song, id, href, name, artists, duration_ms.x, danceability, energy, loudness, speechiness, acousticness, instrumentalness, liveness, valence, tempo)

#Acortamos los datos de la cancion a los parametros que son relevantes para el analisis como los identificadores para la playlist 
# y sus features para los analisis
song <- select(song, id, danceability, energy, loudness, speechiness, acousticness, instrumentalness, liveness, valence, tempo)

#-------------------------------------------------------------------------------

# Cargamos la base de datos de las canciones beats.rds que se encuentra en la carpeta R
df_canciones <- readRDS(file = "~/R/beats.rds")

#Convertimos los datos a data frame en caso de que no se haya cargado como uno
df_canciones <- as.data.frame(df_canciones)

df_canciones_features <- select(df_canciones, track_id, track_href, track_name, artist_name, duration_ms, danceability, energy, loudness, speechiness, acousticness, instrumentalness, liveness, valence, tempo)
#Seleccionamos los datos de interes de la base de datos que son los parámetros para la playlist
# y los features de las canciones para los analisis
df_canciones <- select(df_canciones, track_id, danceability, energy, loudness, speechiness, acousticness, instrumentalness, liveness, valence, tempo)

#Cambio de nombre a la primera variable de la cancion ingresada para poder agregarla sin problemas a la base de datos
names(song)[1] <- 'track_id'

#Ahora unimos la información de la canción ingresada o elegida a la base de datos
df_canciones <- rbind(df_canciones, song)

##Pre procesamiento de la base de datos

#Realizamos prepocesamiento de los datos donde eliminamos posibles Na entre los datos y verificamos con el track_id
# que las canciones dentro de la base no se repitan
df_canciones_completo <- na.omit(df_canciones)
df_canciones_completo <- distinct(df_canciones_completo, track_id, danceability, energy, loudness, speechiness, acousticness, instrumentalness, liveness, valence, tempo)

rownames(df_canciones_completo) <- df_canciones_completo$track_id

#Luego, escalamos la base de datos para normalizarla
df_canciones_escalado <- scale(df_canciones_completo[,2:10])

#-------------------------------------------------------------------------------

cluster_k_3 <- kmeans(df_canciones_escalado, centers = 3, nstart = 25)
#Ordenamos las canciones por cluster y luego lo convertimos en un data frame junto con sus id
Canciones_orden_cluster = order(cluster_k_3$cluster)
df_clusterkm_canciones = data.frame(df_canciones_completo$track_id[Canciones_orden_cluster], cluster_k_3$cluster[Canciones_orden_cluster])

#Revisamos que no existan na dentro del cluster
df_clusterkm_canciones <- na.omit(df_clusterkm_canciones)
#Buscamos en que cluster se encuentra la cancion que se introdujo al algoritmo y separamos las canciones pertenecientes al mismo cluster
ultimateTodo = df_clusterkm_canciones[df_clusterkm_canciones$df_canciones_completo.track_id.Canciones_orden_cluster. == song$track_id, ]
ultimateUltraComboNamboBreaker2 = df_clusterkm_canciones[df_clusterkm_canciones$cluster_k_3.cluster.Canciones_orden_cluster. == ultimateTodo$cluster_k_3.cluster.Canciones_orden_cluster., ]

#Cambiamos el nombre de las columnas dento de la variable
names(ultimateUltraComboNamboBreaker2)[1] <- 'track_id'
names(ultimateUltraComboNamboBreaker2)[2] <- 'clusterId'

#Revisamos que no existan id repetidos 
ultimateUltraComboNamboBreaker2 <- unique(ultimateUltraComboNamboBreaker2, by = "track_id")

#Unimos los features y otras caracteristicas de las cancion segun su id y luego revisamos valores replicados
u2 <- merge(x = ultimateUltraComboNamboBreaker2, y = df_canciones_features, by = c("track_id"))
u2 <- select(u2, track_id, track_href, track_name, artist_name, duration_ms, danceability, energy, loudness, speechiness, acousticness, instrumentalness, liveness, valence, tempo)
u2 <- distinct(u2, track_id, track_href, track_name, artist_name, duration_ms, danceability, energy, loudness, speechiness, acousticness, instrumentalness, liveness, valence, tempo)

#obtenemos una playlist de almenos 55 canciones 
playlist_kmeans = u2[sample(nrow(u2), 55), ]

#Obtenemos la duracion total de la playlist de recomendaciones con kmeans en horas
tiempo_playlist_kmeans = ((sum(playlist_kmeans$duration_ms) / 1000) / 60) / 60
print(paste("El tiempo total de la playlist con kmeans (k = 3) es: ", tiempo_playlist_kmeans ))
playlist_final_kmeans <- select(playlist_kmeans,  track_name, artist_name, duration_ms)
#Se visualiza el nombre de la cancion, el artista y duracion de las canciones de la playlist
head(playlist_final_kmeans , 55)
#Se visualiza el nombre de la cancion, el artista y duracion de las primeras 10 canciones de la playlist
head(playlist_final_kmeans , 10)



