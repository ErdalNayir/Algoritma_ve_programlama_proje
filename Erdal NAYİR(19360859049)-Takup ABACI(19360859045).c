#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


const char matrix_bigram_strings[10][3] ={"th", "he", "in", "er", "an", "en", "ch", "de", "ei", "te"};

const char matrix_trigram_strings[10][4]={"the", "and", "ing", "ent", "ion", "der", "sch", "ich", "nde", "die"};

const char languages[2][8]={"english", "german"};

//İngilizce dilinin frekans değerleri
 const float frequency_eng[20]={ 2.71, 2.33, 2.03, 1.78, 1.61, 1.13, 0.01, 0.01, 0.01, 0.01, 1.81, 0.73, 0.72, 0.42, 0.42, 0.01, 0.01, 0.01, 0.01, 0.01 };
 //Almanca dilinin frekans değerleri
 const float frequency_germ[20]={ 0.01, 0.89, 1.71, 3.90, 1.07, 3.61, 2.36, 2.31, 1.98, 1.98, 0.01, 0.01, 0.01, 0.01, 0.01, 1.04, 0.76, 0.75, 0.72, 0.62 };


float calculated_frequencies[20];
float distances [2]={0,0};






void filter_str(char str[])
{


  for(int i=0;i<=strlen(str);i++) //metnin içinde gezinebilmek için döngü oluştruldu.
  {
   if('A'<=str[i] && str[i]<='Z') // eğer metnin içindeki karakterler bu A-Z arasındaysa bunlar "str" char dizisinin  içine yerleştirildi.
    {
     str[i]=str[i];

   }
   else
   {
    if('a'<=str[i] && str[i]<='z') // ilk koşul gerçekleşmezse. bu koşulda eğer kelime a-z arasındayasa "str" char dizisinin içine yerleştirildi.
    {

    str[i]=str[i];

    }

    else
    {
    if(str[i]=='\0') // \0 ile karşılaşınca bunuda "str" char dizisinin i. kısmına ekleyecek.
    {
        str[i]=str[i];
    }
    else  // ' ' ile karşılaşınca bunuda olduğu gibi aktaracak.
    {
        str[i]=' ';

        str[i]=str[i];


   }}}}
    // Sonuçları Gösterme Kısmı.

    printf("Temizlenmis Metin:\n");
    printf("\n");
    printf(str);
    printf("\n\n");
    printf("*******************************************************************************************************************");
    printf("\n\n");
   }



void calculate_frequencies_bi(char str[])
{

int a=0,b=0; // döngülerde kullanılacak değerler oluşturuluyor

float sayac=0; // bigramsların miktarına göre artacak.


float adet[10]; // bigramsların adet sayıları burada depolanacak

for(int i=0; str[i]; i++){  //karakter küçültme döngüsü..
    if(str[i]!=' '){
        if('A'<=str[i] && str[i]<='Z'){    //eğer harfler A-Z arasında ise bunlara 32 sayısını ekleyerek küçültcek böylece ilerideki işlmeler kolaylaşcak
            str[i]=str[i]+32;
        }

    }
}

for(int b=0;b<10;b++)
{
  for(int i=0;i<=strlen(str);i++){                    //eğer str char dizinin içindeki ilk harfle matrix_bigram_strings ilk elemanını kıyaslar.
    if(str[i]== matrix_bigram_strings[b][a])          //eğer doğruysa bu sefer ikinci karakterleri kıyaslar buda true çıkarsa sayacı 1 arttırır yani;
    {                                                 // ilk kıyaslanacak bigramsdan, t==t ise indexleri 1 arttır th==th ise sayac=+1 eğer değilse döngüye 't' elemanı ile devam et
    if(str[i+1]==matrix_bigram_strings[b][a+1])
    sayac++;
    }

    }

    adet[b]=sayac;  // adetler sırayla kaydediliyor.
    printf("%c%c 'den cumlenin icinde %2.f tane  vardir\n",matrix_bigram_strings[b][a],matrix_bigram_strings[b][a+1],sayac); //sonuclar ekrana basılıyor
    sayac=0; // sayaç sıfırlanıyor çünkü diğer bigrmasların adetinin sonraki bigramsların adetine eklenmesini istemiyoruz
    }

    printf("\n\n\n");


    float toplam=0; //toplam bulunan bigrams adedi tutulacak.


   for(int i=0; i<10; i++){  // bütün bigram adedi toplam değişkenine atanıyor
        toplam+=adet[i];

   }

if(toplam==0){                  //eğer toplam adet sıfır ise bütün frekanslar 0 lanıyor eğer biz toplamı sıfır olarak işlem yapmaya çalışırsak 0 ra bölüm hatası verir.
    for(int i=0; i<10; i++){
        calculated_frequencies[i]=0;


    }
 }
 else{                             //toplam 0 değilse  frekanslar hesaplanıyor. mesela th bigramı için; 2 adet varsa bu tüm bulunan bigram adedine bölünerek th bigramının frekansı bulunuyor
    for(int i=0; i<10; i++){
        calculated_frequencies[i]=adet[i]/toplam;

    }
 }



    for(int i=0; i<10; i++){   //frekanslar ekrana basılıyor.
        printf("%c%c 'nin  frekansi: %f 'dir\n",matrix_bigram_strings[i][a],matrix_bigram_strings[i][a+1],calculated_frequencies[i]);


    }
printf("\n");
printf("**************************************************************************************************************");
printf("\n\n\n");


}




