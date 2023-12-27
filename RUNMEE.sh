cmake -G Xcode .
cmake --install .
cmake --build .
cp pirmas.v1.0/studentai1000.txt Debug/studentai1000.txt
cp pirmas.v1.0/studentai10000.txt Debug/studentai10000.txt
cp pirmas.v1.0/studentai100000.txt Debug/studentai100000.txt
cp pirmas.v1.0/studentai1000000.txt Debug/studentai1000000.txt
cp pirmas.v1.0/studentai10000000.txt Debug/studentai10000000.txt
cd Debug
./pirmas.v1.0
 
