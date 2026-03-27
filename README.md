PALEIDIMO INSTRUKCIJA
1) Atidarykite terminala projekto kataloge.
2) Sugeneruokite build failus i build aplanka:
```
cmake -S . -B build
```
3) Sukompiliuokite programa:
```
cmake --build build
```
4) Ieikite i build aplanka:
```
cd build
```
5) Paleiskite norima programa:
```
./vector.exe
```
arba
```
./list.exe
```
arba
```
./deque.exe
```
5) Jei gaunate klaida, istrinkite build aplanka ir paleiskite 2-3 zingsnius is naujo.
<br>

TESTAVIMO PARAMETRAI: 

CPU: AMD Ryzen AI 5340 w/Radeon 840M

RAM: 16 GB

SSD: SK Hynix_HFS512GEM4X182N 

KONTEINERIŲ TYRIMAS

Vector konteineris:
```
1000:
1 strategija| Atskyrimo laikas: 0.0001372,  0.0001375,  0.0001251  Vidurkis:  0.0001333
2 strategija| Atskyrimo laikas: 0.0001196,  0.0001263,  0.0001322  Vidurkis:   0.000126
3 strategija| Atskyrimo laikas: 0.0000886,  0.0000791,  0.0000602  Vidurkis:  0.0000759
```
```
10000:
1 strategija| Atskyrimo laikas: 0.0012237,  0.0009626,  0.0009972  Vidurkis:  0.0010611
2 strategija| Atskyrimo laikas: 0.0009038,  0.0009249,    0.00093  Vidurkis:  0.0009195
3 strategija| Atskyrimo laikas: 0.0003474,   0.000335,  0.0005716  Vidurkis:   0.000418
```
```
100000:
1 strategija| Atskyrimo laikas: 0.0119887,  0.0110641,  0.0115848  Vidurkis:  0.0115458
2 strategija| Atskyrimo laikas: 0.0099553,  0.0123872,  0.0125256  Vidurkis:  0.0116227
3 strategija| Atskyrimo laikas: 0.0045916,  0.0042005,  0.0042507  Vidurkis:  0.0043476
```
```
1000000:
1 strategija| Atskyrimo laikas:  0.148257,   0.153131,   0.147417  Vidurkis:  0.1496016
2 strategija| Atskyrimo laikas: 0.0877348,  0.0853595,  0.0877479  Vidurkis:  0.0869474
3 strategija| Atskyrimo laikas: 0.0306239,  0.0303708,  0.0299182  Vidurkis:  0.0303043
```

