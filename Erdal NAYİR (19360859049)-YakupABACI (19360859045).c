#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


const char matrix_bigram_strings[10][3] ={"th", "he", "in", "er", "an", "en", "ch", "de", "ei", "te"};

const char matrix_trigram_strings[10][4]={"the", "and", "ing", "ent", "ion", "der", "sch", "ich", "nde", "die"};

const char languages[2][8]={"english", "german"};

//Ingilizce dilinin frekans degerleri
 const float frequency_eng[20]={ 2.71, 2.33, 2.03, 1.78, 1.61, 1.13, 0.01, 0.01, 0.01, 0.01, 1.81, 0.73, 0.72, 0.42, 0.42, 0.01, 0.01, 0.01, 0.01, 0.01 };
 //Almanca dilinin frekans degerleri
 const float frequency_germ[20]={ 0.01, 0.89, 1.71, 3.90, 1.07, 3.61, 2.36, 2.31, 1.98, 1.98, 0.01, 0.01, 0.01, 0.01, 0.01, 1.04, 0.76, 0.75, 0.72, 0.62 };


float calculated_frequencies[20];
float distances [2]={0,0};






void filter_str(char str[])
{
   int uzunluk;

  for(int i=0;i <= strlen(str) ;i++) //metnin icinde doloasabilmek icin dongu olusturuldu
  {
   if('A'<=str[i] && str[i]<='Z'){  // eğer metnin içindeki karakterler bu A-Z arasındaysa bunlar "str" char dizisinin  içine yerleştirildi.
     str[i]=str[i];
     uzunluk++;

   }
   else
   {
    if('a'<=str[i] && str[i]<='z')  // ilk kosul gerçekleşmezse. bu koşulda eğer kelime a-z arasındayasa "str" char dizisinin içine yerleştirildi.
    {
    str[i]=str[i];
    uzunluk++;

   }
    else
    {
    if(str[i]=='\0'){              // ile karşılasınca bunuda "str" char dizisinin i. kısmına ekleyecek.
        str[i]=str[i];
        uzunluk++;

    }
    else                          // ' ' veya bu kosulları saglamayan bir karakter ile karsılasınca bunuda oldugu gibi aktaracak.
    {
        str[i]=' ';

   }}}}

   printf("Metin Temizleniyor...\n");
   printf("Temizlenmis metin uzunlugu: %d\n\n\n",uzunluk);
   printf(str);
   printf("\n\n");
   printf("**************************************************************************************************************");
   }



