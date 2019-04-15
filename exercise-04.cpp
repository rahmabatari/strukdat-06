/*
Nama Program	: Exercise 04
Nama			: Rahma Batari
NPM				: 140810180051
Kelas			: A
*/

#include<iostream>
#include<string.h>

using namespace std;

struct contact{
	char nama[20];
	char nomor[12];
	contact* nextcontact;
};
struct index{
	char info[5];
	contact* FirstContact;
	index* next;
};
typedef index* pointerIndex;
typedef contact* pointerContact;
typedef pointerIndex list;

void createList(list& First){
	First=NULL;
}
void createElemtIndex(pointerIndex& pBaru){
	pBaru = new index;
	cout<<"Masukan index :"; cin>>pBaru->info;
	pBaru->next=NULL;
	pBaru->FirstContact=NULL;
	
}
void createElemtContact(pointerContact& pBaru){
	pBaru= new contact;
	cout<<"Masukan nama :"; cin>>pBaru->nama;
	cout<<"Masukan nomor:"; cin>>pBaru->nomor;
	pBaru->nextcontact=NULL;
}
void insertFirstIndex(list& First,pointerIndex pBaru){
	if(First==NULL){
		First=pBaru;
	}
	else{
		pBaru->next=First;
		First=pBaru;
	}
}
void traversalIndex(list First){
	pointerIndex pBantu;
	pBantu=First;
	while(pBantu!=NULL){
		cout<<"Index :"<<pBantu->info<<",";
		pBantu=pBantu->next;
	}
}
void linearSearch(list First,char key[5],int& status,pointerIndex& pCari){
	status=0;
	pCari=First;
	while(status==0 && pCari!=NULL){
		if(strcmp(pCari->info,key)==0){
			status=1;
		}
		else{
			pCari=pCari->next;
		}
	}
}
void insertFirstContact(list& First,char key[5],pointerContact pBaru){
	pointerIndex pIn;
	int ketemu;
	cout<<"Masukan Index yang di cari: "; cin>>key;
	linearSearch(First,key,ketemu,pIn);
	if(ketemu){
		cout<<"Ditemukan dengan Index :"<<pIn->info<<endl;
		if(pIn->FirstContact==NULL){
			pIn->FirstContact=pBaru;
		}
		else{
			pBaru->nextcontact=pIn->FirstContact;
			pIn->FirstContact=pBaru;
		}
	}
	else{
		cout<<"Index  tidak di temukan"<<endl;
	}
}
void deleteFirstContact(list& First,char key[5],pointerContact& pHapus ){
	int ketemu;
	pointerIndex pIn;
	cout<<"Masukan Index yang di cari: "; cin>>key;
	linearSearch(First,key,ketemu,pIn);
		if(ketemu){
		cout<<"Ditemukan dengan Index :"<<pIn->info;
		if(pIn->FirstContact==NULL){
			cout<<"Tidak ada yang di hapus"<<endl;
		}
		else if(pIn->FirstContact->nextcontact==NULL){
			pHapus=pIn->FirstContact;
			pIn->FirstContact=NULL;
		}
		else{
			pHapus=pIn->FirstContact;
			pIn->FirstContact=pIn->FirstContact->nextcontact;
			pHapus->nextcontact=NULL;
			
		}
	}
	else{
		cout<<"Index tidak di temukan"<<endl;
	}
	
}
void traversalIndexContact(list First){
	pointerIndex pBantuIndex;
	pointerContact pBantuContact;
	cout<<"Traversal Divisi"<<endl;
	pBantuIndex=First;
	while (pBantuIndex!=NULL){ 
	cout<<"Index ="<<pBantuIndex->info <<endl;
	pBantuContact=pBantuIndex->FirstContact;
	while (pBantuContact!=NULL) { 
	cout<<pBantuContact->nama<<" / "<<pBantuContact->nomor<<endl;
	pBantuContact=pBantuContact->nextcontact;
	}
	pBantuIndex=pBantuIndex->next;
	}
}
void updateContact(list First,char key[10],int& status,pointerIndex& pIndex){
	status=0;

	pointerContact pK,pb;
	pIndex=First;
	pK=pIndex->FirstContact;
	cout<<"Masukan nama :"; cin>>key;
	while(pIndex!=NULL){
		while(status== 0 && pK!=NULL){
			if(strcmp(pK->nama,key)==0){
				cout<<"Masukan Nama :"; cin>>pK->nama;
				cout<<"Masukan Nomor :"; cin>>pK->nomor;
			status=1;
			}
			else if(pK->nextcontact!=NULL){
					pK=pK->nextcontact;
			}
			else {
					status=1;
			}
			
		}
			pIndex=pIndex->next;
		}
	}
	

int main(){
	pointerIndex pI;
	pointerContact pK,phk;
	list q;
	char key[5],nama[10];
	int ni,nk,ketemu;
	createList(q);
	cout<<"Masukan Banyak index :"; cin>>ni;
	for(int i=0;i<ni;i++){
		createElemtIndex(pI);
		insertFirstIndex(q,pI);
	}
	cout<<"Masukan banyak kontak :"; cin>>nk;
	for(int i=0;i<nk;i++){
		createElemtContact(pK);
		insertFirstContact(q,key,pK);
	}
		traversalIndexContact(q);
		
	updateContact(q,nama,ketemu,pI);
	traversalIndexContact(q);
	
	
}