void calculate_frequencies_tri(char str[]) // tamamen calculate_frequencies_bi fonksiyonu ile aynı mantığa sahip sadece 3.karakter için indeksler bir kez daha arttırılıyor.
{

int a=0,b=0;

float sayac=0;
                                //değişkenlerin oluşturulması
float frekans_tri[10]; //burda ayriyeten sonuçları ekrana basmak için frequences_tri değeri oluşturuluyor

float adet[10];

for(int i=0; str[i]; i++){ //küçültme kısmı
    if(str[i]!=' '){
        if('A'<=str[i] && str[i]<='Z'){
            str[i]=str[i]+32;
        }

    }
}

for(int b=0;b<10;b++)
{
  for(int i=0;i<=strlen(str);i++){
    if(str[i]== matrix_trigram_strings[b][a])       //t==t 1 arttır: th==th ise 1 arttır the==the sayacı 1 arttır değilse th den aramaya devam et
    {
    if(str[i+1]==matrix_trigram_strings[b][a+1])
        if(str[i+2]==matrix_trigram_strings[b][a+2]){
            sayac++;
        }
    }

    }

    adet[b]=sayac;  //frekans işlemei için depolanıyor
    printf("%c%c%c 'den cumlenin icinde %2.f tane  vardir\n",matrix_trigram_strings[b][a],matrix_trigram_strings[b][a+1],matrix_trigram_strings[b][a+2],sayac); //sonuç bastırma
    sayac=0; //sayaç her işlemden sonra sıfırlanıyor sıfırlanmazsa sayacın değğeri büyür ve yanlış değerler atanır .
    }

    printf("\n\n\n");


    float toplam=0;


   for(int i=0; i<10; i++){
        toplam+=adet[i];

   }

 if(toplam==0){                    //yukardaki fonksiyonda yapılan işlemlerin aynısı yapılıyor.
    for(int i=0; i<10; i++){
        frekans_tri[i]=0;

    }
 }
 else{
    for(int i=0; i<10; i++){
        frekans_tri[i]=adet[i]/toplam;

    }
 }

    for(int i=0; i<10; i++){  //frekansları ekrana basma işlemi frekans_tri değişkeni burda işe yarıyor
        printf("%c%c%c 'nin  frekansi: %f 'dir\n",matrix_trigram_strings[i][a],matrix_trigram_strings[i][a+1],matrix_trigram_strings[i][a+2],frekans_tri[i]);


    }
    int k=10;                                   // k=10 atanıyor çünkü biz bu değerleri global deki calculated _frequencies dizisine kaydetmek istiyoruz.
    int p=0;                                    // bu dizinin zaten ilk 10 boyutu dolu olduğundan diğer 10 luk kısmına yüklemek için bu yöntemi uyguluyoruz.
    while(k<20){
        calculated_frequencies[k]=frekans_tri[p];           //depolama işlemi.
        k++;
        p++;

    }
printf("\n");
printf("**************************************************************************************************************");

}



void calculate_distances(){ //distance hesaplama

    float oklid_eng; //öklid mesefeleri bu elemanlara atancak
    float oklid_ger;


    for(int i=0; i<20; i++){    //işlemler için dögü kullanıyoruz


      oklid_eng+=pow((calculated_frequencies[i]-frequency_eng[i]),2);  // bu diziler içindeki aynı sıradaki elemanları çıkar karesini al ve topla komutu.
      oklid_ger+=pow((calculated_frequencies[i]-frequency_germ[i]),2); // bu diziler içindeki aynı sıradaki elemanları çıkar karesini al ve topla komutu.(aynı)


}
    oklid_eng=sqrt(oklid_eng); //bu toplanan değerlarin karekökünü al
    oklid_ger=sqrt(oklid_ger); //bu toplanan değerlarin karekökünü al

    distances[0]=oklid_eng; // değerleri globaldeki distance int dizisine aktar
    distances[1]=oklid_ger; // değerleri globaldeki distance int dizisine aktar


    printf("Euclidian Distance for English: %f\n",oklid_eng);  //sonuçları bastır...
    printf("Euclidian Distance for German: %f\n",oklid_ger);

    printf("\n\n");
}

void detect_lang(){ //eğer bir metnin ingilizce distance küçükkse o zaman bu dilin ingilizce olma durumu daha yüksektir aynısı almanca içinde geçerli
                    // buna dayanaraktan aşağıdaki koşullar oluşturuldu distance[0]=english_distance tutar distance[1]=german_distance tutar.
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

    char metin[]={}; // Metin girebilmek için globalde "metin" adlı karakter dizisi oluşturuldu.

    printf("metin giriniz: "); //metin alınıyor
    gets(metin);

    if(strlen(metin)>0){ //eğer hiçbir şey girilmezse kodların çalıştırılması durduruluyor eğer metin uzunluğu büyük 0 dan ise alttaki işlemler gerçekleşiyor

    printf("Metnin  uzunlugu: %d",strlen(metin)); //metin uzunluğu basılıyor
    printf("\n\n");
    filter_str(metin); //metin filtreleniyor
    printf("\n");
    calculate_frequencies_bi(metin); //bigrams frekansları hesaplanıyor
    calculate_frequencies_tri(metin); //trigrams frekansları hesaplanıyor

    printf("\n\n\n");


    printf("\n\n\n");
    calculate_distances(); //distanclar hesaplanıyor

    detect_lang(); //dil tespit ediliyor

    }
    else{ //metin uzunluğu 0 ise bu koşul gerçekleşerek uyarı metni ekrana basılır ve program durur.

        printf("\n");
        printf("Lutfen bir metin giriniz aksi taktirde isleminiz gerceklestirilemez...\n");
    }

return 0;

}
