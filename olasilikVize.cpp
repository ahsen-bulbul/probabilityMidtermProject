#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

void siraliFrekansSerisi() {
    int n;
    cout << "Kaç adet sayı gireceksiniz? ";
    cin >> n;

    if (n <= 0) {
        cout << "Geçerli bir sayı giriniz.\n";
        return;
    }

    vector<int> dizi(n);
    cout << "Sayıları girin: ";
    for (int i = 0; i < n; ++i) {
        cin >> dizi[i];
    }

    // Sıralama
    sort(dizi.begin(), dizi.end());

    cout << "\nKüçükten büyüğe sıralı dizi:\n";
    for (int sayi : dizi) {
        cout << sayi << " ";
    }
    cout << endl;

    // Frekans Serisi
    map<int, int> frekans;
    for (int sayi : dizi) {
        frekans[sayi]++;
    }

    cout << "\nFrekans Serisi:\n";
    cout << "Sayı\tFrekans\n";
    for (const auto& pair : frekans) {
        cout << pair.first << "\t" << pair.second << endl;
    }
}

void frekanstab() {
    int n;
    cout << "Kac adet deger gireceksiniz: ";
    cin >> n;

    int r, k, sf = 0, sfsayac = 1, toplam = 0;
    float h, snc, rydk;

    vector<double> veri(n);

    // Veri alma
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". Degeri giriniz: ";
        cin >> veri[i];
    }

    // Sıralama (Bubble sort)
    for (int i = 0; i < n; i++) {
        for (int y = 0; y < (n - 1); y++) {
            if (veri[y + 1] < veri[y]) {
                double temp = veri[y + 1];
                veri[y + 1] = veri[y];
                veri[y] = temp;
            }
        }
    }

    // Sınıf sayısını hesapla
    h = sqrt(n);
    k = ceil(h);
    cout << k << ":k" << endl;

    vector<float> sfdizi(k);
    vector<float> efdizi(k);

    r = veri[n - 1] - veri[0];

    if (r % k == 0) {
        rydk = r;
        snc = r / k;
    }
    else {
        rydk = r;
        snc = r / k;
        snc++;
    }
    cout << "Sınıf genişliği: " << snc << endl;

    cout << "Sinif limitleri" << endl;
    cout << " " << endl;
    for (int i = 0; i < k; i++) {
        if (veri[0] - ceil(veri[0]) != 0) {
            cout << (veri[0] + (snc * i)) << "       " << veri[0] + (snc * (i + 1)) - 0.1 << endl;
        }
        else {
            cout << (veri[0] + (snc * i)) << "       " << veri[0] + (snc * (i + 1)) - 1 << endl;
        }
    }

    cout << "Sinif sinirlari" << endl;
    cout << " " << endl;
    if (veri[0] - ceil(veri[0]) != 0) {
        cout << fixed << setprecision(5);
        cout << (((veri[0] + snc) + (veri[0] + snc - 0.1)) / 2) - snc << "     " << (((veri[0] + snc) + (veri[0] + snc - 0.1)) / 2) << endl;
        for (int i = 0; i < k - 1; i++) {
            float alttut = (((veri[0] + snc) + (veri[0] + snc - 0.1)) / 2) + (snc * i);
            float usttut = (((veri[0] + snc) + (veri[0] + snc - 0.1)) / 2) + (snc * (i + 1));
            cout << alttut << "     " << usttut << endl;
        }
    }
    else {
        cout << fixed << setprecision(5);
        cout << (((veri[0] + snc) + (veri[0] + snc - 1)) / 2) - snc << "     " << (((veri[0] + snc) + (veri[0] + snc - 1)) / 2) << endl;
        for (int i = 0; i < k - 1; i++) {
            float alttut = (((veri[0] + snc) + (veri[0] + snc - 1)) / 2) + (snc * i);
            float usttut = (((veri[0] + snc) + (veri[0] + snc - 1)) / 2) + (snc * (i + 1));
            cout << alttut << "     " << usttut << endl;
        }
    }

    cout << "Sinif Frekansi" << endl;
    cout << " " << endl;
    for (int i = 0; i < n; i++) {
        if ((((veri[0] + snc) + (veri[0] + snc - 1)) / 2 - snc) < veri[i] && veri[i] < (((veri[0] + snc) + (veri[0] + snc - 1)) / 2)) {
            sf++;
        }
    }
    sfdizi[0] = sf;
    cout << "      " << sf << "      " << endl;
    sf = 0;

    for (int i = 0; i < k - 1; i++) {
        for (int y = 0; y < n; y++) {
            if (((((veri[0] + snc) + (veri[0] + snc - 1)) / 2) + (snc * i)) < veri[y] &&
                veri[y] < ((((veri[0] + snc) + (veri[0] + snc - 1)) / 2) + (snc * (i + 1)))) {
                sf++;
            }
        }
        sfdizi[sfsayac] = sf;
        sfsayac++;
        cout << "      " << sf << "      " << endl;
        sf = 0;
    }

    cout << "Sinif orta noktasi" << endl;
    cout << " " << endl;
    for (int i = 0; i < k; i++) {
        cout << "     " << ((veri[0] + (snc * i)) + (veri[0] + (snc * (i + 1)) - 1)) / 2 << "      " << endl;
    }

    cout << "Eklenik frekans" << endl;
    cout << " " << endl;
    for (int i = 0; i < k; i++) {
        toplam += sfdizi[i];
        efdizi[i] = toplam;
        cout << "      " << toplam << "      " << endl;
    }

    cout << "Oransal eklenik frekans" << endl;
    cout << " " << endl;
    for (int i = 0; i < k; i++) {
        cout << fixed << setprecision(2);
        cout << "      " << efdizi[i] / n << "      " << endl;
    }

    cout << "Oransal frekans" << endl;
    cout << " " << endl;
    for (int i = 0; i < k; i++) {
        cout << fixed << setprecision(2);
        cout << "       " << sfdizi[i] / n << "       " << endl;
    }
}

