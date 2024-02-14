#include <iostream>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <stdio.h>
# include <time.h>  
#include <stdlib.h>  
#include <cstdio>
#include <string>

using namespace std;
void MusteriEkle();
void MusteriListeleme();
void MusteriArama();
void MusteriSilme();
void MusteriDuzeltme();

struct Musteri
{
char adi [90];
char soyadi[90];
char yas[3];
char cinsiyet;
char plaka;
int oda_no;
char tc [11];
int gun;
int fiyat;
};
  	Musteri must; 
int main()
{
	srand(time(0));
	setlocale (	LC_ALL, "Turkish");
	char secim;
	string mus_adi;
	string mus_soyadi;
	int yas;
char cinsiyet;

  
	do 
	{
		system ("color 70" );
      system("cls");
	setlocale (	LC_ALL, "Turkish");
	cout << "*****SAYIN MÜÞTERÝMÝZ ÝLÝ OTOPARK SÝSTEMÝNE HOÞGELDÝNÝZ**** "<<endl;
	
	cout <<"*****YAPABÝLECEÐÝNÝZ ÝÞLEMLER*****\n [1] =Müþteri Kayýt Ekleme \n [2] = Müþteri Kayýt Getirme \n [3] = Müþteri Kayýt Silme";
	cout <<"\n [4] = Müþteri Kayýt Düzeltme \n [5] = Müþteri Kayýt Sorgulama "<<endl;
	cout <<"LÜTFEN YAPACAÐINIZ ÝÞLEMÝ SEÇÝNÝZ"<<endl;
		secim = getche();
		switch (secim)
		{
			case '1': 
			{
			MusteriEkle();
				break;
			}
			case '2':      
			{
				MusteriListeleme();
				break;
			}
			case '3' :
			{
				
				 MusteriSilme();
				break;	
			}
			case '4':
			{
			  MusteriDuzeltme();
				break;
			}
			case '5':
			{  MusteriArama();
				
				break;
			}
		}
          cout << "\nana menüye dönmek ister misiniz (e/h && E/H)"<<endl;
		 secim = getche();
		 
	}
	while(secim == 'e'|| secim == 'E' );
	{
		
	}
	
	 system ("pause");
	return 0 ;
}
void MusteriEkle()
{

	ofstream yaz ("otopark.txt",  ios :: binary | ios::app );
	char secim;
	do 
	{
	cout << "\nadýnýzý giriniz"<<endl;
	cin >> must.adi;
	cout << "soyadýnýzý giriniz"<<endl;	
	cin>> must.soyadi;
	cout << "yaþýnýzý giriniz"<<endl;
	cin >> must.yas;
		cout << "cinsiyetinizi giriniz (E/e) , (K,k)))\n"<<endl;
	 must.cinsiyet = getche();
	 cout << "\nLÜTFEN TC KÝMLÝK NUMARANIZI GÝRÝNÝZ"<<endl;
	 cin>>must.tc;
	 must.oda_no =rand() % (300-1+1 ) + (1);
	 cout << "OTOPARK NUMARANIZ \n0-100 1.KAT\n 100-200 2.KAT \n 200-300 3.KAT\n 300-400 4.KAT \n 400-500 5.KAT \n 500-600 6.KAT"<<must.oda_no<<endl;
	cout <<" OTOPARK NUMARANIZ : " << must.oda_no <<" :: NUMARA OLARAK BELÝRLENMÝÞTÝR KAÇ GÜNLÜÐÜNE ::\n"<<must.oda_no<< "NUMARALI PARK YERÝNÝ KÝRALAMAK ÝSTÝYORSUNUZ ?"<<endl;
	 cin>> must.gun ;
	 must.fiyat = 30*must.gun;
	 cout << "ÖDEMENÝZ GEREKEN FÝYAT : " <<must.fiyat<<endl;
	 yaz.write((char*)&must,sizeof(must));
	 cout << "KAYIT TAMAMLANDI"<<endl;
	 cout << "müþteri eklemek ister misiniz\n"<<endl;
	 secim = getche();

	 
	}
		while(secim == 'e'|| secim == 'E' );
	{	
		yaz.close();
	}

}
void MusteriListeleme()
{
	ifstream oku ("otopark.txt", ios :: binary | ios::app );
	oku.seekg(0,ios::end); // okuma iþaretçisi
	int adet = oku.tellg()/sizeof(must);
	if (adet>0)
	{
		for (int i = 0 ; i<adet; i++)
		{
			oku.seekg(i*sizeof(must));
			oku.read((char*)&must,sizeof(must));
		}
			cout <<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN ADI :"<<must.adi<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN SOYADI :"<<must.soyadi<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN YAÞI :" <<must.yas<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN CÝNSÝYETÝ (E : ERKEK K: KIZ /n) :"<<must.cinsiyet<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRAN MÜÞTERÝNÝN ARAÇ PLAKASI :" << must.plaka<<endl;
			cout << "OTELÝMÝZE REZERVASYON YAPTIRANIN TC KÝMLÝK NUMARASI : "<<must.tc<<endl;
			cout << "ODA NUMARANIZ :\n"<<must.oda_no<<endl;
			cout << "________________________________________"<<endl;	
			
	}
	else 
	cout << "KAYIT BULUNAMADI LÜTFEN REZERVASYON BÝLGÝLERÝNÝZÝ KONTROL EDÝNÝZ"<<endl;
		oku.close();
}
void MusteriArama()
{
	ifstream oku ("otopark.txt",ios :: binary |  ios ::app  );          // ios::binary veri girip siler 
	oku.seekg(0,ios::end);
	int kayit = oku.tellg()/sizeof(must);
	char tc_no [11];
	cout << "LÜTFEN ARATMAK ÝSTEDÝÐÝNÝZ TC KÝMLÝK  NUMARASINI GÝRÝNÝZ"<<endl;
	cin >>tc_no;
	if (kayit>0)
	{
		for (int i = 0 ; i<kayit; i++)
		{
			oku.seekg(i*sizeof(must));
		    oku.read((char*)&must,sizeof(must));
		 // okuma iþaretçisi
		}
				if(strcmp(must.tc,tc_no)==0)// hangi kaydý benden nerden istiyor dersek strcmp kullanýrýz
		{
		cout <<endl;
			cout << "ARAMAK ÝSTEDÝÐÝNÝZ MÜÞTERÝMÝZÝN KAYDI"<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN ADI :"<<must.adi<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN SOYADI :"<<must.soyadi<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN YAÞI :"<<must.yas<<endl;
	        cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN CÝNSÝYETÝ (E : ERKEK K: KIZ /n) :"<<must.cinsiyet<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRAN MÜÞTERÝNÝN ARAÇ PLAKASI :" << must.plaka<<endl;
			cout << "OTELÝMÝZE REZERVASYON YAPTIRANIN TC KÝMLÝK NUMARASI : "<<must.tc<<endl;
			cout << "OTOPARKIMIZA YAPILAN TOPLAM GÜN SAYISI :" <<must.gun <<endl;
			cout << "ÖDEMENÝZ GEREKEN MÝKTAR :"<<must.fiyat<<endl;
			cout << "________________________________________"<<endl;
			oku.close();
		}
		else 
		{
			cout << "ARADIÐINIZ KAYIT BULUNAMADI LÜTFEN BÝLGÝLERÝNÝZÝ KONTROL EDÝNÝZ "<<endl;
		}
		
	}
}
void MusteriSilme()
{
		ifstream oku ("otopark.txt",ios :: binary |  ios ::app  );          // ios::binary veri girip siler 
	oku.seekg(0,ios::end);
	int kayit = oku.tellg()/sizeof(must);
	char tc_no [11];
	cout << "LÜTFEN SÝLMEK  ÝSTEDÝÐÝNÝZ TC KÝMLÝK  NUMARASINI GÝRÝNÝZ"<<endl;
	cin >>tc_no;
	char secim;
	if (kayit>0)
	{
		for (int i = 0 ; i<kayit; i++)
		{
			oku.seekg(i*sizeof(must));
		    oku.read((char*)&must,sizeof(must));
       	}
	}
		else 
		
		{
		  
		  
	     cout << "kayýt bulunamadý"<<endl;
		}
		if(strcmp(must.tc,tc_no)==0)// hangi kaydý benden nerden istiyor dersek strcmp kullanýrýz
		{
		cout <<endl;
			cout << "SÝLÝNECEK  MÜÞTERÝMÝZÝN KAYDI"<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN ADI :"<<must.adi<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN SOYADI :"<<must.soyadi<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN YAÞI :"<<must.yas<<endl;
			 cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN CÝNSÝYETÝ (E : ERKEK K: KIZ /n) :"<<must.cinsiyet<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRAN MÜÞTERÝNÝN ARAÇ PLAKASI :" << must.plaka<<endl;
			cout << "OTELÝMÝZE REZERVASYON YAPTIRANIN TC KÝMLÝK NUMARASI : "<<must.tc<<endl;
			cout << "OTOPARKIMIZA YAPILAN TOPLAM GÜN SAYISI :" <<must.gun <<endl;
			 cout << "ARAÇ PLAKANIZI  : " <<endl;
			cout << "ÖDEMENÝZ GEREKEN MÝKTAR :"<<must.fiyat<<endl;
			cout << "________________________________________"<<endl;
		    cout << "SÝLÝNMESÝNÝ ÝSTEDÝÐÝNÝZ KÝÞÝ BU MU ? (E/e && H/h)";
		    secim = getche();
		    oku.close();
		     if(secim == 'E'|| secim == 'e' )
	          {	
	                      remove("otopark.txt");
	                      rename ("yedek.dat","otopark.txt");
	                 cout << "Kayýt silindi"<<endl;
	          }
	          // YANLIÞLIKLA SÝLME ÝÞLEMÝ YAPAN MÜÞTERÝ YEDEK DOSYA DA TUTULMAKTADIR 
	          else 
	          cout << "yedek dosyamýza alýndý"<<endl;
			   	  Musteri yed;
		  ofstream yedek ("yedek.dat" ,ios::app | ios::binary );
		  strcpy(yed.adi,must.adi);
		  strcpy(yed.soyadi,must.soyadi);
		  strcpy(yed.tc,must.tc);
		  yed.oda_no = must.oda_no;
		  yed.fiyat=must.fiyat;
		  yed.gun = must.gun;
		  yedek.write((char*)&yed,sizeof(yed));
		  yedek.close();  
		}
		}
		
