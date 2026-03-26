TESTAVIMO PARAMETRAI: 
CPU: AMD Ryzen AI 5340 w/Radeon 840M
RAM: 16 GB
SSD: SK Hynix_HFS512GEM4X182N 

KONTEINERIŲ TYRIMAS

Vector konteineris:
```
1000:
                 Failo skaitymo laikas:  0.0007919,    0.00077,   0.000777  Vidurkis:  0.0007796
                      Rusiavimo laikas:  0.0001905,  0.0001372,  0.0001163  Vidurkis:   0.000148 
Vargsiuku ir kietiaku atskyrimo laikas:  0.0001372,  0.0001375,  0.0001251  Vidurkis:  0.0001333

10000:
                 Failo skaitymo laikas:  0.0075482,  0.0070109,  0.0070105  Vidurkis:  0.0071898
                      Rusiavimo laikas:  0.0012535,  0.0009276,  0.0014901  Vidurkis:  0.0012237
Vargsiuku ir kietiaku atskyrimo laikas:  0.0012237,  0.0009626,  0.0009972  Vidurkis:  0.0010611

100000:
                 Failo skaitymo laikas:  0.0697628,  0.0690002,  0.0688717  Vidurkis:  0.0692115
                      Rusiavimo laikas:   0.010253,  0.0103932,  0.0111325  Vidurkis:  0.0105929
Vargsiuku ir kietiaku atskyrimo laikas:  0.0119887,  0.0110641,  0.0115848  Vidurkis:  0.0115458

1000000:
                 Failo skaitymo laikas:  0.663516,   0.66256,   0.661653    Vidurkis:  0.662576
                      Rusiavimo laikas:  0.122612,  0.122521,   0.121281    Vidurkis:  0.122138
Vargsiuku ir kietiaku atskyrimo laikas:  0.153574,  0.153131,   0.147417    Vidurkis:  0.151374

10000000:
                 Failo skaitymo laikas:  6.53674,  6.50271,  6.54028        Vidurkis:  6.526576
                      Rusiavimo laikas:  1.37599,  1.38457,  1.39243        Vidurkis:   1.38433
Vargsiuku ir kietiaku atskyrimo laikas:  1.61612,  1.55005,  1.56051        Vidurkis:   1.57556
```

List konteineris:
```
1000:
                 Failo skaitymo laikas:  0.0011506,  0.0008903,  0.0014377  Vidurkis:  0.0011595
                      Rusiavimo laikas:  0.0001287,  0.0002271,  0.0002016  Vidurkis:  0.0001858
Vargsiuku ir kietiaku atskyrimo laikas:  0.0002094,  0.0002145,  0.0002903  Vidurkis:  0.0002381

10000:
                 Failo skaitymo laikas:  0.0084119,  0.0077728,   0.008404  Vidurkis:  0.0081962
                      Rusiavimo laikas:  0.0012722,  0.0012303,  0.0011672  Vidurkis:  0.0012232
Vargsiuku ir kietiaku atskyrimo laikas:  0.0014286,  0.0015187,  0.0014303  Vidurkis:  0.0014592

100000:
                 Failo skaitymo laikas:  0.0748777,  0.0749175,  0.0753437  Vidurkis:  0.0750463
                      Rusiavimo laikas:  0.0162768,  0.0199001,  0.0219891  Vidurkis:  0.0193886
Vargsiuku ir kietiaku atskyrimo laikas:  0.0191908,  0.0193874,  0.0187849  Vidurkis:   0.019121

1000000:
                 Failo skaitymo laikas:  0.714057,  0.720544,  0.717437     Vidurkis:  0.717346
                      Rusiavimo laikas:  0.518293,  0.518757,  0.516026     Vidurkis:  0.517692
Vargsiuku ir kietiaku atskyrimo laikas:  0.218728,  0.207242,  0.212711     Vidurkis:  0.212893

10000000:
                 Failo skaitymo laikas:  7.14775,  7.16515,  7.02466        Vidurkis:   7.11252
                      Rusiavimo laikas:   10.135,  10.3215,  10.1698        Vidurkis:  10.20876
Vargsiuku ir kietiaku atskyrimo laikas:  2.27642,  2.13911,  2.21721        Vidurkis:  2.210913
```

Deque konteineris:
```
1000:
                 Failo skaitymo laikas:  0.0013739,  0.0008729,  0.0011558  Vidurkis:  0.0011342
                      Rusiavimo laikas:  0.0001544,  0.0001451,  0.0002814  Vidurkis:  0.0001936
Vargsiuku ir kietiaku atskyrimo laikas:  0.0001602,  0.0001296,  0.0001793  Vidurkis:  0.0001563

10000:
                 Failo skaitymo laikas:  0.0097322,  0.0092441,    0.00848  Vidurkis:  0.0091521
                      Rusiavimo laikas:  0.0015202,  0.0019415,  0.0015975  Vidurkis:  0.0016864
Vargsiuku ir kietiaku atskyrimo laikas:  0.0011322,  0.0014522,  0.0009961  Vidurkis:  0.0011935

100000:
                 Failo skaitymo laikas:  0.0708895,  0.0719067,  0.0704915  Vidurkis:  0.0710959
                      Rusiavimo laikas:  0.0149185,  0.0138545,  0.0162812  Vidurkis:   0.015018
Vargsiuku ir kietiaku atskyrimo laikas:  0.0141873,  0.0134399,  0.0154184  Vidurkis:  0.0143485

1000000: 
                 Failo skaitymo laikas:  0.684514,   0.67838,   0.675466    Vidurkis:  0.679453
                      Rusiavimo laikas:  0.189361,  0.189031,   0.189807    Vidurkis:  0.189399
Vargsiuku ir kietiaku atskyrimo laikas:  0.166198,  0.168763,    0.17277    Vidurkis:  0.169243

10000000:
                 Failo skaitymo laikas:  6.93593,  6.73193,  6.70661        Vidurkis:   6.79149
                      Rusiavimo laikas:  2.37168,   2.3234,  2.30605        Vidurkis:   2.33371
Vargsiuku ir kietiaku atskyrimo laikas:  1.84084,  1.90198,  1.75635        Vidurkis:  1.833056
```
