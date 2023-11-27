# Pirma

Lyginame programos veikimo greitį su vector ir list konteineriu:

| Konteineris | 1000 | 10000 | 100000 | 1000000 | 10000000 |
| -- | -- | -- | -- | -- | -- | 
| Studento failo uzpildymas | 0.003 s | 0.0294 s | 0.2756 s | 2.6706 s | 29.1732 s |
|std::vector "Vargsiukai.txt" | 0.0289 s | 0.0926 s | 0.5954 s | 5.6555 s | 58.8272 s |
|std::vector "Kietiakai.txt" | 0.0292 s | 0.0926 s | 0.5955 s | 5.6554 s | 58.8275 s |
|std::list "Vargsiukai.txt" | 0.0263 s | 0.0849 s | 0.5148 s | 5.2316 s | 50.4858 s |
|std::list "Kietiakai.txt" |0.0264 s | 0.0849 s | 0.5148 s | 5.2317 s | 50.4859 s |

Išvada: Iš lentelių matyti, kad naudojant list konteinerį failai buvo generuojami greičiau nei naudojant vector knteinerį. 

Kompiuterio duomenys:

CPU - Apple M1 chip 8-core CPU with 4 perform­ance cores and 4 efficiency cores

RAM - 16 GB

HDD - 256 GB SSD