void calculate_frequencies_bi(char str[])
{

int a=0; // döngülerde kullanilacak degerler olusturuluyor

float sayac=0; // bigramslarin miktarina göre artacak.


float adet[10]; // bigramslarin adet sayilari burada depolanacak

for(int i=0; str[i]; i++){  //karakter küçültme döngüsü..
    if(str[i]!=' '){
        if('A'<=str[i] && str[i]<='Z'){    //eðer harfler A-Z arasinda ise bunlara 32 sayisini ekleyerek kücültcek böylece ilerideki islmeler kolaylascak
            str[i]=str[i]+32;
        }

    }
}
int i;
for(int b=0;b<10;b++)
{
  for(i=0;i<=strlen(str);i++){                    //eðer str char dizinin içindeki ilk harfle matrix_bigram_strings ilk elemanini kiyaslar.
    if(str[i]== matrix_bigram_strings[b][a])          //eger dogruysa bu sefer ikinci karakterleri kiyaslar buda true çikarsa sayaci 1 arttirir yani;
    {                                                 // ilk kiyaslanacak bigramsdan, t==t ise indexleri 1 arttir th==th ise sayac=+1 eger degilse döngüye 't' elemani ile devam et
    if(str[i+1]==matrix_bigram_strings[b][a+1])
    sayac++;
    }

    }

    adet[b]=sayac;  // adetler sirayla kaydediliyor.
    printf("%c%c 'den cumlenin icinde %2.f tane  vardir\n",matrix_bigram_strings[b][a],matrix_bigram_strings[b][a+1],sayac); //sonuclar ekrana basýlýyor
    sayac=0; // sayaç sifirlaniyor çünkü diger bigrmaslarin adetinin sonraki bigramslarin adetine eklenmesini istemiyoruz
    }

    printf("\n\n\n");


    float toplam=0; //toplam bulunan bigrams adedi tutulacak.


   for(int i=0; i<10; i++){  // bütün bigram adedi toplam deðiþkenine ataniyor
        toplam+=adet[i];

   }

if(toplam==0){                  //eðer toplam adet sifir ise bütün frekanslar 0 laniyor eger biz toplami sifir olarak islem yapmaya çalisirsak 0 ra bölüm hatasi verir.
    for(int i=0; i<10; i++){
        calculated_frequencies[i]=0;


    }
 }
 else{                             //toplam 0 degilse  frekanslar hesaplaniyor. mesela th bigrami için; 2 adet varsa bu tüm bulunan bigram adedine bölünerek th bigraminin frekansi bulunuyaor
    for(int i=0; i<10; i++){
        calculated_frequencies[i]=adet[i]/toplam;

    }
 }



    for(int i=0; i<10; i++){   //frekanslar ekrana basiliyor.
        printf("%c%c 'nin  frekansi: %f 'dir\n",matrix_bigram_strings[i][a],matrix_bigram_strings[i][a+1],calculated_frequencies[i]);


    }
printf("\n");
printf("**************************************************************************************************************");
printf("\n\n\n");


}




void calculate_frequencies_tri(char str[]) // tamamen calculate_frequencies_bi fonksiyonu ile ayni mantiga sahip sadece 3.karakter için indeksler bir kez daha arttiriliyor.
{

int a=0;

float sayac=0;
                                //degiskenlerin olusturulmasi
float frekans_tri[10]; //burda ayriyeten sonuçlari ekrana basmak için frequences_tri degeri olusturuluyor

float adet[10];

for(int i=0; str[i]; i++){ //kücültme kismi
    if(str[i]!=' '){
        if('A'<=str[i] && str[i]<='Z'){
            str[i]=str[i]+32;
        }

    }
}

for(int b=0;b<10;b++)
{
  for(int i=0;i<=strlen(str);i++){
    if(str[i]== matrix_trigram_strings[b][a])       //t==t 1 arttir: th==th ise 1 arttir the==the sayaci 1 arttir degilse th den aramaya devam et
    {
    if(str[i+1]==matrix_trigram_strings[b][a+1])
        if(str[i+2]==matrix_trigram_strings[b][a+2]){
            sayac++;
        }
    }

    }

    adet[b]=sayac;  //frekans iþlemei için depolanýyor
    printf("%c%c%c 'den cumlenin icinde %2.f tane  vardir\n",matrix_trigram_strings[b][a],matrix_trigram_strings[b][a+1],matrix_trigram_strings[b][a+2],sayac); //sonuç bastýrma
    sayac=0; //sayaç her islemden sonra sifirlaniyor sifirlanmazsa  sayacin degeri buyur ve yanlis degerler atanir .
    }

    printf("\n\n\n");


    float toplam=0;


   for(int i=0; i<10; i++){
        toplam+=adet[i];

   }

 if(toplam==0){                    //yukardaki fonksiyonda yapilan islemlerin aynisi yapiliyor.
    for(int i=0; i<10; i++){
        frekans_tri[i]=0;

    }
 }
 else{
    for(int i=0; i<10; i++){
        frekans_tri[i]=adet[i]/toplam;

    }
 }

    for(int i=0; i<10; i++){  //frekanslari ekrana basma islemi frekans_tri degiskeni burda ise yariyor
        printf("%c%c%c 'nin  frekansi: %f 'dir\n",matrix_trigram_strings[i][a],matrix_trigram_strings[i][a+1],matrix_trigram_strings[i][a+2],frekans_tri[i]);


    }
    int k=10;                                   // k=10 ataniyor çünkü biz bu degerleri globaldeki calculated_frequencies dizisine kaydetmek istiyoruz.
    int p=0;                                    // bu dizinin zaten ilk 10 boyutu dolu oldugundan diger 10 luk kismina yüklemek için bu yöntemi uyguluyoruz.
    while(k<20){
        calculated_frequencies[k]=frekans_tri[p];           //depolama islemi.
        k++;
        p++;

    }
printf("\n");
printf("**************************************************************************************************************");

}