void MusteriDuzeltme()
{
	ifstream oku ("Otopark.txt",ios :: binary |  ios ::app  );          // ios::binary veri girip siler 
	oku.seekg(0,ios::end);
	int kayit = oku.tellg()/sizeof(must);
	char tc_no [11];
	cout << "LÜTFEN DÜZELTMEK  ÝSTEDÝÐÝNÝZ MÜÞTERÝNÝN TC KÝMLÝK  NUMARASINI GÝRÝNÝZ"<<endl;
	cin >>tc_no;
	char secim;
	if (kayit>0)
	{
		for (int i = 0 ; i<kayit; i++)
		{
			oku.seekg(i*sizeof(must));
		    oku.read((char*)&must,sizeof(must));
       	}
	}
		else 
		
		{
		  
		  
	     cout << "kayýt bulunamadý"<<endl;
		}
		if(strcmp(must.tc,tc_no)==0)// hangi kaydý benden nerden istiyor dersek strcmp kullanýrýz
		{
		    cout <<endl;
			cout << "DÜZELTÝLECEK  MÜÞTERÝMÝZÝN KAYDI"<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN ADI :"<<must.adi<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN SOYADI :"<<must.soyadi<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN YAÞI :"<<must.yas<<endl;
			cout << "OTOPARKIMIZA  YAPILAN TOPLAM GÜN SAYISI :" <<must.gun <<endl;
			cout << "OTOPARKIMIZA REZERVAYSON YAPTIRAN MÜÞTERÝNÝN ARAÇ PLAKASI"<<endl;
			cout << "ÖDEMENÝZ GEREKEN MÝKTAR :"<<must.fiyat<<endl;
			cout << "________________________________________"<<endl;
		    cout << "DÜZELTÝLMESÝNÝ ÝSTEDÝÐÝNÝZ KÝÞÝ BU MU ? (E/e && H/h)";
		    secim = getche();
		    oku.close();
		     if(secim == 'E'|| secim == 'e' )
	          {	
	        
	          ofstream yedek ("yedek.dat" ,ios::app | ios::binary );
	                 	cout << "\nadýnýzý giriniz"<<endl;
	                   cin >> must.adi;
	               cout << "soyadýnýzý giriniz"<<endl;	
	                cin>> must.soyadi;
	            cout << "yaþýnýzý giriniz"<<endl;
	            cin >> must.yas;
	          	cout << "cinsiyetinizi giriniz (E/e) , (K,k)))\n"<<endl;
	                 must.cinsiyet = getche();
	            cout << "\nLÜTFEN TC KÝMLÝK NUMARANIZI GÝRÝNÝZ"<<endl;
	                   cin>>must.tc;
	           must.oda_no =rand() % (300-1+1 ) + (1);
	         cout << "ODA NUMARANIZ : "<<must.oda_no<<endl;
	         cout <<" ODA NUMARANIZ " << must.oda_no<<"KAÇ GÜNLÜÐÜNE"<<must.oda_no<< "NUMARALI ODAYI KÝRALAMAK ÝSTÝYORSUNUZ"<<endl;
	        cin>> must.gun ;
	        must.fiyat = 300*must.gun;
	        cout << "ÖDEMENÝZ GEREKEN FÝYAT : " <<must.fiyat<<endl;
	        yedek.write((char*)&must,sizeof(must));
		     yedek.close();  
	        
	       
	          }
	        
	          else 
	          cout << "yedek dosyamýza alýndý"<<endl;
			   	  Musteri yed;
		  ofstream yedek ("yedek.dat" ,ios::app | ios::binary );
		  strcpy(yed.adi,must.adi);
		  strcpy(yed.soyadi,must.soyadi);
		  strcpy(yed.tc,must.tc);
		  yed.oda_no = must.oda_no;
		  yed.fiyat=must.fiyat;
		  yed.gun = must.gun;
		  yedek.write((char*)&yed,sizeof(yed));
		  yedek.close();  
		}
}
	

	

	
	
			
		
	



