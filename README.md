# Processador-de-Imagens-PPM
Projeto final de APC (1° semestre de computação) - 2018/1

Para compilar: `gcc proj.c -lm -o output`

Programa vai ler um arquivo .ppm e realizar as modificações desejadas pelo usuário de acordo com as opções no menu. A opção principal que processa a imagem utiliza um algoritmo k-means para agrupar pixels e os classificar de acordo com as cores escolhidas pelo usuário. Em seguida, o salva em um arquivo.

Conversão de imagens para PPM com o nível correto de compressão (P3) pode ser feito usando o image-magick: `convert image.? -compress none result.ppm`
