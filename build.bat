@echo off

g++ src/*.cpp -o Engine.exe -IC:\libs\allegro\include -LC:\libs\allegro\lib -lallegro_monolith -fdiagnostics-color=always

Engine.exe