// Ortalama hesaplama fonksiyonu
double ortalama(const vector<int>& dizi) {
    double toplam = 0;
    for (int sayi : dizi) {
        toplam += sayi;
    }
    return toplam / dizi.size();
}

// Medyan hesaplama fonksiyonu
double medyan(vector<int> dizi) {
    sort(dizi.begin(), dizi.end());
    int n = dizi.size();
    if (n % 2 == 0) {
        return (dizi[n / 2 - 1] + dizi[n / 2]) / 2.0;
    }
    else {
        return dizi[n / 2];
    }
}

// Mod hesaplama fonksiyonu
int mod(const vector<int>& dizi) {
    map<int, int> frekans;
    for (int sayi : dizi) {
        frekans[sayi]++;
    }

    int mod_deger = dizi[0];
    int max_frekans = 0;
    for (const auto& pair : frekans) {
        if (pair.second > max_frekans) {
            max_frekans = pair.second;
            mod_deger = pair.first;
        }
    }

    return mod_deger;
}

// Varyans hesaplama fonksiyonu
double varyans(const vector<int>& dizi) {
    double ort = ortalama(dizi);
    double toplam = 0;
    for (int sayi : dizi) {
        toplam += pow(sayi - ort, 2);
    }
    return toplam / dizi.size();
}

// Standart sapma hesaplama fonksiyonu
double standartSapma(const vector<int>& dizi) {
    return sqrt(varyans(dizi));
}

void merkezi() {
    int n;
    cout << "Kaç tane sayı gireceksiniz? ";
    cin >> n;

    if (n <= 0) {
        cout << "Geçerli bir sayı girilmedi.\n";
        return;
    }

    vector<int> dizi(n);
    cout << "Sayıları girin: ";
    for (int i = 0; i < n; i++) {
        cin >> dizi[i];
    }
    cout << "\nMerkezi Dağılım Ölçüleri:\n";
    cout << "Ortalama: " << ortalama(dizi) << endl;
    cout << "Medyan: " << medyan(dizi) << endl;
    cout << "Mod: " << mod(dizi) << endl;
    cout << "Varyans: " << varyans(dizi) << endl;
    cout << "Standart Sapma: " << standartSapma(dizi) << endl;
}

