#!/bin/bash

OUTPUT="game"
SRC_DIR="src"
INCLUDE_DIR="include"

SOURCES=$(find "$SRC_DIR" -name '*.cpp')

# Verificaciones
command -v sdl2-config >/dev/null 2>&1 || { echo "❌ SDL2 no está instalado. Ejecutá: sudo apt install libsdl2-dev"; exit 1; }
command -v fltk-config >/dev/null 2>&1 || { echo "❌ FLTK no está instalado. Ejecutá: sudo apt install libfltk1.3-dev"; exit 1; }

# Verifica headers
if ! find /usr/include /usr/local/include -name SDL_mixer.h | grep -q SDL_mixer.h; then
    echo "❌ Falta SDL_mixer. Ejecutá: sudo apt install libsdl2-mixer-dev"
    exit 1
fi

# Flags
FLTK_FLAGS=$(fltk-config --cxxflags)
FLTK_LIBS=$(fltk-config --ldflags)
SDL2_FLAGS=$(sdl2-config --cflags --libs)

# Librerías manuales extra
EXTRA_LIBS="-lfltk_images -lSDL2_mixer"

echo "Compilando con FLTK, SDL2 y soporte de imágenes..."

g++ $SOURCES -I"$INCLUDE_DIR" $FLTK_FLAGS $SDL2_FLAGS $FLTK_LIBS $EXTRA_LIBS -o $OUTPUT

if [ $? -eq 0 ]; then
    echo "✅ Compilado correctamente: ./$OUTPUT"
else
    echo "❌ Error de compilación"
echo
./game
echo "Press Enter to continue..."
read


