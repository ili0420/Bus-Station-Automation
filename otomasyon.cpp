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
	cout << "*****SAYIN M��TER�M�Z �L� OTOPARK S�STEM�NE HO�GELD�N�Z**** "<<endl;
	
	cout <<"*****YAPAB�LECE��N�Z ��LEMLER*****\n [1] =M��teri Kay�t Ekleme \n [2] = M��teri Kay�t Getirme \n [3] = M��teri Kay�t Silme";
	cout <<"\n [4] = M��teri Kay�t D�zeltme \n [5] = M��teri Kay�t Sorgulama "<<endl;
	cout <<"L�TFEN YAPACA�INIZ ��LEM� SE��N�Z"<<endl;
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
          cout << "\nana men�ye d�nmek ister misiniz (e/h && E/H)"<<endl;
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
	cout << "\nad�n�z� giriniz"<<endl;
	cin >> must.adi;
	cout << "soyad�n�z� giriniz"<<endl;	
	cin>> must.soyadi;
	cout << "ya��n�z� giriniz"<<endl;
	cin >> must.yas;
		cout << "cinsiyetinizi giriniz (E/e) , (K,k)))\n"<<endl;
	 must.cinsiyet = getche();
	 cout << "\nL�TFEN TC K�ML�K NUMARANIZI G�R�N�Z"<<endl;
	 cin>>must.tc;
	 must.oda_no =rand() % (300-1+1 ) + (1);
	 cout << "OTOPARK NUMARANIZ \n0-100 1.KAT\n 100-200 2.KAT \n 200-300 3.KAT\n 300-400 4.KAT \n 400-500 5.KAT \n 500-600 6.KAT"<<must.oda_no<<endl;
	cout <<" OTOPARK NUMARANIZ : " << must.oda_no <<" :: NUMARA OLARAK BEL�RLENM��T�R KA� G�NL���NE ::\n"<<must.oda_no<< "NUMARALI PARK YER�N� K�RALAMAK �ST�YORSUNUZ ?"<<endl;
	 cin>> must.gun ;
	 must.fiyat = 30*must.gun;
	 cout << "�DEMEN�Z GEREKEN F�YAT : " <<must.fiyat<<endl;
	 yaz.write((char*)&must,sizeof(must));
	 cout << "KAYIT TAMAMLANDI"<<endl;
	 cout << "m��teri eklemek ister misiniz\n"<<endl;
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
	oku.seekg(0,ios::end); // okuma i�aret�isi
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
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN YA�I :" <<must.yas<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN C�NS�YET� (E : ERKEK K: KIZ /n) :"<<must.cinsiyet<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRAN M��TER�N�N ARA� PLAKASI :" << must.plaka<<endl;
			cout << "OTEL�M�ZE REZERVASYON YAPTIRANIN TC K�ML�K NUMARASI : "<<must.tc<<endl;
			cout << "ODA NUMARANIZ :\n"<<must.oda_no<<endl;
			cout << "________________________________________"<<endl;	
			
	}
	else 
	cout << "KAYIT BULUNAMADI L�TFEN REZERVASYON B�LG�LER�N�Z� KONTROL ED�N�Z"<<endl;
		oku.close();
}
void MusteriArama()
{
	ifstream oku ("otopark.txt",ios :: binary |  ios ::app  );          // ios::binary veri girip siler 
	oku.seekg(0,ios::end);
	int kayit = oku.tellg()/sizeof(must);
	char tc_no [11];
	cout << "L�TFEN ARATMAK �STED���N�Z TC K�ML�K  NUMARASINI G�R�N�Z"<<endl;
	cin >>tc_no;
	if (kayit>0)
	{
		for (int i = 0 ; i<kayit; i++)
		{
			oku.seekg(i*sizeof(must));
		    oku.read((char*)&must,sizeof(must));
		 // okuma i�aret�isi
		}
				if(strcmp(must.tc,tc_no)==0)// hangi kayd� benden nerden istiyor dersek strcmp kullan�r�z
		{
		cout <<endl;
			cout << "ARAMAK �STED���N�Z M��TER�M�Z�N KAYDI"<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN ADI :"<<must.adi<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN SOYADI :"<<must.soyadi<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN YA�I :"<<must.yas<<endl;
	        cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN C�NS�YET� (E : ERKEK K: KIZ /n) :"<<must.cinsiyet<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRAN M��TER�N�N ARA� PLAKASI :" << must.plaka<<endl;
			cout << "OTEL�M�ZE REZERVASYON YAPTIRANIN TC K�ML�K NUMARASI : "<<must.tc<<endl;
			cout << "OTOPARKIMIZA YAPILAN TOPLAM G�N SAYISI :" <<must.gun <<endl;
			cout << "�DEMEN�Z GEREKEN M�KTAR :"<<must.fiyat<<endl;
			cout << "________________________________________"<<endl;
			oku.close();
		}
		else 
		{
			cout << "ARADI�INIZ KAYIT BULUNAMADI L�TFEN B�LG�LER�N�Z� KONTROL ED�N�Z "<<endl;
		}
		
	}
}
void MusteriSilme()
{
		ifstream oku ("otopark.txt",ios :: binary |  ios ::app  );          // ios::binary veri girip siler 
	oku.seekg(0,ios::end);
	int kayit = oku.tellg()/sizeof(must);
	char tc_no [11];
	cout << "L�TFEN S�LMEK  �STED���N�Z TC K�ML�K  NUMARASINI G�R�N�Z"<<endl;
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
		  
		  
	     cout << "kay�t bulunamad�"<<endl;
		}
		if(strcmp(must.tc,tc_no)==0)// hangi kayd� benden nerden istiyor dersek strcmp kullan�r�z
		{
		cout <<endl;
			cout << "S�L�NECEK  M��TER�M�Z�N KAYDI"<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN ADI :"<<must.adi<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN SOYADI :"<<must.soyadi<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN YA�I :"<<must.yas<<endl;
			 cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN C�NS�YET� (E : ERKEK K: KIZ /n) :"<<must.cinsiyet<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRAN M��TER�N�N ARA� PLAKASI :" << must.plaka<<endl;
			cout << "OTEL�M�ZE REZERVASYON YAPTIRANIN TC K�ML�K NUMARASI : "<<must.tc<<endl;
			cout << "OTOPARKIMIZA YAPILAN TOPLAM G�N SAYISI :" <<must.gun <<endl;
			 cout << "ARA� PLAKANIZI  : " <<endl;
			cout << "�DEMEN�Z GEREKEN M�KTAR :"<<must.fiyat<<endl;
			cout << "________________________________________"<<endl;
		    cout << "S�L�NMES�N� �STED���N�Z K��� BU MU ? (E/e && H/h)";
		    secim = getche();
		    oku.close();
		     if(secim == 'E'|| secim == 'e' )
	          {	
	                      remove("otopark.txt");
	                      rename ("yedek.dat","otopark.txt");
	                 cout << "Kay�t silindi"<<endl;
	          }
	          // YANLI�LIKLA S�LME ��LEM� YAPAN M��TER� YEDEK DOSYA DA TUTULMAKTADIR 
	          else 
	          cout << "yedek dosyam�za al�nd�"<<endl;
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
	cout << "L�TFEN D�ZELTMEK  �STED���N�Z M��TER�N�N TC K�ML�K  NUMARASINI G�R�N�Z"<<endl;
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
		  
		  
	     cout << "kay�t bulunamad�"<<endl;
		}
		if(strcmp(must.tc,tc_no)==0)// hangi kayd� benden nerden istiyor dersek strcmp kullan�r�z
		{
		    cout <<endl;
			cout << "D�ZELT�LECEK  M��TER�M�Z�N KAYDI"<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN ADI :"<<must.adi<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN SOYADI :"<<must.soyadi<<endl;
			cout << "OTOPARKIMIZA REZERVASYON YAPTIRANIN YA�I :"<<must.yas<<endl;
			cout << "OTOPARKIMIZA  YAPILAN TOPLAM G�N SAYISI :" <<must.gun <<endl;
			cout << "OTOPARKIMIZA REZERVAYSON YAPTIRAN M��TER�N�N ARA� PLAKASI"<<endl;
			cout << "�DEMEN�Z GEREKEN M�KTAR :"<<must.fiyat<<endl;
			cout << "________________________________________"<<endl;
		    cout << "D�ZELT�LMES�N� �STED���N�Z K��� BU MU ? (E/e && H/h)";
		    secim = getche();
		    oku.close();
		     if(secim == 'E'|| secim == 'e' )
	          {	
	        
	          ofstream yedek ("yedek.dat" ,ios::app | ios::binary );
	                 	cout << "\nad�n�z� giriniz"<<endl;
	                   cin >> must.adi;
	               cout << "soyad�n�z� giriniz"<<endl;	
	                cin>> must.soyadi;
	            cout << "ya��n�z� giriniz"<<endl;
	            cin >> must.yas;
	          	cout << "cinsiyetinizi giriniz (E/e) , (K,k)))\n"<<endl;
	                 must.cinsiyet = getche();
	            cout << "\nL�TFEN TC K�ML�K NUMARANIZI G�R�N�Z"<<endl;
	                   cin>>must.tc;
	           must.oda_no =rand() % (300-1+1 ) + (1);
	         cout << "ODA NUMARANIZ : "<<must.oda_no<<endl;
	         cout <<" ODA NUMARANIZ " << must.oda_no<<"KA� G�NL���NE"<<must.oda_no<< "NUMARALI ODAYI K�RALAMAK �ST�YORSUNUZ"<<endl;
	        cin>> must.gun ;
	        must.fiyat = 300*must.gun;
	        cout << "�DEMEN�Z GEREKEN F�YAT : " <<must.fiyat<<endl;
	        yedek.write((char*)&must,sizeof(must));
		     yedek.close();  
	        
	       
	          }
	        
	          else 
	          cout << "yedek dosyam�za al�nd�"<<endl;
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
	

	

	
	
			
		
	



