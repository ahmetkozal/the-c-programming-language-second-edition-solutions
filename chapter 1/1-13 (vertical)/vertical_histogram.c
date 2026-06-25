#include <stdio.h>
/*Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.*/
int main(){
    int c, len, max;
    int words[21];
    len = max = 0;
    //Kullanmadan once listeyi temizliyoruz cunku ici random dolu.
    for (int i = 1; i < 21;++i){
        words[i] = 0;
    }
    while ((c = getchar()) != EOF){
        //char sayiyor. Kelimenin uzunlugu
        if (c!=' ' && c!= '\t' && c!= '\n'){
            ++len;
        }
        /*araya bosluk girince kelime bitiyor, leni index olarak olarak kullanip
        len uzunlugundaki kelimeler degerini 1 arttiriyor*/
        else{
            //eger kelime 0 harften buyukse
            if (len>0){
                ++words[len];
            }

            //yeni kelimeye gecmeden once sifirliyor ki yeni kelimenin uzunlugunu hesaplayalim.
            len = 0;
        }
    }
    //EOF oldugunda son kelime 0 harften buyukse onu da eklemek icin.
    if (len>0){
        ++words[len];
    }

    //Kac harflik kelimeden en cok var hesaplamasi. Cunku yukaridan asagi yazacagimiz icin yukseklik lazim.
    for(int i =1;i<21;++i){
        if (words[i]>max){
            max = words[i];
        }
    }
    //sutun, max'tan sifira iniyor. yukseklik
    for (int i = max; i > 0;--i){
        //satir, 20 satir olacak
        for (int z = 1; z<21;++z){
            /* eger 'z' harflik kelime sayisi i'den, yani yukseklikten buyuk veya esitse.
            yani mesela 3 harflik kelimeden, su an i=4 diyelim.4 veya daha cok varsa
            * yazdiracagiz. eger 3 tane varsa yazdirmayacak, sonraki dongude i 3 oldugu zaman
            yazmaya baslayacak*/
            if (words[z] >= i){
                printf("| * |");
            }
            else{
                printf("|   |");
            }
        }
        printf("\n");
    }
    // harf sayilarini yazdirmak icin.
    for (int i = 1; i < 21;++i){
        if (i<10){
            printf("| %d |",i);
        }
        else{
            printf("| %d|",i);
        }
    }
}