![V1](https://github.com/Vakaris201/Objektinis/blob/v1.0/nuotraukos/V1.png)
![V2](https://github.com/Vakaris201/Objektinis/blob/v1.0/nuotraukos/V2.png)
![V3](https://github.com/Vakaris201/Objektinis/blob/v1.0/nuotraukos/V3.png)

```
10000000:
1 strategija| Atskyrimo laikas:   1.57156,    1.55005,    1.56051  Vidurkis:   1.560706
2 strategija| Atskyrimo laikas:  0.805137,   0.875178,   0.820083  Vidurkis:   0.833466
3 strategija| Atskyrimo laikas:   0.27601,   0.278601,   0.261707  Vidurkis:   0.272106
```
![V1.1](https://github.com/Vakaris201/Objektinis/blob/v1.0/nuotraukos/V1.1.png)
![V2.1](https://github.com/Vakaris201/Objektinis/blob/v1.0/nuotraukos/V2.1.png)
![V3.1](https://github.com/Vakaris201/Objektinis/blob/v1.0/nuotraukos/V3.1.png)

List konteineris:
```
1000:
1 strategija| Atskyrimo laikas: 0.0002094,  0.0002145,  0.0002903  Vidurkis:  0.0002381
2 strategija| Atskyrimo laikas: 0.0002078,  0.0001772,  0.0001645  Vidurkis:  0.0001831
3 strategija| Atskyrimo laikas: 0.0001433,   0.000134,  0.0001389  Vidurkis:  0.0001387
```
```
10000:
1 strategija| Atskyrimo laikas: 0.0014286,  0.0015187,  0.0014303  Vidurkis:  0.0014592
2 strategija| Atskyrimo laikas: 0.0011375,  0.0011407,  0.0011289  Vidurkis:  0.0011357
3 strategija| Atskyrimo laikas: 0.0006402,  0.0007101,  0.0006785  Vidurkis:  0.0006762
```
```
100000:
1 strategija| Atskyrimo laikas: 0.0191908,  0.0193874,  0.0187849  Vidurkis:   0.019121
2 strategija| Atskyrimo laikas: 0.0115679,  0.0129729,  0.0130196  Vidurkis:  0.0125201
3 strategija| Atskyrimo laikas: 0.0113211,  0.0131957,  0.0130065  Vidurkis:  0.0125077
```
```
1000000:
1 strategija| Atskyrimo laikas:  0.213701,   0.207242,   0.212711  Vidurkis:   0.211218
2 strategija| Atskyrimo laikas:  0.188649,   0.191516,   0.195902  Vidurkis:  0.1920223
3 strategija| Atskyrimo laikas:  0.364145,   0.371598,   0.363272  Vidurkis:  0.3663383
```
![L1](https://github.com/Vakaris201/Objektinis/blob/v1.0/nuotraukos/L1.png)
![L2](https://github.com/Vakaris201/Objektinis/blob/v1.0/nuotraukos/L2.png)
![L3](https://github.com/Vakaris201/Objektinis/blob/v1.0/nuotraukos/L3.png)

```
10000000:
1 strategija| Atskyrimo laikas:   2.20826,    2.13911,    2.21721  Vidurkis:   2.188193
2 strategija| Atskyrimo laikas:   2.26362,    2.26219,    2.25458  Vidurkis:    2.26013
3 strategija| Atskyrimo laikas:   3.76198,    3.78391,    3.77868  Vidurkis:  3.7748566
```
![L1.1](https://github.com/Vakaris201/Objektinis/blob/v1.0/nuotraukos/L1.1.png)
![L2.1](https://github.com/Vakaris201/Objektinis/blob/v1.0/nuotraukos/L2.1.png)
![L3.1](https://github.com/Vakaris201/Objektinis/blob/v1.0/nuotraukos/L3.1.png)

Deque konteineris:
```
1000:
1 strategija| Atskyrimo laikas: 0.0002724,  0.0002631,  0.0002183  Vidurkis:  0.0002512
2 strategija| Atskyrimo laikas: 0.0001522,  0.0001068,  0.0001201  Vidurkis:  0.0001263
3 strategija| Atskyrimo laikas: 0.0000913,  0.0000841,  0.0000906  Vidurkis:  0.0000886
```
```
10000:
1 strategija| Atskyrimo laikas: 0.0017039,  0.0017368,  0.0017407  Vidurkis:  0.0017271
2 strategija| Atskyrimo laikas: 0.0009041,  0.0009066,  0.0010827  Vidurkis:  0.0009464
3 strategija| Atskyrimo laikas: 0.0005826,  0.0005059,  0.0004646  Vidurkis:  0.0005177
```
```
100000:
1 strategija| Atskyrimo laikas: 0.0188441,  0.0168037,  0.0160086  Vidurkis:  0.0172188
2 strategija| Atskyrimo laikas: 0.0090145,  0.0090103,   0.009156  Vidurkis:  0.0090602
3 strategija| Atskyrimo laikas: 0.0063581,  0.0053733,  0.0056863  Vidurkis:  0.0058059
```
```
1000000: 
1 strategija| Atskyrimo laikas:   0.16816,   0.168763,   0.169429  Vidurkis:   0.168784 
2 strategija| Atskyrimo laikas: 0.0987044,    0.10094,  0.0978724  Vidurkis:  0.0991722
3 strategija| Atskyrimo laikas:  0.056636,  0.0561603,  0.0575465  Vidurkis:  0.0567809
```
![D1](https://github.com/Vakaris201/Objektinis/blob/v1.0/nuotraukos/D1.png)
![D2](https://github.com/Vakaris201/Objektinis/blob/v1.0/nuotraukos/D2.png)
![D3](https://github.com/Vakaris201/Objektinis/blob/v1.0/nuotraukos/D3.png)

```
10000000:
1 strategija| Atskyrimo laikas:   1.79851,    1.78005,    1.75635  Vidurkis:  1.7783033
2 strategija| Atskyrimo laikas:   1.17568,    1.30447,    1.03811  Vidurkis:  1.1727533
3 strategija| Atskyrimo laikas:  0.582763,   0.580105,   0.580581  Vidurkis:  0.5811496
```
![D1.1](https://github.com/Vakaris201/Objektinis/blob/v1.0/nuotraukos/D1.1.png)
![D2.1](https://github.com/Vakaris201/Objektinis/blob/v1.0/nuotraukos/D2.1.png)
![D3.1](https://github.com/Vakaris201/Objektinis/blob/v1.0/nuotraukos/D3.1.png)

TYRIMO ISVADOS:
1) Is 3 konteineriu greiciausiai veikia vector.
2) 3 strategija yra greiciausia, isskyrus konteineriui list.
3) Konteineriui list geriausia rinktis 1 arba 2 strategija.
4) Konteineris deque geras tarpinis variantas - greitesnis uz list, bet letesnis uz vector.
