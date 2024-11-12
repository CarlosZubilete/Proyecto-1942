#include "ArchivoPlayer.h"

ArchivoPlayer::ArchivoPlayer()
{
  _nombreArchivo = "ArchivoPlayer-dat.dat";
}

bool ArchivoPlayer::Guardar(Player player){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&player, sizeof(Player), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoPlayer::Guardar(Player player, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Player) * posicion, SEEK_SET);
    bool ok = fwrite(&player, sizeof(Player), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoPlayer::Buscar(int puntos){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Player player;
    int i = 0;
    while(fread(&player, sizeof(Player), 1, pArchivo)){
        if(player.getPuntos() == puntos){
            fclose(pArchivo);
            return i;
            /// TODO: hacer gerIDPlayer
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Player ArchivoPlayer::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    Player player;
    if(pArchivo == NULL){
        return player;
    }

    fseek(pArchivo, sizeof(Player) * posicion, SEEK_SET);
    fread(&player, sizeof(Player), 1, pArchivo);
    fclose(pArchivo);
    return player;
}

int ArchivoPlayer::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Player);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoPlayer::Leer(int cantidadRegistros, Player *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Player), 1, pArchivo);
    }
    fclose(pArchivo);
}

/*
int ArchivoPlayer::Buscar(int IDplayer){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Player player;
    int i = 0;
    while(fread(&player, sizeof(Player), 1, pArchivo)){
        if(player.getIDPlayer() == IDplayer){
            fclose(pArchivo);
            return i;
            /// TODO: hacer gerIDPlayer
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}
*/





