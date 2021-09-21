/*
Nama : Salsabila Karin
NPM : 140810190015
Kelas : A
*/

#include<iostream>
#include<string.h>
#include <climits>
#include <conio.h>
using namespace std;
int mod(int a,int b){
   if(a>0)
   return a%b;
   else{
   while(a<0){
      a+=b;
   }
   return a%b;
   } 
}
int main(){
 int key,length,x;
 string plainText;
 char repeat;
 string encryptedText,decryptedText;
 
 do{       
      plainText="";     //Menghapus isi plain teks sebelumnya
      encryptedText=""; //Menghapus isi cipher teks sebelumnya
      decryptedText=""; //Menghapus isi deskripsi teks sebelumnya
      cout<<"Plain Teks :";
      getline(cin,plainText,'\n'); //input plain teks -> untuk input manual, jadikan atau remove comment sesuai keinginan
      length = plainText.length(); //menghitung jumlah char pada plainteks untuk hitungan looping
      system("cls");
      cout<<"Teks adalah : "<<plainText<<endl; //Mengoutput plain teks agar kita tahu plain teks yang terinput
      cout << "Kunci : ";
      cin >> key; //input kunci
      while (cin.fail()) //error handling jika input kunci bukanlah angka
      {
         cin.clear(); // membersihkan buffer input agar bisa mengulang input
         cin.ignore(INT_MAX, '\n'); // mengabaikan input sebelumnya
         cout << "Hanya bisa input angka\n";
         cout << "Kunci : ";
         cin >> key; 
      }
      key = mod(key,26);
      cout<<"1 Encrypt, 2 Decrypt\n";
      cin>>x;
      switch(x){
         case 1 :
            //ENKRIPSI
            for(int i = 0; i <= length; ++i) {      
            if (islower(plainText[i]))  //enkripsi huruf kecil
                  encryptedText += mod((plainText[i]-'a'+ key),26)+'a';       
               else if (isupper(plainText[i]))  //enkripsi huruf kapital
                  encryptedText += mod((plainText[i]-'A'+ key),26)+'A';
               else
                  encryptedText += plainText[i];
            }
            //OUTPUT ENKRIPSI
            cout<<"\nHasil enkripsi: "<<encryptedText<<"\n";
            cout<<"Angka enkripsi : ";// mengoutput angka dari huruf
            for(int i = 0; i <= length; ++i) {
            if(islower(encryptedText[i]))
                  cout<< int(encryptedText[i]-97)<<" ";
               else if(isupper(encryptedText[i])) 
               cout<< int(encryptedText[i]-65)<<" ";
               else
                  cout<<" | " ;
            }
         break;
         case 2:
            //DESKRIPSI
            encryptedText = plainText;
            for(int i = 0; i <= length; ++i) {
            if(islower(encryptedText[i]))//deskripsi huruf kecil
                  decryptedText += mod((encryptedText[i]-'a'- key),26)+'a';
               else if(isupper(encryptedText[i]))//deskripsi huruf kapital
                  decryptedText += mod((encryptedText[i]-'A'- key),26)+'A';
               else
                  decryptedText += encryptedText[i];  
            }
            //OUTPUT DESKRIPSI
            cout << "\n\nHasil deskripsi: " << decryptedText<<"\n";
            cout<<"Angka deskripsi : ";// mengoutput angka dari huruf
            for(int i = 0; i < length; ++i) {
               if(islower(decryptedText[i]))
                  cout<< int(decryptedText[i]-97)<<" ";
               else if(isupper(decryptedText[i]))
               cout<< int(decryptedText[i]-65)<<" ";
               else
                  cout<<" | " ;
            } 
         break;
      }
      cout<<"\nUlangi program ? (Y/N) : ";
      cin>>repeat;
      cin.ignore(); //membersihkan cin agar bisa input ulang plainteks
   }while(repeat == 'y'|| repeat == 'Y');
}