void frekansSerisi() {
    int n;
    cout << "Kaç tane sayı gireceksiniz? ";
    cin >> n;

    if (n <= 0) {
        cout << "Geçerli bir sayı girilmedi.\n";
        return;
    }

    vector<int> dizi(n);
    cout << "Sayıları girin: ";
    for (int i = 0; i < n; i++) {
        cin >> dizi[i];
    }

    // Frekans tablosu
    map<int, int> frekanslar;
    for (int sayi : dizi) {
        frekanslar[sayi]++;
    }

    cout << "\nFrekans Tablosu:\n";
    cout << "Sayı\tFrekans\n";
    for (const auto& pair : frekanslar) {
        cout << pair.first << "\t" << pair.second << endl;
    }


    // Merkezi dağılım ölçüleri
    cout << "\nMerkezi Dağılım Ölçüleri:\n";
    cout << "Ortalama: " << ortalama(dizi) << endl;
    cout << "Medyan: " << medyan(dizi) << endl;
    cout << "Mod: " << mod(dizi) << endl;
    cout << "Varyans: " << varyans(dizi) << endl;
    cout << "Standart Sapma: " << standartSapma(dizi) << endl;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void rasgele() {
    int alt, ust, adet;
    cout << "Alt değeri girin: ";
    cin >> alt;
    cout << "Üst değeri girin: ";
    cin >> ust;

    if (alt > ust) {
        cout << "Alt değer üst değerden büyük olamaz.\n";
        return;
    }

    cout << "Kaç adet sayı üretmek istiyorsunuz? ";
    cin >> adet;

    int aralik = ust - alt + 1;
    vector<int> sayilar;
    srand(time(0));

    if (adet <= aralik) {
        // Eşsiz sayılar üretilecek
        vector<int> tum_sayilar;
        for (int i = alt; i <= ust; ++i) {
            tum_sayilar.push_back(i);
        }
        random_shuffle(tum_sayilar.begin(), tum_sayilar.end());

        for (int i = 0; i < adet; ++i) {
            sayilar.push_back(tum_sayilar[i]);
        }
    }
    else {
        // Aynı sayı birden fazla üretilebilir
        for (int i = 0; i < adet; ++i) {
            int rastgele_sayi = rand() % aralik + alt;
            sayilar.push_back(rastgele_sayi);
        }
    }

    // Küçükten büyüğe sırala
    sort(sayilar.begin(), sayilar.end());

    cout << "Üretilen Sayılar (küçükten büyüğe):\n";
    for (int sayi : sayilar) {
        cout << sayi << " ";
    }
    cout << endl;
}



// Örnekleme fonksiyonu (örnek)
void ornekleme() {
    int max_deger, ornek_sayisi;
    cout << "Maksimum değer girin: ";
    cin >> max_deger;

    cout << "Kaç tane örnek üretmek istiyorsunuz? ";
    cin >> ornek_sayisi;

    if (ornek_sayisi <= 0 || max_deger <= 0) {
        cout << "Geçersiz giriş! Değerler pozitif olmalıdır.\n";
        return;
    }

    double k = static_cast<double>(max_deger) / ornek_sayisi;

    srand(time(0));
    int baslangic = rand() % static_cast<int>(k) + 1;

    vector<int> orneklem;
    for (int i = 0; i < ornek_sayisi; i++) {
        int eleman = static_cast<int>(baslangic + i * k);
        if (eleman > max_deger) break;
        orneklem.push_back(eleman);
    }

    cout << "Sistematik Örnekleme Sonucu:\n";
    for (int sayi : orneklem) {
        cout << sayi << " ";
    }
    cout << endl;
}

void basitSeri() {
    int adet;
    cout << "Kaç adet sayı gireceksiniz? ";
    cin >> adet;

    if (adet <= 0) {
        cout << "Geçerli bir sayı giriniz.\n";
        return;
    }

    vector<int> dizi(adet);
    cout << "Sayıları girin: ";
    for (int i = 0; i < adet; ++i) {
        cin >> dizi[i];
    }

    sort(dizi.begin(), dizi.end());

    cout << "Küçükten büyüğe sıralı dizi:\n";
    for (int sayi : dizi) {
        cout << sayi << " ";
    }
    cout << endl;
}


int main() {
    setlocale(LC_ALL, "");
    int secim;

    do {
        cout << "\n2025 Olasılık Vize Ödevi\n"<<endl;
        cout << "1 - Rastgele Sayı Üret\n";
        cout << "2 - Sistematik Rastgele Örnekleme Yap\n";
        cout << "3 - Basit Sıralı Seri Oluştur\n";
        cout << "4 - Frekans Serisi\n";
        cout << "5 - Frekans Tablosu\n";
        cout << "6 - Merkezi Dağılım Ölçüleri\n";
        cout << "7 - Basit Seri + Frekans Serisi\n";
        cout << "0 - Çıkış\n";
        cout << "Seçiminizi yapın: ";
        cin >> secim;

        switch (secim) {
        case 1:
            rasgele();
            break;
        case 2:
            ornekleme();
            break;
        case 3:
            basitSeri();
            break;
        case 4:
            frekansSerisi();
            break;
        case 5:
            frekanstab();
            break;
        case 6:
            merkezi();
            break;
        case 7:
            siraliFrekansSerisi();
            break;
        case 0:
            cout << "Programdan çıkılıyor...\n";
            break;
        default:
            cout << "Geçersiz seçim! Lütfen tekrar deneyin.\n";
        }

    } while (secim != 0);

    return 0;
}




// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