void calculate_distances(){ //distance hesaplama

    float oklid_eng; //öklid mesefeleri bu elemanlara atancak
    float oklid_ger;


    for(int i=0; i<20; i++){    //islemler için döngü kullaniyoruz


      oklid_eng+=pow((calculated_frequencies[i]-frequency_eng[i]),2);  // bu diziler içindeki ayni siradaki elemanlari çikar karesini al ve topla komutu.
      oklid_ger+=pow((calculated_frequencies[i]-frequency_germ[i]),2); // bu diziler içindeki ayni siradaki elemanlari çikar karesini al ve topla komutu.(ayni)


}
    oklid_eng=sqrt(oklid_eng); //bu toplanan degerlarin karekökünü al
    oklid_ger=sqrt(oklid_ger); //bu toplanan degerlarin karekökünü al

    distances[0]=oklid_eng; // degerleri globaldeki distance int dizisine aktar
    distances[1]=oklid_ger; // degerleri globaldeki distance int dizisine aktar


    printf("Euclidian Distance for English: %f\n",oklid_eng);  //sonuçlari bastir...
    printf("Euclidian Distance for German: %f\n",oklid_ger);

    printf("\n\n");
}

void detect_lang(){ //eger bir metnin ingilizce distance küçükkse o zaman bu dilin ingilizce olma durumu daha yüksektir aynisi almanca içinde geçerli
                    // buna dayanaraktan asagidaki kosullar olusturuldu distance[0]=english_distance tutar distance[1]=german_distance tutar.
if(distances[0]<distances[1]){
    printf("Metnin dili ingilizcedir\n");
    printf("Euclidian Distance for English: %f\n",distances[0]);
}
else if(distances[1]<distances[0]){
    printf("Metnin dili Almancadir\n");
    printf("Euclidian Distance for English: %f\n",distances[1]);
}
else if(distances[0]==distances[1]){
    printf("Dil tespit edilemedi..\n");
}

}



int main()
{

    char metin[1000000]={}; // Metin girebilmek için globalde "metin" adli karakter dizisi olusturuldu.

    printf("metin giriniz: "); //metin aliniyor
    gets(metin);


    if(strlen(metin)>0){ //eger hiçbir þey girilmezse kodlarin calistirilmasi durduruluyor eger metin uzunluðu büyük 0 dan ise alttaki islemler gerçeklesiyor

    printf("Metnin  uzunlugu:%d", (int)strlen(metin)); //metin uzunlugu basiliyor
    printf("\n\n");
    filter_str(metin); //metin filtreleniyor
    printf("\n");
    calculate_frequencies_bi(metin); //bigrams frekanslari hesaplaniyor
    calculate_frequencies_tri(metin); //trigrams frekanslari hesaplaniyor

    printf("\n\n\n");


    printf("\n\n\n");
    calculate_distances(); //distancelar hesaplaniyor

    detect_lang(); //dil tespit ediliyor

    }
    else{ //metin uzunlugu 0 ise bu kosul gerçekleserek uyari metni ekrana basilir ve program durur.

        printf("\n");
        printf("Lutfen bir metin giriniz aksi taktirde isleminiz gerceklestirilemez...\n");
    }

return 0;

}

