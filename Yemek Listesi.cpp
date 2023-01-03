/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   PROGRAMLAMAYA GİRİŞ DERSİ
**					2022/2023 GÜZ DÖNEMİ
**
**				PROJE NUMARASI..........:1
**				ÖĞRENCİ ADI............:YUNUS EMRE YILMAZ
**				ÖĞRENCİ NUMARASI.......:G211210044
**                         DERSİN ALINDIĞI GRUP...:1.OGRETIM/A GRUBU
****************************************************************************/
#include<iostream>
#include<clocale>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<fstream>
#include<istream>
#include<ostream>
#include<cstdio>
#include<cstdio>
using namespace std;
char menu_secimi = 'e';//menu islemini devam ettirebilmek icin
string urun_adi_karsilastirma;//urun arama yapabilmek icin
string yemek_cesidi_karsilastirma;//yemek cesidi aramasi yapabilmek icin
char giris_islemi, urun_islemi;//giris ve urun islemini yapmak icin
char yemek_cesidi_islemi;//yemek islemini yapmak icin
string yemek_menusu[5];//restoranin gunluk yemek menusu
string yemek_cesidi, yemeklik_malzeme1, yemeklik_malzeme2, yemeklik_malzeme3, yemeklik_malzeme4;//yemek cesidi eklerken kullanilacak degiskenler
int yemeklik_malzeme1_kisi, yemeklik_malzeme2_kisi, yemeklik_malzeme3_kisi, yemeklik_malzeme4_kisi;//yemek cesidi eklerken kullanilacak degiskenler
string urun_adi, uretim_tarihi, tuketim_tarihi;//urun eklerken kullanilacak degiskenler
int kalori_gram, stok_adet_kilo, alis_fiyati, satis_fiyati;//urun eklerken kullanilacak degiskenler
string yemek_menusu1, yemek_menusu2, yemek_menusu3, yemek_menusu4, yemek_menusu5;//gunluk cikarilacak olan yemek menusu belirleniyor.
//arayuz icin bir fonksiyon tanimlaniyor.
void grafik()
{
	for (int i = 0; i < 80; i++)
	{
		cout << "-";
	}
	cout << endl;
}
//ilk giriste yapilacak olan secim icin menu olusturuluyor.
void giris_islemi_menusu()
{
	grafik();
	cout << "*****GIRIS ISLEMI MENUSU*****" << endl;
	grafik();
	cout << "Lutfen yapmak istediginiz islemi giriniz:" << endl;
	cout << "1)Urun hakkinda bir islem:" << endl;
	cout << "2)Yemek cesidi hakkinda bir islem:" << endl;
	cout << "3)Menuye yemek cesidi belirleme hakkinda bir islem:" << endl;
	cin >> giris_islemi;
	//secilen isleme gore istenilen islmei yapacak.
	grafik();
}
//urun islemleri icin bir menu taminlaniyor ve secim yaptiriliyor.
void urun_islemi_menusu()
{
	grafik();
	cout << "*****URUN ISLEMI MENUSU*****" << endl;
	grafik();
	cout << "Lutfen yapmak istediginiz islemi seciniz:" << endl;
	cout << "1)Urun Ekleme:" << endl;
	cout << "2)Urun Silme:" << endl;
	cout << "3)Urun Arama:" << endl;
	cout << "4)Urun Guncelleme:" << endl;
	cout << "5)Urun Listeleme:" << endl;
	cin >> urun_islemi;
	//secilen urun islemine gore ilgili islem yapilacak.
	grafik();
}
//depoya yeni bir urun ekleme islemi yapiliyor.
void urun_ekleme()
{
	grafik();
	cout << "*****URUN EKLEME*****" << endl;
	grafik();
	//dosyaya bir sey yazmak icin tanimlama yapilir.
	ofstream u_ekle;
	//depo.txt aciliyor.
	u_ekle.open("depo.txt", ios::app);
	cout << "Urunun adini giriniz:" << endl;
	cin >> urun_adi;
	cout << "Urunun uretim tarihini giriniz:" << endl;
	cin >> uretim_tarihi;
	cout << "Urunun tuketim tarihini giriniz:" << endl;
	cin >> tuketim_tarihi;
	cout << "Urunun kalori gramini giriniz:" << endl;
	cin >> kalori_gram;
	cout << "Urunun stok adet kilosunu giriniz:" << endl;
	cin >> stok_adet_kilo;
	cout << "Urunun kilogram alis fiyatini giriniz:" << endl;
	cin >> alis_fiyati;
	cout << "Urunun kilogram satis fiyatini giriniz:" << endl;
	cin >> satis_fiyati;
	grafik();
	cout << "Urun ekleme islemi basariyla tamamlanmistir." << endl;
	grafik();
	//girilen bilgiler depo.txt'ye yazdiriliyor
	u_ekle << urun_adi << "\t" << uretim_tarihi << "\t" << tuketim_tarihi << "\t" << kalori_gram << "\t" << stok_adet_kilo << "\t" << alis_fiyati << "\t" << satis_fiyati << "\n";
	//depo.txt kapatiliyor.
	u_ekle.close();
}
//depodan urun silme islemi yapiliyor.
void urun_silme()
{
	grafik();
	cout << "*****URUN SILME*****" << endl;
	grafik();
	//depo txt'yi okumak ve icine veri eklemek icin degiskenler tanimlaniyor.
	ifstream u_s_arama;
	ofstream u_s_ekle;
	//depo.txt ve depo_gecici.txt dosyalari aciliyor.
	u_s_arama.open("depo.txt", ios::app);
	u_s_ekle.open("depo_gecici.txt", ios::app);
	grafik();
	cout << "Lutfen silmek istediginiz urunun adini giriniz:" << endl;
	cin >> urun_adi_karsilastirma;
	int a = 0;
	//depo.txt dosyasini son satira kadar okuyor ve bitince donguden cikiyor.
	while (!u_s_arama.eof())
	{
		//depo.txt dosyasinda bulunan bilgileri satir satir okuyor.
		u_s_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
		//depo.txt dosyasinin sonuna gelince iceri giriyor ve donguden komple cikiyor.
		if (u_s_arama.eof())
		{
			break;
		}
		//silmek istedigin urunu bulunca blogun icine giriyor ve onun bilgilerini dosyaya yazdirmadan disari cikiyor.
		if (urun_adi == urun_adi_karsilastirma)
		{
			grafik();
			cout << "*****URUN SİLME İSLEMİ BASARİYLA TAMAMLANMİSTİR.*****" << endl;
			grafik();
			//a=1 olunca dongunun disindaki if blogunun icine girmiyor ve urun basariyla silinmis oluyor.
			a = 1;
			continue;
		}
		else
		{
			//diger urunlerin bilgilerini ayni sekil depog_gecici.txt dosyasina yazdirmaya devam ediyor.
			u_s_ekle << urun_adi << "\t" << uretim_tarihi << "\t" << tuketim_tarihi << "\t" << kalori_gram << "\t" << stok_adet_kilo << "\t" << alis_fiyati << "\t" << satis_fiyati << endl;
		}
	}
	//a degiskeni hala 0 ise aradigimiz isimde bir urun bulunamadigini isaret eder ve en son bir mesaj yazdirir.
	if (a == 0)
	{
		grafik();
		cout << "*****ARADIGINIZ ISIMDE URUN BULUNMAMAKTADIR.*****" << endl;
		grafik();
	}
	//depo.txt ve depo_gecici.txt dosyalari kapatiliyor.
	u_s_arama.close();
	u_s_ekle.close();
	//depo.txt dosyasi siliniyor
	remove("depo.txt");
	//depo_gecici.txt dosyasi depo.txt dosyasina aktariliyor.
	rename("depo_gecici.txt" , "depo.txt");
}
//depodan urun arama islemi yapiliyor.
void urun_arama()
{
	//depo.txt'den urun okumak icin tanimalniyor.
	ifstream u_arama;
	grafik();
	cout << "*****URUN ARAMA*****" << endl;
	grafik();
	//depo.txt dosyasi aciliyor.
	u_arama.open("depo.txt", ios::app);
	cout << "Aramak istediginiz urunun adini giriniz:" << endl;
	cin >> urun_adi_karsilastirma;
	grafik();
	cout << endl;
	int a = 0;
	//depo.txt dosyasini son satira kadar okuyor ve bitince dongunun disina cikiyor.
	while (!u_arama.eof())
	{
		//depo.txt'deki dosyalari teker teker son satira kadar okuyor.
		u_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
		//aradaigimiz urun bulununca iceri girer ve urunun bilgilerini yazdirip komple donguden disari cikar.
		if (urun_adi == urun_adi_karsilastirma)
		{
			grafik();
			cout << "*****Aradiginiz urun bulunmustur. Bilgileri:*****" << endl;
			cout << urun_adi << "\t" << uretim_tarihi << "\t" << tuketim_tarihi << "\t" << kalori_gram << "\t" << stok_adet_kilo << "\t" << alis_fiyati << "\t" << satis_fiyati << "\n";
			grafik();
			//a=1 olunca dongunun disindaki if blogunun icine girmiyor ve urun basariyla aranmis oluyor.
			a = 1;
			break;
		}
	}
	//a hala 0 ise iceri girer ve aranan isimde bir urun bulunamadigini gostermek icin mesaj verir.
	if (a == 0)
	{
		grafik();
		cout << "Aradiginiz isimde bir urun bulunamamistir." << endl;
		grafik();
	}
	//depo.txt dosyasi kapatilir.
	u_arama.close();
}
//depodan urun guncelleme islemi yapiliyor.
void urun_guncelleme()
{
	grafik();
	cout << "*****URUN GUNCELLEME*****" << endl;
	grafik();
	cout << "Guncellemek istediginiz urunun adini giriniz:" << endl;
	cin >> urun_adi_karsilastirma;
	grafik();
	//depo.txt'den urun okuma ve urun ekleme islemleri icin degiskenler tanimlaniyor.
	ifstream u_d_arama;
	ofstream u_d_ekle;
	//depo.txt ve depo_gecici.txt dosyalari tanimlaniyor.
	u_d_arama.open("depo.txt", ios::app);
	u_d_ekle.open("depo_gecici.txt", ios::app);
	int a = 0;
	//depo.txt dosyasi satir satir okunuyor ve bitince disari cikiyor.
	while (!u_d_arama.eof())
	{
		//depo.txt'deki bilgiler bilgiler satir satir okunuyor.
		u_d_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
		//okuma bitince dongunun en disina cikar.
		if (u_d_arama.eof())
			break;
		//guncellenecek urun bulunca iceri girer eski bilgileri yazdirip yeni bligilerini ister ve depo_gecici.txt dosyasina ekler ve diger urunleri depo_gecici.txt dosyasina yazdirmaya devam eder.
		if (urun_adi == urun_adi_karsilastirma)
		{
			grafik();
			cout << "*****Guncellemek istediginiz urunun bilgileri:*****" << endl;
			cout << urun_adi << "\t" << uretim_tarihi << "\t" << tuketim_tarihi << "\t" << kalori_gram << "\t" << stok_adet_kilo << "\t" << alis_fiyati << "\t" << satis_fiyati << "\n";
			grafik();
			cout << "*****Guncellemek istediginiz urunun yeni bilgilerini giriniz:*****" << endl;
			grafik();
			cout << "Urunun adini giriniz:" << endl;
			cin >> urun_adi;
			cout << "Urunun uretim tarihini giriniz:" << endl;
			cin >> uretim_tarihi;
			cout << "Urunun tuketim tarihini giriniz:" << endl;
			cin >> tuketim_tarihi;
			cout << "Urunun kalori gramini giriniz:" << endl;
			cin >> kalori_gram;
			cout << "Urunun stok adet kilosunu giriniz:" << endl;
			cin >> stok_adet_kilo;
			cout << "Urunun kilogram alis fiyatini giriniz:" << endl;
			cin >> alis_fiyati;
			cout << "Urunun kilogram satis fiyatini giriniz:" << endl;
			cin >> satis_fiyati;
			grafik();
			cout << "Urun guncelleme islemi basariyla tamamlanmistir." << endl;
			grafik();
			u_d_ekle << urun_adi << "\t" << uretim_tarihi << "\t" << tuketim_tarihi << "\t" << kalori_gram << "\t" << stok_adet_kilo << "\t" << alis_fiyati << "\t" << satis_fiyati << "\n";
			a = 1;
			continue;
		}
		else
		{
			u_d_ekle << urun_adi << "\t" << uretim_tarihi << "\t" << tuketim_tarihi << "\t" << kalori_gram << "\t" << stok_adet_kilo << "\t" << alis_fiyati << "\t" << satis_fiyati << "\n";
		}
	}
	if (a==0)
	{
		grafik();
		cout << "*****Aradiginiz isimde bir urun bulunmamaktadir.*****" << endl;
		grafik();
	}
	//okuma ve yazdirma degiskenleri kapatiliyor.
	u_d_ekle.close();
	u_d_arama.close();
	//depo.txt dosyasi siliniyor.
	remove("depo.txt");
	//depo_gecici.txt dosyasi depo.txt dosyasina aktariliyor.
	rename("depo_gecici.txt" , "depo.txt");
}
//depodan urun listeleme islemi yapiliyor.
void urun_listeleme()
{
	grafik();
	cout << "*****Urun Listeleme*****" << endl;
	grafik();
	//urun okumak icin degisken tanimlaniyor.
	ifstream u_listeleme;
	//depo.txt dosyasi aciliyor.
	u_listeleme.open("depo.txt", ios::app);
	//dosyanin sonuna kadar okuyor ve bitince dongu disina cikiyor.
	while (!u_listeleme.eof())
	{
		//dosyadaki bilgiler satir satir okunuyor.
		u_listeleme>> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
		//satir sonuna gelince bir alt satira iniyor.
		if (urun_adi ==" ")
			continue;
		//dosya bitnce donguden disari cikiyor.
		else if (u_listeleme.eof())
			break;
		//dosyadaki urunleri yazdirmaya devam ediyor.
		else 
			cout << urun_adi << "\t" << uretim_tarihi << "\t" << tuketim_tarihi << "\t" << kalori_gram << "\t" << stok_adet_kilo << "\t" << alis_fiyati << "\t" << satis_fiyati << "\n";
	}
}
//yemek cesidi islemleri icin bir menu tanimlaniyor ve secim yaptiriliyor.
void yemek_cesidi_islemi_menusu()
{
	grafik();
	cout << "*****YEMEK CESIDI ISLEMI MENUSU*****" << endl;
	grafik();
	cout << "Lutfen yapmak istediginiz islemi seciniz:" << endl;
	cout << "1)Yemek Cesidi Ekleme:" << endl;
	cout << "2)Yemek cesidi Silme:" << endl;
	cout << "3)Yemek cesidi Arama:" << endl;
	cout << "4)Yemek Cesidi Guncelleme:" << endl;
	cout << "5)Yemek Cesidi Listeleme:" << endl;
	cin >> yemek_cesidi_islemi;
	//yapilan secime gore ilgili islem yaptiriliyor.
	grafik();
}
//yemek cesidine yemek cesidi ve malzemeye yenek cesidi ve gerekli olan malzemeler ekleniyor.
void yemek_cesidi_ekleme()
{
	grafik();
	cout << "*****YEMEK CESIDI EKLEME*****" << endl;
	grafik();
	//yemek cesidi eklemek icin tanimlaniyor.
	ofstream y_c_ekle;
	//yemekcesidi.txt dosyasi aciliyor.
	y_c_ekle.open("yemekcesidi.txt", ios::app);
	//malzeme eklemek icin tanimlaniyor
	ofstream malzeme_ekle;
	//malzeme.txt dosyasi aciliyor.
	malzeme_ekle.open("malzeme.txt", ios::app);
	cout << "Eklemek istediginiz yemek cesidini giriniz:" << endl;
	cin >> yemek_cesidi;
	//yemekcesidi.txt dosyasina ekleniyor.
	y_c_ekle << yemek_cesidi << "\n";
	grafik();
	cout << "Yemek icin gerekli olan malzemeleri 1 kisilik kullanim miktari ile eksiksiz giriniz:" << endl;
	cin >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
	cout << endl;
	grafik();
	//malzeme.txt dosyasina ekleniyor.
	malzeme_ekle << yemek_cesidi << "\t" << yemeklik_malzeme1 << "\t" << yemeklik_malzeme1_kisi << "\t" << yemeklik_malzeme2 << "\t" << yemeklik_malzeme2_kisi << "\t" << yemeklik_malzeme3 << "\t" << yemeklik_malzeme3_kisi << "\t" << yemeklik_malzeme4 << "\t" << yemeklik_malzeme4_kisi << "\n";
	cout << "*****Yemek cesidi ekleme islemi basariyla tamamlanmistir*****" << endl;
	grafik();
	//yemek cesidi ve malzeme ekleme degiskenleri kapatiliyor.
	y_c_ekle.close();
	malzeme_ekle.close();
}
//yemek cesidi silme islemi yapiliyor.
void yemek_cesidi_silme()
{
	grafik();
	cout << "*****YEMEK CESIDI SILME*****" << endl;
	grafik();
	//yemek cesidi ekleme arama ve malzeme arama ekleme degiskenleri tanimlaniyor.
	ifstream y_c_arama;
	ifstream malzeme_arama;
	ofstream y_c_ekle;
	ofstream malzeme_ekle;
	//yemekcesidi.txt yemekcesidigecicitxt ve malzemetxt malzemegecicitxt dosyalari aciliyor.
	y_c_arama.open("yemekcesidi.txt", ios::app);
	y_c_ekle.open("yemekcesidi_gecici.txt", ios::app);
	malzeme_arama.open("malzeme.txt", ios::app);
	malzeme_ekle.open("malzeme_gecici.txt", ios::app);
	grafik();
	cout << "Lutfen silmek istediginiz yemegin ismini giriniz:" << endl;
	cin >> yemek_cesidi_karsilastirma;
	grafik();
	int a = 0;
	//yemekcesidi dosyasi okunuyor ve bitince disari cikiyor
	while (!y_c_arama.eof())
	{
		//yemek cesidini satir satir okuyor.
		y_c_arama >> yemek_cesidi;
		//yemek cesidi okuma bitince komple disari cikiyor.
		if (y_c_arama.eof())
		{
			break;
		}
		//arana yemek cesidi bulunduysa iceri girilir ve yemek cesidi silinir ve diger yemek cesitlerini yazdirmaya devam eder.
		if (yemek_cesidi == yemek_cesidi_karsilastirma)
		{
			grafik();
			cout << "*****YEMEK CESIDI SILME ISLEMI BASARIYLA TAMAMLANMISTIR.*****" << endl;
			grafik();
			a = 1;
			continue;
		}
		//diger kalan yemek cesitlerini yazdirmaya devam eder
		else
		{
			y_c_ekle << yemek_cesidi << "\n";
		}
	}
	//malzemetxt dosyasini okur ve bitince dongu disina cikar
	while (!malzeme_arama.eof())
	{
		//malzemeleri satir satir okuyor.
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		//malzeme okuma bitince komple disari cikiyor.
		if (malzeme_arama.eof())
			break;
		//aranan malzeme bulunca yazdirmiyor ve devam ediyor.
		if (yemek_cesidi == yemek_cesidi_karsilastirma)
		{
			continue;
		}
		//diger malzemeleri yazdirmaya devam ediyor.
		else
		{
			malzeme_ekle << yemek_cesidi << "\t" << yemeklik_malzeme1 << "\t" << yemeklik_malzeme1_kisi << "\t" << yemeklik_malzeme2 << "\t" << yemeklik_malzeme2_kisi << "\t" << yemeklik_malzeme3 << "\t" << yemeklik_malzeme3_kisi << "\t" << yemeklik_malzeme4 << "\t" << yemeklik_malzeme4_kisi << "\n";
		}
	}
	//a degiskeni hala 0 ise dongunun icindeki mesaji yazdiriyor.
	if (a == 0)
	{
		grafik();
		cout << "*****ARADIGINIZ ISIMDE BIR YEMEK CESIDI BULUNMAMAKTADIR.*****" << endl;
		grafik();
	}
	//acilan okuma ve ekleme degiskenleri kapatiliyor.
	y_c_arama.close();
	y_c_ekle.close();
	malzeme_arama.close();
	malzeme_ekle.close();
	//yemekcesiditxt ve ymalzemetxt dosyalari siliniyor
	remove("yemekcesidi.txt");
	//yemekcesidigecicitxt yemekcesiditxt dosyasina akatariliyor
	rename("yemekcesidi_gecici.txt" , "yemekcesidi.txt");
	remove("malzeme.txt");
	//malzemegecicitxt malzemetxt dosyasina aktariliyor.
	rename("malzeme_gecici.txt" , "malzeme.txt");
}
//yemek cesidi arama islemi yapiliyor.
void yemek_cesidi_arama()
{
	grafik();
	cout << "*****YEMEK CESIDI ARAMA*****" << endl;
	grafik();
	cout << "ARAMAK ISTEDIGINIZ YEMEK CESIDININ ADINI GIRINIZ:" << endl;
	cin >> yemek_cesidi_karsilastirma;
	grafik();
	cout << endl;
	//yemek cesidi ve malzeme arama icin degiskenler tanimlaniyor.
	ifstream y_c_arama;
	ifstream malzeme_arama;
	//malzeme ve yemek cesidi txt dosyalari aciliyor.
	malzeme_arama.open("malzeme.txt", ios::app);
	y_c_arama.open("yemekcesidi.txt", ios::app);
	int a = 0;
	//yemekcesidi dosyasi aciliyor ve satir satir okunuyor bitince dongu disina cikiyor.
	while (!y_c_arama.eof())
	{
		//satir satir yemek cesitleri okunuyor
		y_c_arama >> yemek_cesidi;
		//yemek cesidi bulununca dongunun icine giriliyor
		if (yemek_cesidi == yemek_cesidi_karsilastirma)
		{
			//malzeme dosyasi satir satir okunuyor vr bitince komple dongu disina cikiyor.
			while (!malzeme_arama.eof())
			{
				//malzemeler satir satir okunuyor
				malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
				//yemek cesidi bulununca bilgileri yazdiriliyor ve komple dongu disina cikiliyor.
				if (yemek_cesidi == yemek_cesidi_karsilastirma)
				{
					grafik();
					cout << "*****Aradiginiz yemek cesidi bulunmustur. Bilgileri:*****" << endl;
					cout << yemek_cesidi << "\t" << yemeklik_malzeme1 << "\t" << yemeklik_malzeme1_kisi << "\t" << yemeklik_malzeme2 << "\t" << yemeklik_malzeme2_kisi << "\t" << yemeklik_malzeme3 << "\t" << yemeklik_malzeme3_kisi << "\t" << yemeklik_malzeme4 << "\t" << yemeklik_malzeme4_kisi << "\n";
					grafik();
					a = 1;
					break;
				}
			}
		}
	}
	//a hala 0 ise gerekli mesaj veriliyor.
	if (a == 0)
	{
		grafik();
		cout << "*****Aradiginiz isimde bir yemek cesidi bulunamamistir.*****" << endl;
		grafik();
	}
	//yemek cesidi ve malzeme arama dosyalari kapatiliyor.
	y_c_arama.close();
	malzeme_arama.close();
}
//yemek cesidi guncelleme islemi yapiliyor.
void yemek_cesidi_guncelleme()
{
	grafik();
	cout << "*****YEMEK CESIDI GUNCELLEME*****" << endl;
	grafik();
	//yemekcesidi ve malzeme arama degiskenleri tanimlaniyor.
	ifstream y_c_arama;
	ifstream malzeme_arama;
	//yemek cesidi ve malzeme ekleme degiskenleri tanimlaniyor.
	ofstream y_c_ekle;
	ofstream malzeme_ekle;
	//gerekli dosyalar okuma ve yazma islemleri icin aciliyor.
	y_c_arama.open("yemekcesidi.txt", ios::app);
	y_c_ekle.open("yemekcesidi_gecici.txt", ios::app);
	malzeme_arama.open("malzeme.txt", ios::app);
	malzeme_ekle.open("malzeme_gecici.txt", ios::app);
	grafik();
	cout << "Lutfen guncellemek istediginiz yemek cesidinin ismini giriniz:" << endl;
	cin >> yemek_cesidi_karsilastirma;
	grafik();
	cout << endl;
	int a = 0;
	//yemek cesidi dosyasi satir satir okunuyor ve bitince dongu disina cikiliyor.
	while (!y_c_arama.eof())
	{
		//yemek cesitleri satir satir okunuyor.
		y_c_arama >> yemek_cesidi;
		//dosya bitince dongu disina cikiliyor.
		if (y_c_arama.eof()) break;
		//yemek cesidi bulunca iceri girilipi gerekli malzemelerde bulunup yazdirma islemi yapiliyor ve yenii malzeme ve yemek cesidinin girilmesi isteniyor.
		if (yemek_cesidi == yemek_cesidi_karsilastirma)
		{
			while (!malzeme_arama.eof())
			{
				malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
				if (malzeme_arama.eof()) break;
				if (yemek_cesidi == yemek_cesidi_karsilastirma)
				{
					grafik();
					cout << "*****Guncellemek istediginiz yemek cesidinin bilgileri:*****" << endl;
					cout << yemek_cesidi << "\t" << yemeklik_malzeme1 << "\t" << yemeklik_malzeme1_kisi << "\t" << yemeklik_malzeme2 << "\t" << yemeklik_malzeme2_kisi << "\t" << yemeklik_malzeme3 << "\t" << yemeklik_malzeme3_kisi << "\t" << yemeklik_malzeme4 << "\t" << yemeklik_malzeme4_kisi << "\n";
					grafik();
					grafik();
					cout << "*****Guncellemek istediginiz yemek cesidinin yeni bilgilerini giriniz:*****" << endl;
					grafik();
					cout << "Eklemek istediginiz yemek cesidini giriniz:" << endl;
					cin >> yemek_cesidi;
					y_c_ekle << yemek_cesidi << "\n";
					grafik();
					cout << "Yemek icin gerekli olan malzemeleri 1 kisilik kullanim miktari ile eksiksiz giriniz:" << endl;
					cin >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
					cout << endl;
					grafik();
					malzeme_ekle << yemek_cesidi << "\t" << yemeklik_malzeme1 << "\t" << yemeklik_malzeme1_kisi << "\t" << yemeklik_malzeme2 << "\t" << yemeklik_malzeme2_kisi << "\t" << yemeklik_malzeme3 << "\t" << yemeklik_malzeme3_kisi << "\t" << yemeklik_malzeme4 << "\t" << yemeklik_malzeme4_kisi << "\n";
					cout << "*****Yemek cesidi guncelleme islemi basariyla tamamlanmistir*****" << endl;
					grafik();
					a = 1;
					continue;
				}
				//diger malzemeler oldugu gibi yazdiriliyor.
				else
				{
					malzeme_ekle << yemek_cesidi << "\t" << yemeklik_malzeme1 << "\t" << yemeklik_malzeme1_kisi << "\t" << yemeklik_malzeme2 << "\t" << yemeklik_malzeme2_kisi << "\t" << yemeklik_malzeme3 << "\t" << yemeklik_malzeme3_kisi << "\t" << yemeklik_malzeme4 << "\t" << yemeklik_malzeme4_kisi << "\n";
				}
			}
		}
		//diger yemek cesitleri oldugu gibi yazdiriliyor.
		else
		{
			y_c_ekle << yemek_cesidi << "\n";
		}
	}
	//a hala 0 ise gerekli mesaj veriliyor.
	if (a == 0)
	{
		grafik();
		cout << "*****ARADIGINIZ ISIMDE BIR YEMEK CESIDI BULUNAMAMISTIR.*****" << endl;
		grafik();
	}
	//yemek cesidi malzeme arama ve ekleme degiskenleri kapatiliyor.
	y_c_arama.close();
	y_c_ekle.close();
	malzeme_arama.close();
	malzeme_ekle.close();
	//malzeme ve yemekcesidi txt dosyalari siliniyor.
	remove("malzeme.txt");
	//malzemegecici malzeme -yemekcesidigecici yemek cesidi txt dosyasina aktariliyor.
	rename("malzeme_gecici.txt" ,"malzeme.txt");
	remove("yemekcesidi.txt");
	rename("yemekcesidi_gecici.txt" ,"yemekcesidi.txt");
}
//yemek cesidi listeleme islemi yapiliyor
void yemek_cesidi_listeleme()
{
	grafik();
	cout << "*****YEMEK CESIDI LISTELEME*****" << endl;
	grafik();
	//yemek cesidi okumak icin gerekli degisken tanimlaniyor.
	ifstream y_c_listeleme;
	//yemek cesidi dosyasi aciliyor.
	y_c_listeleme.open("yemekcesidi.txt", ios::app);
	while (!y_c_listeleme.eof())
	{
		//yemek cesitleri satir satir okunuyor
		y_c_listeleme >> yemek_cesidi;
		//satir sonuna gelince bir alt satira inip devam ediyor.
		if (yemek_cesidi == " ")
			continue;
		//yemek cesidi okuma bitince komple dongu disina cikar
		else if (y_c_listeleme.eof())
			break;
		//okudugu yemek cesitlerini yazmaya devam ediyor
		else
			cout << yemek_cesidi << "\n";
	}
}
//menuye yemek cesidi belirleme islemi yapilir.
void menuye_yemek_cesidi_belirleme()
{
	grafik();
	cout << "*****MENUYE YEMEK CESIDI BELIRLEME*****" << endl;
	grafik();
	//bir gunluk cikarilacak menu porsiyonlari teker teker tanimlaniyor
	int corba_menu_porsiyon;
	int ara_yemek_menu_porsiyon;
	int ana_yemek_menu_porsiyon;
	int tatli_menu_porsiyon;
	int icecek_menu_porsiyon;
	//gunluk menu porsiyonlari teker teker giriliyor.
	grafik();
	cout << "MENUDE CORBA KAC PORSİYON OLSUN?" << endl;
	cin >> corba_menu_porsiyon;
	grafik();
	cout << "MENUDE ARA YEMEK KAC PORSİYON OLSUN?" << endl;
	cin >> ara_yemek_menu_porsiyon;
	grafik();
	cout << "MENUDE ANA YEMEK KAC PORSİYON OLSUN?" << endl;
	cin >> ana_yemek_menu_porsiyon;
	grafik();
	cout << "MENUDE TATLI KAC PORSİYON OLSUN?" << endl;
	cin >> tatli_menu_porsiyon;
	grafik();
	cout << "MENUDE ICECEK KAC PORSİYON OLSUN?" << endl;
	cin >> icecek_menu_porsiyon;
	grafik();
	//gunluk cikarilacak yemek menusu giriliyor.
	cout << "Menuye eklemek istediginiz yemek cesidinin adlarini sirasiyla giriniz:(Corba-Ara Yemek-Ana Yemek-Tatlı-Icecek)" << endl;
	cin >> yemek_menusu1 >> yemek_menusu2 >> yemek_menusu3 >> yemek_menusu4>> yemek_menusu5;
	//yemek cesidi arama ve belirlenen yemek cesitlerini eklemek icin gerekli degiskenler tanimlaniyor.
	ifstream y_c_arama;
	ofstream yc_list_ekle;
	//gunlıuk satilan menudeki yemekler icin porsiyon sayisi isteniyor.
	int corba_porsiyon;
	int ara_yemek_porsiyon;
	int ana_yemek_porsiyon;
	int tatli_porsiyon;
	int icecek_porsiyon;
	//gunluk cikarilan yemek icin toplam alis fiyatlari hesaplaniyor.
	float yemek1_fiyat_alis = 0;
	float yemek2_fiyat_alis = 0;
	float yemek3_fiyat_alis = 0;
	float yemek4_fiyat_alis = 0;
	float yemek5_fiyat_alis = 0;
	//gunluk cikarilan yemek icin toplam satis fiyatlari hesaplaniyor.
	float yemek1_fiyat_satis = 0;
	float yemek2_fiyat_satis = 0;
	float yemek3_fiyat_satis = 0;
	float yemek4_fiyat_satis = 0;
	float yemek5_fiyat_satis = 0;
	int sayi = 0;
	yc_list_ekle.open("yemekcesidibelirleme.txt", ios::app);
	//b degiskeninin sifir ya da 1 olmasina karsilik gerekli mesajlar veriliyor.
	int b = 0;
	while (( b==0))
	{
		y_c_arama.open("yemekcesidi.txt", ios::app);
		while (!y_c_arama.eof())
		{
			y_c_arama >> yemek_cesidi;
			//yemek cesidi bulununca yemek cesidi belirleme dosyasina ekleniyor.//diger kalan menu yemekleri icin hep ayni sey yapiliyor.
			if (yemek_cesidi == yemek_menusu1)
			{
				b = 1;
				yc_list_ekle << yemek_menusu1 << "\t";
				break;
			}
		}
		y_c_arama.close();
		//ilgili yemek cesidi bulunamayinca tekrar girilmesi isteniyor//diger kalan menu yemekleri icin hep ayni sey yapiliyor.
		if (b == 0)
		{
			grafik();
			cout << "*corba cesidini tekrar giriniz:" << endl;
			cin >> yemek_menusu1;
			grafik();
			b = 0;			
		}
	}
	int d = 0;
	while (( d == 0))
	{
		y_c_arama.open("yemekcesidi.txt", ios::app);
		while (!y_c_arama.eof())
		{
			y_c_arama >> yemek_cesidi;
			if (yemek_cesidi == yemek_menusu2)
			{
				d = 1;
				yc_list_ekle << "\t" << yemek_menusu2 << "\t";
				break;
			}
		}
		y_c_arama.close();
		if (d == 0)
		{
			grafik();
			cout << "*ara yemek cesidini tekrar giriniz:" << endl;
			cin >> yemek_menusu2;
			grafik();
			d = 0;
		}
	}
	int i = 0;
	while (( i == 0))
	{
		y_c_arama.open("yemekcesidi.txt", ios::app);
		while (!y_c_arama.eof())
		{
			y_c_arama >> yemek_cesidi;
			if (yemek_cesidi == yemek_menusu3)
			{
				i = 1;
				yc_list_ekle << "\t" << yemek_menusu3 << "\t";
				break;
			}
		}
		y_c_arama.close();
		if (i == 0)
		{
			grafik();
			cout << "*ana yemek cesidini tekrar giriniz:" << endl;
			cin >> yemek_menusu3;
			grafik();
			i = 0;
		}
	}
	int a = 0;
	while ((a == 0 ))
	{
		y_c_arama.open("yemekcesidi.txt", ios::app);
		while (!y_c_arama.eof())
		{
			y_c_arama >> yemek_cesidi;
			if (yemek_cesidi == yemek_menusu4)
			{
				a = 1;
				yc_list_ekle << "\t" << yemek_menusu4 << "\t";
				break;
			}
		}
		y_c_arama.close();
		if (a == 0)
		{
			grafik();
			cout << "*tatli cesidini tekrar giriniz:" << endl;
			cin >> yemek_menusu4;
			grafik();
			a = 0;
		}
	}
	int c = 0;
	while (( c == 0))
	{
		y_c_arama.open("yemekcesidi.txt", ios::app);
		while (!y_c_arama.eof())
		{
			y_c_arama >> yemek_cesidi;
			if (yemek_cesidi == yemek_menusu5)
			{
				c = 1;
				yc_list_ekle << "\t" << yemek_menusu5 << "\n";
				break;
			}
		}
		y_c_arama.close();
		if (c == 0)
		{
			grafik();
			cout << "*icecek cesidini tekrar giriniz:" << endl;
			cin >> yemek_menusu5;
			grafik();
			c = 0;
		}
	}
	yc_list_ekle.close();
	cout << endl << endl;
	while (sayi == 0)
	{
		grafik();
		//satilan porsiyon sayisi isteniyor ve gunluk cikarilan porsiyona gore kontrol ediliyor.//diger menu yemekleri icin hep ayni sey yapiliyor.
		cout << "Kac porsiyon corba sattın?" << endl;
		cin >> corba_porsiyon;
		if (corba_menu_porsiyon >= corba_porsiyon)
		{
			sayi = 1;
			break;
		}
		//fazla yada baska birsey girlince hata veriyor ve tekrar girilmesi isteniyor.//diger menu yemekleri icin hep ayni sey yapiliyor.
		else
		{
			grafik();
			cout << "Lutfen tekrar giriniz?" << endl;
			grafik();
			sayi = 0;
		}
	}
	sayi = 0;
	while (sayi == 0)
	{
		grafik();
		cout << "Kac porsiyon ara yemek sattın?" << endl;
		cin >> ara_yemek_porsiyon;
		if (ara_yemek_menu_porsiyon >= ara_yemek_porsiyon)
		{
			sayi = 1;
			break;
		}
		else
		{
			grafik();
			cout << "Lutfen tekrar giriniz?" << endl;
			grafik();
			sayi = 0;
		}
	}
	sayi = 0;
	while (sayi == 0)
	{
		grafik();
		cout << "Kac porsiyon ana yemek sattın?" << endl;
		cin >> ana_yemek_porsiyon;
		if (ana_yemek_menu_porsiyon >= ana_yemek_porsiyon)
		{
			sayi = 1;
			break;
		}
		else
		{
			grafik();
			cout << "Lutfen tekrar giriniz?" << endl;
			grafik();
			sayi = 0;
		}
	}
	sayi = 0;
	while (sayi == 0)
	{
		grafik();
		cout << "Kac porsiyon tatlı sattın?" << endl;
		cin >> tatli_porsiyon;
		if (tatli_menu_porsiyon >= tatli_porsiyon)
		{
			sayi = 1;
			break;
		}
		else
		{
			grafik();
			cout << "Lutfen tekrar giriniz?" << endl;
			grafik();
			sayi = 0;
		}
	}
	sayi = 0;
	while (sayi == 0)
	{
		grafik();
		cout << "Kac porsiyon icecek sattın?" << endl;
		cin >> icecek_porsiyon;
		if (icecek_menu_porsiyon >= icecek_porsiyon)
		{
			sayi = 1;
			break;
		}
		else
		{
			grafik();
			cout << "Lutfen tekrar giriniz?" << endl;
			grafik();
			sayi = 0;
		}
	}
	grafik();
	cout << "*****DEPO KONTROL ETME*****" << endl;
	grafik();
	//malzeme ve urun arama degiskenleri tanimlaniyor.
	ifstream malzeme_arama;
	ifstream urun_arama;
	//malzeme ve urun dosyalari aciliyor.
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	//siparis listesi eklemek icin degisken tanimlaniyor.
	ofstream siparis_list_ekle;
	//siparis listesi dosyasi aciliyor.
	siparis_list_ekle.open("siparislistesi.txt", ios::app);
	//gerekli degiskenler tanimlaniyor ve ilgili degere gore hata mesaji veya gerekli islemler yapiliyor//geri kalan yemekler ve malzemeler icin de hep ayni islem yapiliyor.
	int u = 0;
	int h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu1)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme1)
				{
					//menudeki 1. yemek icin toplm alis ve satis fiyatlari hesaplaniyor.//geri kalan yemekler ve malzemeler icin de hep ayni islem yapiliyor.
					yemek1_fiyat_alis = yemek1_fiyat_alis + alis_fiyati * corba_porsiyon;
					yemek1_fiyat_satis = yemek1_fiyat_satis + satis_fiyati * corba_porsiyon;
					//stok kilo ile gerekli olan malzeme karsilastiriliyor.//geri kalan yemekler ve malzemeler icin de hep ayni islem yapiliyor.
					if (yemeklik_malzeme1_kisi * corba_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	//ilgili  duruma gore ilgili hata mesaji verdiriliyor.//geri kalan yemekler ve malzemeler icin de hep ayni islem yapiliyor.
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme1 << " urununden " << "\t" << yemeklik_malzeme1_kisi * corba_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme1 << " urununden " << "\t" << yemeklik_malzeme1_kisi * corba_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}
	//acilan dosyalar kapatilip tekrardan yeni olarak aciliyor.//geri kalan yemekler ve malzemeler icin de hep ayni islem yapiliyor.
	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	u = 0; 
	h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu1)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme2)
				{
					yemek1_fiyat_alis = yemek1_fiyat_alis + alis_fiyati * corba_porsiyon;
					yemek1_fiyat_satis = yemek1_fiyat_satis + satis_fiyati * corba_porsiyon;
					if (yemeklik_malzeme2_kisi * corba_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme2 << " urununden " << "\t" << yemeklik_malzeme2_kisi * corba_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme2 << " urununden " << "\t" << yemeklik_malzeme2_kisi * corba_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}
	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	u = 0;
	h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu1)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme3)
				{
					yemek1_fiyat_alis = yemek1_fiyat_alis + alis_fiyati * corba_porsiyon;
					yemek1_fiyat_satis = yemek1_fiyat_satis + satis_fiyati * corba_porsiyon;
					if (yemeklik_malzeme3_kisi * corba_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme3 << " urununden " << "\t" << yemeklik_malzeme3_kisi * corba_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme3 << " urununden " << "\t" << yemeklik_malzeme3_kisi * corba_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}
	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	u = 0;
	h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu1)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme4)
				{
					yemek1_fiyat_alis = yemek1_fiyat_alis + alis_fiyati * corba_porsiyon;
					yemek1_fiyat_satis = yemek1_fiyat_satis + satis_fiyati * corba_porsiyon;
					if (yemeklik_malzeme4_kisi * corba_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme4 << " urununden " << "\t" << yemeklik_malzeme4_kisi * corba_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme4 << " urununden " << "\t" << yemeklik_malzeme4_kisi * corba_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}
	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	u = 0;
	h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu2)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme1)
				{
					yemek2_fiyat_alis = yemek2_fiyat_alis + alis_fiyati * ara_yemek_porsiyon;
					yemek2_fiyat_satis = yemek2_fiyat_satis + satis_fiyati * ara_yemek_porsiyon;
					if (yemeklik_malzeme1_kisi * ara_yemek_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme1 << " urununden " << "\t" << yemeklik_malzeme1_kisi * ara_yemek_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme1 << " urununden " << "\t" << yemeklik_malzeme1_kisi * ara_yemek_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}
	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	u = 0;
	h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu2)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme2)
				{
					yemek2_fiyat_alis = yemek2_fiyat_alis + alis_fiyati * ara_yemek_porsiyon;
					yemek2_fiyat_satis = yemek2_fiyat_satis + satis_fiyati * ara_yemek_porsiyon;
					if (yemeklik_malzeme2_kisi * ara_yemek_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme2 << " urununden " << "\t" << yemeklik_malzeme2_kisi * ara_yemek_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme2 << " urununden " << "\t" << yemeklik_malzeme2_kisi * ara_yemek_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}

	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	u = 0;
	h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu2)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme3)
				{
					yemek2_fiyat_alis = yemek2_fiyat_alis + alis_fiyati * ara_yemek_porsiyon;
					yemek2_fiyat_satis = yemek2_fiyat_satis + satis_fiyati * ara_yemek_porsiyon;
					if (yemeklik_malzeme3_kisi * ara_yemek_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme3 << " urununden " << "\t" << yemeklik_malzeme3_kisi * ara_yemek_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme3 << " urununden " << "\t" << yemeklik_malzeme3_kisi * ara_yemek_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}

	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	u = 0;
	h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu2)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme4)
				{
					yemek2_fiyat_alis = yemek2_fiyat_alis + alis_fiyati * ara_yemek_porsiyon;
					yemek2_fiyat_satis = yemek2_fiyat_satis + satis_fiyati * ara_yemek_porsiyon;
					if (yemeklik_malzeme4_kisi * ara_yemek_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme4 << " urununden " << "\t" << yemeklik_malzeme4_kisi * ara_yemek_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme4 << " urununden " << "\t" << yemeklik_malzeme4_kisi * ara_yemek_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}

	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	u = 0;
	h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu3)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme1)
				{
					yemek3_fiyat_alis = yemek3_fiyat_alis + alis_fiyati * ana_yemek_porsiyon;
					yemek3_fiyat_satis = yemek3_fiyat_satis + satis_fiyati * ana_yemek_porsiyon;
					if (yemeklik_malzeme1_kisi * ana_yemek_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme1 << " urununden " << "\t" << yemeklik_malzeme1_kisi * ana_yemek_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme1 << " urununden " << "\t" << yemeklik_malzeme1_kisi * ana_yemek_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}
	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	u = 0;
	h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu3)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme2)
				{
					yemek3_fiyat_alis = yemek3_fiyat_alis + alis_fiyati * ana_yemek_porsiyon;
					yemek3_fiyat_satis = yemek3_fiyat_satis + satis_fiyati * ana_yemek_porsiyon;
					if (yemeklik_malzeme2_kisi * ana_yemek_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme2 << " urununden " << "\t" << yemeklik_malzeme2_kisi * ana_yemek_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme2 << " urununden " << "\t" << yemeklik_malzeme2_kisi * ana_yemek_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}

	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	u = 0;
	h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu3)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme3)
				{
					yemek3_fiyat_alis = yemek3_fiyat_alis + alis_fiyati * ana_yemek_porsiyon;
					yemek3_fiyat_satis = yemek3_fiyat_satis + satis_fiyati * ana_yemek_porsiyon;
					if (yemeklik_malzeme3_kisi * ana_yemek_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme3 << " urununden " << "\t" << yemeklik_malzeme3_kisi * ana_yemek_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme3 << " urununden " << "\t" << yemeklik_malzeme3_kisi * ana_yemek_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}

	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	u = 0;
	h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu3)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme4)
				{
					yemek3_fiyat_alis = yemek3_fiyat_alis + alis_fiyati * ana_yemek_porsiyon;
					yemek3_fiyat_satis = yemek3_fiyat_satis + satis_fiyati * ana_yemek_porsiyon;
					if (yemeklik_malzeme4_kisi * ana_yemek_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme4 << " urununden " << "\t" << yemeklik_malzeme4_kisi * ana_yemek_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme4 << " urununden " << "\t" << yemeklik_malzeme4_kisi * ana_yemek_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}

	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	u = 0;
	h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu4)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme1)
				{
					yemek4_fiyat_alis = yemek4_fiyat_alis + alis_fiyati * tatli_porsiyon;
					yemek4_fiyat_satis = yemek4_fiyat_satis + satis_fiyati * tatli_porsiyon;
					if (yemeklik_malzeme1_kisi * tatli_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme1 << " urununden " << "\t" << yemeklik_malzeme1_kisi * tatli_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme1 << " urununden " << "\t" << yemeklik_malzeme1_kisi * tatli_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}
	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	u = 0;
	h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu4)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme2)
				{
					yemek4_fiyat_alis = yemek4_fiyat_alis + alis_fiyati * tatli_porsiyon;
					yemek4_fiyat_satis = yemek4_fiyat_satis + satis_fiyati * tatli_porsiyon;
					if (yemeklik_malzeme2_kisi * tatli_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme2 << " urununden " << "\t" << yemeklik_malzeme2_kisi * tatli_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme2 << " urununden " << "\t" << yemeklik_malzeme2_kisi * tatli_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}

	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	u = 0;
	h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu4)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme3)
				{
					yemek4_fiyat_alis = yemek4_fiyat_alis + alis_fiyati * tatli_porsiyon;
					yemek4_fiyat_satis = yemek4_fiyat_satis + satis_fiyati * tatli_porsiyon;
					if (yemeklik_malzeme3_kisi * tatli_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme3 << " urununden " << "\t" << yemeklik_malzeme3_kisi * tatli_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme3 << " urununden " << "\t" << yemeklik_malzeme3_kisi * tatli_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}

	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	u = 0;
	h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu4)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme4)
				{
					yemek4_fiyat_alis = yemek4_fiyat_alis + alis_fiyati * tatli_porsiyon;
					yemek4_fiyat_satis = yemek4_fiyat_satis + satis_fiyati * tatli_porsiyon;
					if (yemeklik_malzeme4_kisi * tatli_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme4 << " urununden " << "\t" << yemeklik_malzeme4_kisi * tatli_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme4 << " urununden " << "\t" << yemeklik_malzeme4_kisi * tatli_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}

	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	u = 0;
	h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu5)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme1)
				{
					yemek5_fiyat_alis = yemek5_fiyat_alis + alis_fiyati * icecek_porsiyon;
					yemek5_fiyat_satis = yemek5_fiyat_satis + satis_fiyati * icecek_porsiyon;
					if (yemeklik_malzeme1_kisi * icecek_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme1 << " urununden " << "\t" << yemeklik_malzeme1_kisi * icecek_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme1 << " urununden " << "\t" << yemeklik_malzeme1_kisi * icecek_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}
	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	u = 0;
	h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu5)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme2)
				{
					yemek5_fiyat_alis = yemek5_fiyat_alis + alis_fiyati * icecek_porsiyon;
					yemek5_fiyat_satis = yemek5_fiyat_satis + satis_fiyati * icecek_porsiyon;
					if (yemeklik_malzeme2_kisi * icecek_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme2 << " urununden " << "\t" << yemeklik_malzeme2_kisi * icecek_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme2 << " urununden " << "\t" << yemeklik_malzeme2_kisi * icecek_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}

	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	u = 0;
	h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu5)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme3)
				{
					yemek5_fiyat_alis = yemek5_fiyat_alis + alis_fiyati * icecek_porsiyon;
					yemek5_fiyat_satis = yemek5_fiyat_satis + satis_fiyati * icecek_porsiyon;
					if (yemeklik_malzeme3_kisi * icecek_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme3 << " urununden " << "\t" << yemeklik_malzeme3_kisi * icecek_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme3 << " urununden " << "\t" << yemeklik_malzeme3_kisi * icecek_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}

	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	u = 0;
	h = 0;
	while (!malzeme_arama.eof())
	{
		malzeme_arama >> yemek_cesidi >> yemeklik_malzeme1 >> yemeklik_malzeme1_kisi >> yemeklik_malzeme2 >> yemeklik_malzeme2_kisi >> yemeklik_malzeme3 >> yemeklik_malzeme3_kisi >> yemeklik_malzeme4 >> yemeklik_malzeme4_kisi;
		if (yemek_cesidi == yemek_menusu5)
		{
			while (!urun_arama.eof())
			{
				urun_arama >> urun_adi >> uretim_tarihi >> tuketim_tarihi >> kalori_gram >> stok_adet_kilo >> alis_fiyati >> satis_fiyati;
				if (urun_adi == yemeklik_malzeme4)
				{
					yemek5_fiyat_alis = yemek5_fiyat_alis + alis_fiyati * icecek_porsiyon;
					yemek5_fiyat_satis = yemek5_fiyat_satis + satis_fiyati * icecek_porsiyon;
					if (yemeklik_malzeme4_kisi * icecek_menu_porsiyon == stok_adet_kilo)
					{
						u = 1;
						break;
					}
					h = 1;
					break;
				}
			}
		}
	}
	if (u == 0)
	{
		siparis_list_ekle << yemeklik_malzeme4 << " urununden " << "\t" << yemeklik_malzeme4_kisi * icecek_menu_porsiyon - stok_adet_kilo << " kilo temin edilmelidir." << "\n";
	}
	if (h == 0)
	{
		siparis_list_ekle << yemeklik_malzeme4 << " urununden " << "\t" << yemeklik_malzeme4_kisi * icecek_menu_porsiyon << " kilo temin edilmelidir." << "\n";
	}
	malzeme_arama.close();
	urun_arama.close();
	malzeme_arama.open("malzeme.txt", ios::app);
	urun_arama.open("depo.txt", ios::app);
	//en son elde edilen kar-kalan yemek-kisi basi ve toplam maliyet her bir yemek icin ayri ayri yazdiriliyor.
	grafik();
	cout << "*****LUTFEN SIPARIS LISTESINDEKI EKSIKLERI TAMAMLAYINIZ.*****" << endl;
	grafik();
	cout << endl << endl;
	grafik();
	cout << "*****CORBADAN ELDE ETTIGIMIZ TOPLAM KAR:" << yemek1_fiyat_satis - yemek1_fiyat_alis << endl;
	grafik();
	cout << "*****CORBANIN KISI BASI MALİYETİ*****" << yemek1_fiyat_alis/corba_menu_porsiyon << endl;
	grafik();
	cout << "*****CORBANIN TOPLAM MALIYETI*****" << yemek1_fiyat_alis << endl;
	grafik();
	cout << "ELIMIZDE KALAN CORBA PORSIYON SAYISI:" << corba_menu_porsiyon - corba_porsiyon << endl;
	grafik();
	cout << "*****ARA YEMEKTEN ELDE ETTIGIMIZ TOPLAM KAR:" << yemek2_fiyat_satis - yemek2_fiyat_alis << endl;
	grafik();
	cout << "*****ARA YEMEGIN KISI BASI MALİYETİ*****" << yemek2_fiyat_alis / ara_yemek_menu_porsiyon << endl;
	grafik();
	cout << "*****ARA YEMEGIN TOPLAM MALIYETI" << yemek2_fiyat_alis << endl;
	grafik();
	cout << "ELIMIZDE KALAN ARA YEMEK PORSIYON SAYISI:" << ara_yemek_menu_porsiyon - ara_yemek_porsiyon << endl;
	grafik();	
	cout << "*****ANA YEMEKTEN ELDE ETTIGIMIZ TOPLAM KAR:" << yemek3_fiyat_satis - yemek3_fiyat_alis << endl;
	grafik();
	cout << "*****ANA YEMEGIN KISI BASI MALIYETI*****" << yemek3_fiyat_alis / ana_yemek_menu_porsiyon << endl;
	grafik();
	cout << "*****ANA YEMEGIN TOPLAM MALIYETI*****" << yemek3_fiyat_alis << endl;
	grafik();
	cout << "ELIMIZDE KALAN ANA YEMEK PORSIYON SAYISI:" << ana_yemek_menu_porsiyon - ana_yemek_porsiyon << endl;
	grafik();
	cout << "*****TATLI ELDE ETTIGIMIZ TOPLAM KAR:" << yemek4_fiyat_satis - yemek4_fiyat_alis << endl;
	grafik();
	cout << "*****TATLININ KISI BASI MALIYETI*****" << yemek4_fiyat_alis / tatli_menu_porsiyon << endl;
	grafik();
	cout << "*****TATLININ TOPLAM MALIYETI*****" << yemek4_fiyat_alis << endl;
	grafik();
	cout << "ELIMIZDE KALAN TATLI PORSIYON SAYISI:" << tatli_menu_porsiyon - tatli_porsiyon << endl;
	grafik();
	cout << "*****ICECEKDEN ELDE ETTIGIMIZ TOPLAM KAR:" << yemek5_fiyat_satis - yemek5_fiyat_alis << endl;
	grafik();
	cout << "*****ICECEK KISI BASI MALIYETI*****" << yemek5_fiyat_alis / icecek_menu_porsiyon << endl;
	grafik();
	cout << "*****ICECEK TOPLAM MALIYETI*****" << yemek5_fiyat_alis << endl;
	grafik();
	cout << "ELIMIZDE KALAN ICECEK PORSIYON SAYISI:" << icecek_menu_porsiyon - icecek_porsiyon << endl;
	grafik();
	cout << "*****RAPOR ISLEMI BASARIYLA TAMAMLANMISTIR*****" << endl;
	grafik();
}
int main()
{
	//devam etme istegine gore devam ediliyor ya da edilmiyor.
	while (menu_secimi == 'e' || menu_secimi == 'E')
	{
		//seilen isleme gore ilgili yapiya gidip ilgili islemi gerceklestiriyor.
		giris_islemi_menusu();
		switch(giris_islemi)
		{
		case'1':
			//ilgili isleme gore gidilipi ilgili islem gerceklestiriliyor.
			urun_islemi_menusu();
			switch (urun_islemi)
			{
			case'1':
				//islem yapildiktan sonra komple dongunun en disina cikiyor.
				urun_ekleme();
				grafik();
				break;
			case'2':
				urun_silme();
				grafik();
				break;
			case'3':
				urun_arama();
				grafik();
				break;
			case'4':
				urun_guncelleme();
				grafik();
				break;
			case'5':
				urun_listeleme();
				grafik();
				break;
				//ilgili secenek yoksa hata veriyor
			default:
				grafik();
				cout << "*****HATA!!!*****" << endl;
				grafik();
				break;
			}
			break;
		case'2':
			yemek_cesidi_islemi_menusu();
			switch (yemek_cesidi_islemi)
			{
			case'1':
				yemek_cesidi_ekleme();
				grafik();
				break;
			case'2':
				yemek_cesidi_silme();
				grafik();
				break;
			case'3':
				yemek_cesidi_arama();
				grafik();
				break;
			case'4':
				yemek_cesidi_guncelleme();
				grafik();
				break;
			case'5':
				yemek_cesidi_listeleme();
				grafik();
				break;
			default:
				grafik();
				cout << "*****HATA!!!*****" << endl;
				grafik();
			}
			break;
		case'3':
			menuye_yemek_cesidi_belirleme();
			grafik();
			break;
			//ilgili secenek yoksa hata veriyor
		default:
			grafik();
			cout << "*****HATA!!!*****" << endl;
			grafik();
		}
		//baska islem yapma istegine gore devam ediyor ya da bitiriyor.
		grafik();
		cout << "***Baska bir islem yapmak ister misiniz?(e-E/h-H)***" << endl;
		cin >> menu_secimi;
		grafik();
	}
	grafik();
	cout << "KALITE ASLA TESADUF DEGILDIR." << endl;
	grafik();
}