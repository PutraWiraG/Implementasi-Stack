#include<iostream>

using namespace std;

struct dataMahasiswa{
  string nama;
  int umur;

  // pointer
  dataMahasiswa *prev;
  dataMahasiswa *next;
};

dataMahasiswa *head, *tail, *cur, *newNode, *del;
int maksData = 5;

// Create Data Mahasiswa
void createData(string nama, int umur){
  head = new dataMahasiswa();
  head->nama = nama;
  head->umur = umur;
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

// Count Data Mahasiswa
int countData()
{
  if( head == NULL ){
    return 0;
  }else{
    int banyak = 0;
    cur = head;
    while( cur != NULL ){
      cur = cur->next;
      banyak++;
    }
    return banyak;
  }
}

// Check Full Data
bool isFullData()
{
  if( countData() == maksData ){
    return true;
  }else{
    return false;
  }
}

// Checkc Empety Data
bool isEmptyData()
{
  if( countData() == 0 ){
    return true;
  }else{
    return false;
  }
}

// Push Data
void pushData( string nama, int umur ){

  if( isFullData() ){
    cout << "Stack Full!!" << endl;
  }else{
    if( isEmptyData() ){
      createData(nama, umur);
    }else{
      newNode = new dataMahasiswa();
      newNode->nama = nama;
      newNode->umur = umur;
      newNode->prev = tail;
      tail->next = newNode;
      newNode->next = NULL;
      tail = newNode;
    }
  }
  
}

// Pop Data
void popData()
{
  del = tail;
  tail = tail->prev;
  tail->next = NULL;
  delete del;
}

// Display Data
void displayData(){
  
  int i = countData();
  	
  if( isEmptyData() ){
    cout << "Data kosong" << endl;
  }else{
    cout << "\n\nList Data : " << endl;
    cur = tail;
    while( cur != NULL ){
      cout << "Nama Mahasiswa "<< i <<": " << cur->nama << " - Umur." << cur->umur << endl;
      cur = cur->prev;
      i--;
    }
  }
  
}

void peekData(int posisi){

  if( isEmptyData() ){
    cout << "Data kosong" << endl;
  }else{
    int nomor = 1;
    cur = tail;
    while( nomor < posisi ){
      cur = cur->prev;
      nomor++;
    }
    cout << "\n\nNama Mahasiswa Posisi ke-" << posisi << " : " << cur->nama << " - Umur." << cur->umur << endl<< endl;
  }

}

// Ubah Data Mahasiswa
void changeData(string nama, int umur, int posisi){

  if( isEmptyData() ){
    cout << "Data kosong" << endl;
  }else{
    int nomor = 1;
    cur = tail;
    while( nomor < posisi ){
      cur = cur->prev;
      nomor++;
    }
    cur->nama = nama;
    cur->umur = umur;
  }

}

//Destroy Data
void destroyData(){
  
  cur = head;
  while( cur != NULL ){
    del = cur;
    head = head->next;
    delete del;
    cur = cur->next;
  }
}

int main(){
	
	cout<<"Implementasi Stack"<<endl;
	cout<<"=================="<<endl;
	displayData();
	createData("Putra Dwi Wira", 21);
	displayData();
	pushData("Wira Gardha", 20);
	pushData("Yuniahans", 19);
	pushData("Dwi Gardha", 15);
	pushData("Putra Yuniahans", 19);
	displayData();
	
	popData();
	displayData();
	
	changeData("Ini diganti", 20, 2);
	displayData();
	
	peekData(2);
	destroyData();
	displayData();
	
}
